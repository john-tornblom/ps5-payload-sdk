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
 *
 **/
static __attribute__ ((used)) void* sceKernelDlsym_addr = 0;
asm(".intel_syntax noprefix\n"
    ".global sceKernelDlsym\n"
    ".type sceKernelDlsym @function\n"
    "sceKernelDlsym:\n"
    "jmp qword ptr [rip + sceKernelDlsym_addr]\n");


/**
 * Symbols provided by the ELF linker.
 **/
extern int (*__init_array_start[])(const payload_args_t *) __attribute__((weak));
extern int (*__init_array_end[])(const payload_args_t *) __attribute__((weak));
extern void (*__fini_array_start[])(void) __attribute__((weak));
extern void (*__fini_array_end[])(void) __attribute__((weak));


/**
 * Entry point to the actual payload.
 **/
extern int main(int argc, char* argv[]);


/**
 * Entry-point used by the ELF loader.
 **/
long _start(payload_args_t *args) {
  unsigned long base_addr = 0x926100000l; //FIXME: this should be parameterized.
  unsigned long array_addr = 0;
  unsigned long count = 0;
  int error = 0;

  sceKernelDlsym_addr = args->sceKernelDlsym;

  // run module constructors
  array_addr = base_addr + (unsigned long)__init_array_start;
  count = __init_array_end - __init_array_start;
  for(int i=0; i<count; i++) {
    unsigned long *init_module_ptr = (unsigned long*)(array_addr + (i * sizeof(init_module_t*)));
    unsigned long init_module_addr = *init_module_ptr + base_addr;
    init_module_t init_module = (init_module_t)init_module_addr;
    if((error=init_module(args))) {
      break;
    }
  }

  // run payload
  if(!error) {
    *args->payloadout = main(0, 0);
  } else {
    *args->payloadout = error;
  }
  
  // run module destructors
  array_addr = base_addr + (unsigned long)__fini_array_start;
  count = __fini_array_end - __fini_array_start;
  for(int i=0; i<count; i++) {
    unsigned long *fini_module_ptr = (unsigned long*)(array_addr + (i * sizeof(fini_module_t*)));
    unsigned long fini_module_addr = *fini_module_ptr + base_addr;
    fini_module_t fini_module = (fini_module_t)fini_module_addr;
    fini_module();
  }
  
  return *args->payloadout;
}

