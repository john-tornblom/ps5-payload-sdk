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

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

#include <sys/sysctl.h>
#include <sys/user.h>
#include <sys/wait.h>

#include <ps5/kernel.h>

#include "elfldr.h"
#include "dynlib.h"
#include "ptrace.h"


/**
 * For testing purposes, include payload directly in the source.
 **/
#include "payload_elf.c"


/**
 *
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
 *
 **/
static pid_t
getpid_byname(const char *name) {
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


static int
runelf(const char *procname, uint8_t* elf, size_t len) {
  uint64_t authid;
  uint64_t attrs;
  uint64_t caps0;
  uint64_t caps1;
  intptr_t addr;
  struct reg r;
  int status;
  pid_t pid;

  if((pid=getpid_byname(procname)) < 0) {
    printf("Cannot find a process with the name '%s'\n", procname);
    return -1;
  }

  authid = kernel_get_ucred_authid(pid);
  caps0 = kernel_get_ucred_caps0(pid);
  caps1 = kernel_get_ucred_caps1(pid);
  attrs = kernel_get_ucred_attrs(pid);

  printf("Running elf in %s with pid %d\n", procname, pid);
  if(pt_attach(pid)) {
    perror("pt_attach");
    return -1;
  }

  if(waitpid(pid, &status, 0) < 0) {
    perror("waitpid");
    return -1;
  }

  if(pt_getregs(pid, &r)) {
    perror("pt_getregs");
    return -1;
  }

  kernel_set_ucred_authid(pid, 0x4800000000010003l);
  kernel_set_ucred_attrs(pid, 0x8000000000000000);
  kernel_set_ucred_caps0(pid, -1);
  kernel_set_ucred_caps1(pid, -1);

  if((addr=elfldr_load(pid, elf, len)) != -1) {
    r.r_rip = addr;
    r.r_rdi = dynlib_resolve_sceKernelDlsym(pid);
  }

  kernel_set_ucred_authid(pid, authid);
  kernel_set_ucred_caps0(pid, caps0);
  kernel_set_ucred_caps1(pid, caps1);
  kernel_set_ucred_attrs(pid, attrs);

  if(pt_setregs(pid, &r)) {
    perror("pt_setregs");
    return -1;
  }

  if(pt_detach(pid)) {
    perror("pt_detach");
    return -1;
  }

  return 0;
}


int
main() {
  pid_t pid = getpid();
  uint8_t qaflags[16];
  uint64_t authid = kernel_get_ucred_authid(pid);

  kernel_get_qaflags(qaflags);
  qaflags[1] |= 2;
  kernel_set_qaflags(qaflags);

  kernel_set_ucred_authid(pid, 0x4800000000010003l);
  runelf("SceRedisServer", payload_elf, payload_elf_len);
  kernel_set_ucred_authid(pid, authid);

  return 0;
}
