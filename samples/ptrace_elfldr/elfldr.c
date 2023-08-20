/* Copyright (C) 2023 John Törnblom

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3, or (at your option) any
later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING. If not, see
<http://www.gnu.org/licenses/>.  */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/socketvar.h>
#include <sys/sysctl.h>
#include <sys/user.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#include <elf.h>
#include <ifaddrs.h>

#include <ps5/kernel.h>

#include "dynlib.h"
#include "ptrace.h"


/**
 * Allignment macros used to map virtual memory.
 **/
#define ROUND_PG(x) (((x) + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1))
#define TRUNC_PG(x) ((x) & ~(PAGE_SIZE - 1))


/**
 * Map ELF protection flags to mmap() protection flags
 **/
#define PFLAGS(x) ((((x) & PF_R) ? PROT_READ : 0) |		\
		   (((x) & PF_W) ? PROT_WRITE : 0) |		\
		   (((x) & PF_X) ? PROT_EXEC : 0))


/**
 * IPv6 constants used to obtain kernel RW primitves.
 **/
#ifndef IPV6_2292PKTOPTIONS
#define IPV6_2292PKTOPTIONS 25
#endif


/**
 * Data structure used to send UI notifications.
 **/
typedef struct notify_request {
  char useless1[45];
  char message[3075];
} notify_request_t;


/**
 * Send a UI notification request.
 **/
int sceKernelSendNotificationRequest(int, notify_request_t*, size_t, int);


/**
 * Get the kernel address of the given file descriptor.
 **/
static intptr_t
kernel_get_file(pid_t pid, int fd) {
  intptr_t fd_files;
  intptr_t fde_file;
  intptr_t file;
  intptr_t proc;
  intptr_t p_fd;

  if(!(proc=kernel_get_proc(pid))) {
    return 0;
  }

  if(kernel_copyout(proc + offsetof(struct proc, p_fd),
		    &p_fd, sizeof(p_fd))) {
    return 0;
  }

  if(kernel_copyout(p_fd, &fd_files, sizeof(fd_files))) {
    return 0;
  }

  if(kernel_copyout(fd_files + 8 + (0x30 * fd),
		    &fde_file, sizeof(fde_file))) {
    return 0;
  }

  if(kernel_copyout(fde_file, &file, sizeof(file))) {
    return 0;
  }

  return file;
}


/**
 * Increase the kernel refcount of an IPv6 UDP socket.
 **/
static int
kernel_inc_so_count(pid_t pid, int fd) {
  intptr_t file;
  int so_count;

  if(!(file=kernel_get_file(pid, fd))) {
    return -1;
  }

  if(kernel_copyout(file, &so_count, sizeof(so_count))) {
    return -1;
  }

  so_count++;
  so_count = 0x100;
  if(kernel_copyin(&so_count, file, sizeof(so_count))) {
    return -1;
  }
  return 0;
}


/**
 * 
 **/
static intptr_t
kernel_get_inp6_outputopts(pid_t pid, int fd) {
  intptr_t inp6_outputopts;
  intptr_t so_pcb;
  intptr_t file;

  if(!(file=kernel_get_file(pid, fd))) {
    return 0;
  }

  if(kernel_copyout(file + 0x18, &so_pcb, sizeof(so_pcb))) {
    return 0;
  }

  if(kernel_copyout(so_pcb + 0x120, &inp6_outputopts,
		    sizeof(inp6_outputopts))) {
    return 0;
  }

  return inp6_outputopts;
}


/**
 * Overlap IPv6 sockets to obtain kernel RW primtives just like the
 * original PS5 kernel exploit.
 **/
static int
kernel_overlap_sockets(pid_t pid, int master_sock, int victim_sock) {
  intptr_t master_inp6_outputopts;
  intptr_t victim_inp6_outputopts;
  intptr_t pktinfo;
  uint32_t tclass;

  if(kernel_inc_so_count(pid, master_sock)) {
    return -1;
  }

  if(!(master_inp6_outputopts=kernel_get_inp6_outputopts(pid, master_sock))) {
    return -1;
  }

  if(kernel_inc_so_count(pid, victim_sock)) {
    return -1;
  }

  if(!(victim_inp6_outputopts=kernel_get_inp6_outputopts(pid, victim_sock))) {
    return -1;
  }

  pktinfo = victim_inp6_outputopts + 0x10;
  if(kernel_copyin(&pktinfo, master_inp6_outputopts + 0x10,
		   sizeof(pktinfo))) {

    return -1;
  }

  tclass = 0x13370000;
  if(kernel_copyin(&tclass, master_inp6_outputopts + 0xc0, sizeof(tclass))) {
    return -1;
  }

  return 0;
}


/**
 * Get the name of a process with the given pid.
 **/
