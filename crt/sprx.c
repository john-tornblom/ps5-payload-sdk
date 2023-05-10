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
 * External ependencies.
 **/
static int (*sceKernelDlsym)() = 0;
static int (*sceKernelStopUnloadModule)() = 0;
static int (*sceSysmoduleLoadModuleByNameInternal)() = 0;


/**
 * Keep track of errors.
 **/
static int *sprx_error = 0;


/**
 *
 **/
__attribute__((constructor(101))) static void
sprx_constructor(const payload_args_t *args) {
  int error;

  sceKernelDlsym = args->sceKernelDlsym;
  sprx_error     = args->payloadout;

  if((error=sceKernelDlsym(0x2001, "sceKernelStopUnloadModule",
			   &sceKernelStopUnloadModule))) {
    *sprx_error = error;
    return;
  }
  if((error=sceKernelDlsym(0x11, "sceSysmoduleLoadModuleByNameInternal",
			   &sceSysmoduleLoadModuleByNameInternal))) {
    *sprx_error = error;
    return;
  }
}


/**
 * Resolve the address of symbol from a module.
 **/
int
sprx_dlsym(unsigned short handle, const char *symname, void *addr) {
  int error;

  if((error=sceKernelDlsym(handle, symname, addr))) {
    *sprx_error = error;
  }

  return error;
}


/**
 * Open a module with a given libname.
 **/
int
sprx_dlopen(const char* libname, unsigned short *handle) {
  unsigned int ret = sceSysmoduleLoadModuleByNameInternal(libname, 0, 0, 0, 0);

  if(ret & 0xffff0000) {
    *sprx_error = ret;
    return ret;
  } else {
    *handle = ret & 0xffff;
    return 0;
  }
}


/**
 * Close a module with a give handle.
 **/
int
sprx_dlclose(unsigned short handle) {
  int error = 0;

  if((error=sceKernelStopUnloadModule(handle, 0, 0, 0, 0, 0))) {
    *sprx_error = error;
  }

  return error;
}

