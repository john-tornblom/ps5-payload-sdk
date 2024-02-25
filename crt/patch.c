/* Copyright (C) 2024 John Törnblom

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

#include "kernel.h"
#include "mdbg.h"
#include "payload.h"
#include "syscall.h"


static int (*sceKernelDlsym)(int, const char*, void*) = 0;


/**
 * Patch retail distributions of sceKernelSpawn() that ignore the dbg parameter.
 *
 * At offset 52, replace 0x00000000a845c748l with 0x90909090a8758948l, i.e.,
 *
 *            mov    QWORD PTR [rbp-0x58],0x0
 * becomes
 *            mov    QWORD PTR [rbp-0x58],rsi
 *            nop
 *            nop
 *            nop
 *            nop
 **/
static int
patch_sceKernelSpawn(void) {
  int pid = syscall(SYS_getpid);
  unsigned long loc;
  unsigned long val;

  if(sceKernelDlsym(0x1, "sceKernelSpawn", &loc) &&
     sceKernelDlsym(0x2001, "sceKernelSpawn", &loc)) {
    return -1;
  }

  loc += 52;
  if(mdbg_copyout(pid, loc, &val, sizeof(val))) {
    return -1;
  }

  // sanity checks
  if(val == 0x90909090a8758948l) {
    return 0;

  } else if(val != 0x00000000a845c748l) {
    return -1;
  }

  val = 0x90909090a8758948l;
  if(mdbg_copyin(pid, &val, loc, sizeof(val))) {
    return -1;
  }

  return 0;
}


static int
patch_kernel_ucred(void) {
  int pid = syscall(SYS_getpid);
  unsigned char caps[16];
  unsigned long attrs;

  if(kernel_get_ucred_caps(pid, caps)) {
    return -1;
  }
  if(!(attrs=kernel_get_ucred_attrs(pid))) {
    return -1;
  }

  caps[5]  = 0x1c; // ??
  caps[7]  = 0x40; // jail related?
  caps[15] |= 0x40; // jitshm
  attrs    |= 0x80; // ptrace

  if(kernel_set_ucred_caps(pid, caps)) {
    return -1;
  }
  if(kernel_set_ucred_attrs(pid, attrs)) {
    return -1;
  }

  return 0;
}


__attribute__((constructor(105))) static void
payload_constructor(payload_args_t *args) {
  sceKernelDlsym = args->sceKernelDlsym;
  patch_sceKernelSpawn();
  patch_kernel_ucred();
}

