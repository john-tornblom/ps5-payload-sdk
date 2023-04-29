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
 * Symbols provided by the ELF linker.
 **/
extern int (*__init_array_start[])(const payload_args_t *) __attribute__((weak));
extern int (*__init_array_end[])(const payload_args_t *) __attribute__((weak));
extern void (*__fini_array_start[])(void) __attribute__((weak));
extern void (*__fini_array_end[])(void) __attribute__((weak));


/**
 * sceKernelDlsym()
 **/
static void* sceKernelDlsym_addr = 0;
asm(".intel_syntax noprefix\n"
    ".global sceKernelDlsym\n"
    ".type sceKernelDlsym @function\n"
    "sceKernelDlsym:\n"
    "jmp qword ptr [rip + sceKernelDlsym_addr]\n");


/**
 * Entry point to the main program.
 **/
extern int main(int argc, char* argv[]);


/**
 * Entry-point used by the ELF loader.
 **/
void
_start(payload_args_t *args) {
  unsigned long count;

  sceKernelDlsym_addr = args->sceKernelDlsym;

  // run module constructors
  count = __init_array_end - __init_array_start;
  for(int i=0; i<count; i++) {
    __init_array_start[i](args);
  }

  // run payload
  *args->payloadout = main(0, 0);

  // run module destructors
  count = __fini_array_end - __fini_array_start;
  for(int i=0; i<count; i++) {
    __fini_array_start[i]();
  }
}

