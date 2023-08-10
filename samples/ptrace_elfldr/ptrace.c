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
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/syscall.h>

#include "ptrace.h"
#include "dynlib.h"


int
pt_attach(pid_t pid) {
  return syscall(SYS_ptrace, PT_ATTACH, pid, 0, 0);
}


int
pt_detach(pid_t pid) {
  return syscall(SYS_ptrace, PT_DETACH, pid, 0, 0);
}


int
pt_getregs(pid_t pid, struct reg *r) {
  return syscall(SYS_ptrace, PT_GETREGS, pid, (caddr_t)r, 0);
}


int
pt_setregs(pid_t pid, const struct reg *r) {
  return syscall(SYS_ptrace, PT_SETREGS, pid, (caddr_t)r, 0);
}


int
pt_copyin(pid_t pid, void* buf, intptr_t addr, size_t len) {
  size_t rem = len % sizeof(int);
  int val;

  for(size_t i=0; i<len-rem; i+=sizeof(int)) {
    memcpy(&val, buf, sizeof(val));
    if(syscall(SYS_ptrace, PT_WRITE_D, pid, (caddr_t)addr, val)) {
      return -1;
    }
    buf += sizeof(int);
    addr += sizeof(int);
  }

  if(rem) {
    val = syscall(SYS_ptrace, PT_READ_D, pid, (caddr_t)addr, NULL);
    memcpy(&val, buf, rem);
    if(syscall(SYS_ptrace, PT_WRITE_D, pid, (caddr_t)addr, val)) {
      return -1;
    }
  }
  return 0;
}


void
pt_copyout(pid_t pid, intptr_t addr, void* buf, size_t len) {
  size_t rem = len % sizeof(int);
  int val;

  for(int i=0; i<len-rem; i+=sizeof(int)) {
    val = syscall(SYS_ptrace, PT_READ_D, pid, (caddr_t)addr, NULL);
    memcpy(buf, &val, sizeof(val));
    buf += sizeof(int);
    addr += sizeof(int);
  }

  if(rem) {
    val = syscall(SYS_ptrace, PT_READ_D, pid, (caddr_t)addr, NULL);
    memcpy(buf, &val, rem);
  }
}


static int
pt_step(int pid) {
  int status;

  if(syscall(SYS_ptrace, PT_STEP, pid, (caddr_t)1, 0)) {
    return -1;
  }

  waitpid(pid, &status, 0);

  return status;
}


uint64_t
pt_call(pid_t pid, intptr_t addr, ...) {
  struct reg jmp_reg;
  struct reg bak_reg;
  va_list ap;

  if(pt_getregs(pid, &bak_reg)) {
    return -1;
  }

  memcpy(&jmp_reg, &bak_reg, sizeof(jmp_reg));
  jmp_reg.r_rip = addr;

  va_start(ap, addr);
  jmp_reg.r_rdi = va_arg(ap, uint64_t);
  jmp_reg.r_rsi = va_arg(ap, uint64_t);
  jmp_reg.r_rdx = va_arg(ap, uint64_t);
  jmp_reg.r_rcx = va_arg(ap, uint64_t);
  jmp_reg.r_r8  = va_arg(ap, uint64_t);
  jmp_reg.r_r9  = va_arg(ap, uint64_t);
  va_end(ap);

  if(pt_setregs(pid, &jmp_reg)) {
    return -1;
  }

  // single step until the function returns
  while(jmp_reg.r_rsp <= bak_reg.r_rsp) {
    pt_step(pid);
    if(pt_getregs(pid, &jmp_reg)) {
      return -1;
    }
  }

  // restore registers
  if(pt_setregs(pid, &bak_reg)) {
    return -1;
  }

  return jmp_reg.r_rax;
}


uint64_t
pt_syscall(pid_t pid, int sysno, ...) {
  intptr_t addr = dynlib_resolve(pid, 0x2001, "HoLVWNanBBc") + 0xa;
  struct reg jmp_reg;
  struct reg bak_reg;
  va_list ap;

  if(pt_getregs(pid, &bak_reg)) {
    return -1;
  }

  memcpy(&jmp_reg, &bak_reg, sizeof(jmp_reg));
  jmp_reg.r_rip = addr;
  jmp_reg.r_rax = sysno;

  va_start(ap, sysno);
  jmp_reg.r_rdi = va_arg(ap, uint64_t);
  jmp_reg.r_rsi = va_arg(ap, uint64_t);
  jmp_reg.r_rdx = va_arg(ap, uint64_t);
  jmp_reg.r_r10 = va_arg(ap, uint64_t);
  jmp_reg.r_r8  = va_arg(ap, uint64_t);
  jmp_reg.r_r9  = va_arg(ap, uint64_t);
  va_end(ap);

  if(pt_setregs(pid, &jmp_reg)) {
    return -1;
  }

  // single step until the function returns
  while(jmp_reg.r_rsp <= bak_reg.r_rsp) {
    pt_step(pid);
    if(pt_getregs(pid, &jmp_reg)) {
      return -1;
    }
  }

  // restore registers
  if(pt_setregs(pid, &bak_reg)) {
    return -1;
  }

  return jmp_reg.r_rax;
}


int
pt_jitshm_create(pid_t pid, intptr_t name, size_t size, int flags) {
  return (int)pt_syscall(pid, 0x215, name, size, flags);
}


int
pt_jitshm_alias(pid_t pid, int fd, int flags) {
  return (int)pt_syscall(pid, 0x216, fd, flags);
}


intptr_t
pt_mmap(pid_t pid, intptr_t addr, size_t len, int prot, int flags,
	int fd, off_t off) {
  return pt_syscall(pid, SYS_mmap, addr, len, prot, flags, fd, off);
}


int
pt_munmap(pid_t pid, intptr_t addr, size_t len) {
  return pt_syscall(pid, SYS_munmap, addr, len);
}


int
pt_mprotect(pid_t pid, intptr_t addr, size_t len, int prot) {
  return pt_syscall(pid, SYS_mprotect, addr, len, prot);
}


int
pt_close(pid_t pid, int fd) {
  return (int)pt_syscall(pid, SYS_close, fd);
}


void
pt_perror(pid_t pid, const char *s) {
  intptr_t faddr = dynlib_resolve(pid, 0x2001, "9BcDykPmo1I"); //__error
  intptr_t addr;
  int err = 0;

  addr = pt_call(pid, faddr);
  pt_copyout(pid, addr, &err, sizeof(err));
  printf("%s: %s\n", s, strerror(err));
}