static int
get_procname(pid_t pid, char name[COMMLEN+1]) {
  int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, pid};
  struct kinfo_proc *ki;
  size_t ki_size = 1096;
  char buf[ki_size];

  if(sysctl(mib, 4, buf, &ki_size, NULL, 0) < 0) {
    return -1;
  }

  ki = (struct kinfo_proc*)buf;
  strncpy(name, ki->ki_comm, COMMLEN);
  return 0;
}



/**
 * Get the pid of a process with the given name.
 **/
static pid_t
kernel_getpid_byname(const char *name) {
  char other_name[MAXCOMLEN+1];
  intptr_t p_comm;
  intptr_t addr;
  intptr_t next;
  pid_t pid;

  if(kernel_copyout(KERNEL_ADDRESS_ALLPROC, &addr, sizeof(addr))) {
    return -1;
  }

  while(1) {
    if(kernel_copyout(addr + offsetof(struct proc, p_pid),
		      &pid, sizeof(pid))) {
      return -1;
    }

    if(get_procname(pid, other_name)) {
      return -1;
    }

    if(!strcmp(name, other_name)) {
      break;
    }

    if(kernel_copyout(addr, &next, sizeof(next))) {
      return -1;
    }

    if(!(addr=next)) {
      return -1;
    }
  }

  return pid;
}


/**
 * Generate a UI notification.
 **/
static void
elfldr_notify(const char *fmt, ...) {
  notify_request_t req;
  va_list args;

  bzero(&req, sizeof req);
  va_start(args, fmt);
  vsnprintf(req.message, sizeof req.message, fmt, args);
  va_end(args);

  sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
}


/**
 * Load an ELF into memory, and jump to its entry point.
 **/
static intptr_t
elfldr_load(pid_t pid, uint8_t *elf, size_t size) {
  Elf64_Ehdr *ehdr = (Elf64_Ehdr*)elf;
  Elf64_Phdr *phdr = (Elf64_Phdr*)(elf + ehdr->e_phoff);
  Elf64_Shdr *shdr = (Elf64_Shdr*)(elf + ehdr->e_shoff);

  intptr_t base_addr = -1;
  size_t base_size = 0;

  size_t min_vaddr = SIZE_MAX;
  size_t max_vaddr = 0;

  int error = 0;

  // Sanity check, we only support 64bit ELFs.
  if(ehdr->e_ident[EI_MAG0] != ELFMAG0 || ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
     ehdr->e_ident[EI_MAG2] != ELFMAG2 || ehdr->e_ident[EI_MAG3] != ELFMAG3 ||
     ehdr->e_ident[EI_CLASS] != ELFCLASS64 ||
     ehdr->e_ident[EI_VERSION] != EV_CURRENT) {
    return -1;
  }

  // Compute size of virtual memory region.
  for(int i=0; i<ehdr->e_phnum; i++) {
    if(phdr[i].p_type != PT_LOAD || phdr[i].p_memsz == 0) {
      continue;
    }

    if(phdr[i].p_vaddr < min_vaddr) {
      min_vaddr = phdr[i].p_vaddr;
    }

    if(max_vaddr < phdr[i].p_vaddr + phdr[i].p_memsz) {
      max_vaddr = phdr[i].p_vaddr + phdr[i].p_memsz;
    }
  }

  min_vaddr = TRUNC_PG(min_vaddr);
  max_vaddr = ROUND_PG(max_vaddr);
  base_size = max_vaddr - min_vaddr;

  int flags = MAP_PRIVATE | MAP_ANONYMOUS;
  if(ehdr->e_type == ET_DYN) {
    base_addr = 0;
  } else if(ehdr->e_type == ET_EXEC) {
    base_addr = min_vaddr;
    flags |= MAP_FIXED;
  } else {
    return -1;
  }

  // Reserve an address space of sufficient size.
  if((base_addr=pt_mmap(pid, base_addr, base_size, PROT_NONE,
			flags, -1, 0)) == -1) {
    pt_perror(pid, "mmap");
    return -1;
  }

  // Commit segments to reserved address space.
  for(int i=0; i<ehdr->e_phnum; i++) {
    size_t aligned_memsz = ROUND_PG(phdr[i].p_memsz);
    intptr_t addr = base_addr + phdr[i].p_vaddr;
    int alias_fd = -1;
    int shm_fd = -1;

    if(phdr[i].p_type != PT_LOAD || phdr[i].p_memsz == 0) {
      continue;
    }

    if(phdr[i].p_flags & PF_X) {
      if((shm_fd=pt_jitshm_create(pid, 0, aligned_memsz,
				  PROT_WRITE | PFLAGS(phdr[i].p_flags))) < 0) {
	pt_perror(pid, "jitshm_create");
	error = 1;
	break;
      }

      if((addr=pt_mmap(pid, addr, aligned_memsz, PFLAGS(phdr[i].p_flags),
		       MAP_FIXED | MAP_SHARED, shm_fd, 0)) == -1) {
	pt_perror(pid, "mmap");
	error = 1;
	break;
      }

      if((alias_fd=pt_jitshm_alias(pid, shm_fd, PROT_WRITE | PROT_READ)) < 0) {
	pt_perror(pid, "jitshm_alias");
	error = 1;
	break;
      }

      if((addr=pt_mmap(pid, 0, aligned_memsz, PROT_WRITE | PROT_READ, MAP_SHARED,
		       alias_fd, 0)) == -1) {
	pt_perror(pid, "mmap");
	error = 1;
	break;
      }

      if(pt_copyin(pid, elf + phdr[i].p_offset, addr, phdr[i].p_memsz)) {
	perror("pt_copyin");
	error = 1;
	break;
      }

      pt_munmap(pid, addr, aligned_memsz);
      pt_close(pid, alias_fd);
      pt_close(pid, shm_fd);
    } else {
      if((addr=pt_mmap(pid, addr, aligned_memsz, PROT_WRITE,
		       MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE,
		       -1, 0)) == -1) {
	pt_perror(pid, "mmap");
	error = 1;
	break;
      }
      if(pt_copyin(pid, elf + phdr[i].p_offset, addr, phdr[i].p_memsz)) {
	perror("pt_copyin");
	error = 1;
	break;
      }
    }
  }

  // Relocate positional independent symbols.
  for(int i=0; i<ehdr->e_shnum && !error; i++) {
    if(shdr[i].sh_type != SHT_RELA) {
      continue;
    }

    Elf64_Rela* rela = (Elf64_Rela*)(elf + shdr[i].sh_offset);
    for(int j=0; j<shdr[i].sh_size/sizeof(Elf64_Rela); j++) {
      if(ELF64_R_TYPE(rela[j].r_info) == R_X86_64_RELATIVE) {
	intptr_t value_addr = (base_addr + rela[j].r_offset);
	intptr_t value = base_addr + rela[j].r_addend;
	if(pt_copyin(pid, &value, value_addr, sizeof(Elf64_Addr))) {
	  perror("pt_copyin");
	  error = 1;
	  break;
	}
      }
    }
  }

  // Set protection bits on mapped segments.
  for(int i=0; i<ehdr->e_phnum && !error; i++) {
    size_t aligned_memsz = ROUND_PG(phdr[i].p_memsz);
    intptr_t addr = base_addr + phdr[i].p_vaddr;

    if(phdr[i].p_type != PT_LOAD || phdr[i].p_memsz == 0) {
      continue;
    }

    if(pt_mprotect(pid, addr, aligned_memsz, PFLAGS(phdr[i].p_flags))) {
      pt_perror(pid, "mprotect");
      error = 1;
      break;
    }
  }

  if(error) {
    return -1;
  } else {
    return base_addr + ehdr->e_entry;
  }
}


