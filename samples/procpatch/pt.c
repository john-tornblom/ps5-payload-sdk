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

#include <stdio.h>
#include <unistd.h>

#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/wait.h>

#include <ps5/kernel.h>

#include "pt.h"


static int
sys_ptrace(int request, pid_t pid, caddr_t addr, int data) {
  pid_t mypid = getpid();
  uint64_t authid;
  long ret;

  if(!(authid=kernel_get_ucred_authid(mypid))) {
    return -1;
  }

  if(kernel_set_ucred_authid(mypid, 0x4800000000010003l)) {
    return -1;
  }

  ret = syscall(SYS_ptrace, request, pid, addr, data);

  if(kernel_set_ucred_authid(mypid, authid)) {
    return -1;
  }

  return (int)ret;
}


int
pt_attach(pid_t pid) {
  if(sys_ptrace(PT_ATTACH, pid, NULL, 0) == -1) {
    perror("PT_ATTACH");
    return -1;
  }

  if(waitpid(pid, NULL, 0) == -1) {
    perror("waitpid");
    return -1;
  }

  return 0;
}


int
pt_detach(pid_t pid) {
  if(sys_ptrace(PT_DETACH, pid, NULL, 0) == -1) {
    perror("PT_DETACH");
    return -1;
  }

  return 0;
}


int
pt_vm_entry(pid_t pid, struct ptrace_vm_entry *ve) {
  if(sys_ptrace(PT_VM_ENTRY, pid, (caddr_t)ve, 0) == -1) {
    perror("PT_VM_ENTRY");
    return -1;
  }

  return 0;
}
