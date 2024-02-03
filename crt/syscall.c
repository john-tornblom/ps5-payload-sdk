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

#include "payload.h"


/**
 * The PS5 does not allow syscalls from .text sections that are allocated in
 * shared memory. Instead, we simply assign the approriate registers, and
 * jump directly to a syscall instruction in libkernel (which is not in shared
 * memory).
 **/
static __attribute__ ((used)) long ptr_syscall = 0;
asm(".intel_syntax noprefix\n"
    ".global syscall\n"
    ".type syscall @function\n"
    "syscall:\n"
    "  mov rax, rdi\n"                      // sysno
    "  mov rdi, rsi\n"                      // arg1
    "  mov rsi, rdx\n"                      // arg2
    "  mov rdx, rcx\n"                      // arg3
    "  mov r10, r8\n"                       // arg4
    "  mov r8,  r9\n"                       // arg5
    "  mov r9,  qword ptr [rsp + 8]\n"      // arg6
    "  jmp qword ptr [rip + ptr_syscall]\n" // syscall
    "  ret\n"
    );


__attribute__((constructor(101))) static void
syscall_constructor(payload_args_t *args) {
  if(args->sceKernelDlsym(0x1, "getpid", &ptr_syscall) &&
     args->sceKernelDlsym(0x2001, "getpid", &ptr_syscall)) {
    return;
  }

  // jump directly to the syscall instruction
  // in getpid (provided by libkernel)
  ptr_syscall += 0xa;
}