/**
 * Create payload args for a process with the given pid.
 **/
static intptr_t
elfldr_args(pid_t pid) {
  int victim_sock;
  int master_sock;
  intptr_t buf;
  int pipe0;
  int pipe1;

  if((buf=pt_mmap(pid, 0, PAGE_SIZE, PROT_READ | PROT_WRITE,
		  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) == -1) {
    pt_perror(pid, "mmap");
    return 0;
  }

  if((master_sock=pt_socket(pid, AF_INET6, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
    pt_perror(pid, "socket");
    return 0;
  }

  pt_setint(pid, buf+0x00, 20);
  pt_setint(pid, buf+0x04, IPPROTO_IPV6);
  pt_setint(pid, buf+0x08, IPV6_TCLASS);
  pt_setint(pid, buf+0x0c, 0);
  pt_setint(pid, buf+0x10, 0);
  pt_setint(pid, buf+0x14, 0);   
  if(pt_setsockopt(pid, master_sock, IPPROTO_IPV6, IPV6_2292PKTOPTIONS, buf, 24)) {
    pt_perror(pid, "setsockopt");
    return 0;
  }
  
  if((victim_sock=pt_socket(pid, AF_INET6, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
    pt_perror(pid, "socket");
    return 0;
  }

  pt_setint(pid, buf+0x00, 0);
  pt_setint(pid, buf+0x04, 0);
  pt_setint(pid, buf+0x08, 0);
  pt_setint(pid, buf+0x0c, 0);
  pt_setint(pid, buf+0x10, 0);
  if(pt_setsockopt(pid, victim_sock, IPPROTO_IPV6, IPV6_PKTINFO, buf, 20)) {
    pt_perror(pid, "setsockopt");
    return 0;
  }

  if(kernel_overlap_sockets(pid, master_sock, victim_sock)) {
    perror("overlap");
    return 0;
  }

  if(pt_pipe(pid, buf)) {
    pt_perror(pid, "pipe");
    return 0;
  }
  pipe0 = pt_getint(pid, buf);
  pipe1 = pt_getint(pid, buf+4);

  intptr_t args       = buf;
  intptr_t dlsym      = dynlib_resolve_sceKernelDlsym(pid);
  intptr_t rwpipe     = buf + 0x100;
  intptr_t rwpair     = buf + 0x200;
  intptr_t kpipe_addr = kernel_get_file(pid, pipe0);
  intptr_t payloadout = buf + 0x300;

  pt_setlong(pid, args + 0x00, dlsym);
  pt_setlong(pid, args + 0x08, rwpipe);
  pt_setlong(pid, args + 0x10, rwpair);
  pt_setlong(pid, args + 0x18, kpipe_addr);
  pt_setlong(pid, args + 0x20, KERNEL_ADDRESS_DATA_BASE);
  pt_setlong(pid, args + 0x28, payloadout);
  pt_setint(pid, rwpipe + 0, pipe0);
  pt_setint(pid, rwpipe + 4, pipe1);
  pt_setint(pid, rwpair + 0, master_sock);
  pt_setint(pid, rwpair + 4, victim_sock);
  pt_setint(pid, payloadout, 0);
  
  return args;
}


int
elfldr_exec(const char* procname, uint8_t *elf, size_t size) {
  uint8_t caps[16];
  uint8_t buf[16];
  struct reg r;
  pid_t pid;

  if((pid=kernel_getpid_byname(procname)) < 0) {
    printf("%s is not running\n", procname);
    return -1;
  }

  if(kernel_get_ucred_caps(pid, caps)) {
    perror("kernel_get_ucred_caps");
    return -1;
  }

  memset(buf, 0xff, sizeof(buf));
  if(kernel_set_ucred_caps(pid, buf)) {
    perror("kernel_set_ucred_caps");
    return -1;
  }
  
  if(pt_attach(pid)) {
    perror("pt_attach");
    return -1;
  }

  if(pt_getregs(pid, &r)) {
    perror("pt_getregs");
    pt_detach(pid);
    return -1;
  }

  if(!(r.r_rdi=elfldr_args(pid))) {
    pt_detach(pid);
    return -1;
  }

  if(!(r.r_rip=elfldr_load(pid, elf, size))) {
    pt_detach(pid);
    return -1;
  }

  kernel_set_ucred_caps(pid, caps);

  if(pt_setregs(pid, &r)) {
    perror("pt_setregs");
    pt_detach(pid);
    return -1;
  }

  if(pt_detach(pid)) {
    perror("pt_detach");
    return -1;
  }

  return 0;
}


/**
 * Read an ELF file from socket.
 **/
static size_t
elfldr_read(int connfd, uint8_t **data) {
  uint8_t buf[0x4000];
  off_t offset = 0;
  ssize_t len;

  *data = 0;
  while((len=read(connfd, buf, sizeof(buf)))) {
    *data = realloc(*data, offset + len);
    if(*data == NULL) {
      return -1;
    }

    memcpy(*data + offset, buf, len);
    offset += len;
  }
  return offset;
}


int
elfldr_serve(const char* procname, uint16_t port) {
  struct sockaddr_in server_addr;
  struct sockaddr_in client_addr;
  char ip[INET_ADDRSTRLEN];
  struct ifaddrs *ifaddr;
  socklen_t addr_len;
  uint8_t *elf;
  size_t size;
  int connfd;
  int srvfd;

  if(getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    return -1;
  }

  // Enumerate all AF_INET IPs
  for(struct ifaddrs *ifa=ifaddr; ifa!=NULL; ifa=ifa->ifa_next) {
    if(ifa->ifa_addr == NULL) {
      continue;
    }

    if(ifa->ifa_addr->sa_family != AF_INET) {
      continue;
    }

    struct sockaddr_in *in = (struct sockaddr_in*)ifa->ifa_addr;
    inet_ntop(AF_INET, &(in->sin_addr), ip, sizeof(ip));
    elfldr_notify("Serving ELF loader on %s:%d (%s)", ip, port, ifa->ifa_name);
  }

  freeifaddrs(ifaddr);

  if((srvfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return -1;
  }

  if(setsockopt(srvfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0) {
    perror("setsockopt");
    return -1;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(port);

  if(bind(srvfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
    perror("bind");
    return -1;
  }

  if(listen(srvfd, 5) != 0) {
    perror("listen");
    return -1;
  }

  addr_len = sizeof(client_addr);
  while(1) {
    if((connfd=accept(srvfd, (struct sockaddr*)&client_addr, &addr_len)) < 0) {
      perror("accept");
      continue;
    }

    if((size=elfldr_read(connfd, &elf))) {
      elfldr_exec(procname, elf, size);
    }
    close(connfd);
  }
  close(srvfd);

  return 0;
}
