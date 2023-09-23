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
 * External dependencies.
 **/
static int (*sceKernelDlsym)(int, const char*, void*) = 0;
static int (*sceKernelStopUnloadModule)(int, unsigned long, const void*,
					unsigned int, const void*, void*) = 0;
static int (*sceKernelLoadStartModule)(const char*, unsigned long,
				       const void*, unsigned int,
				       void*, int*) = 0;
static const char* (*sceKernelGetFsSandboxRandomWord)(void) = 0;
static int (*snprintf)(char *, unsigned long, const char *, ...) = 0;
static int (*access)(const char*, int) = 0;
static int (*getpid)(void) = 0;


/**
 * See include_ps5/kernel.h
 **/
unsigned long kernel_dynlib_resolve(unsigned int pid, unsigned int handle,
				    const char *nid);


/**
 * Keep track of errors.
 **/
static int *sprx_error = 0;


/**
 * process id used to resolve symbols.
 **/
static unsigned int pid = -1;


/**
 *
 **/
__attribute__((constructor(103))) static void
sprx_constructor(const payload_args_t *args) {
  int error;

  sceKernelDlsym = args->sceKernelDlsym;
  sprx_error     = args->payloadout;

  if((error=sceKernelDlsym(0x2001, "sceKernelStopUnloadModule",
			   &sceKernelStopUnloadModule))) {
    *sprx_error = error;
    return;
  }
  if((error=sceKernelDlsym(0x2001, "sceKernelLoadStartModule",
			   &sceKernelLoadStartModule))) {
    *sprx_error = error;
    return;
  }
  if((error=sceKernelDlsym(0x2001, "sceKernelGetFsSandboxRandomWord",
			   &sceKernelGetFsSandboxRandomWord))) {
    *sprx_error = error;
    return;
  }
  if((error=sceKernelDlsym(0x2001, "getpid", &getpid))) {
    *sprx_error = error;
    return;
  }
  if((error=sceKernelDlsym(0x2001, "access", &access))) {
    *sprx_error = error;
    return;
  }
  if((error=sceKernelDlsym(0x2, "snprintf", &snprintf))) {
    *sprx_error = error;
    return;
  }

  pid = getpid();
}


/**
 * Resolve the address of symbol from a module.
 **/
int
sprx_dlsym(unsigned short handle, const char *nid, void **ptr) {
  unsigned long addr;
  int error = -1;

  if((addr=kernel_dynlib_resolve(pid, handle, nid))) {
    *ptr = (void*)addr;
    return 0;
  }

  *sprx_error = error;

  return error;
}


/**
 * Open a module with a given libname.
 **/
int
sprx_dlopen(const char* libname, unsigned short *handle) {
  const char *sandbox_path = sceKernelGetFsSandboxRandomWord();
  char path[0x100];

  if(sandbox_path) {
    snprintf(path, sizeof(path), "/%s/priv_ex/lib/%s.sprx", sandbox_path, libname);
    if(!access(path, 0) && (*handle=sceKernelLoadStartModule(path, 0, 0, 0, 0, 0)) > 0) {
      return 0;
    }

    snprintf(path, sizeof(path),"/%s/common_ex/lib/%s.sprx", sandbox_path, libname);
    if(!access(path, 0) && (*handle=sceKernelLoadStartModule(path, 0, 0, 0, 0, 0)) > 0) {
      return 0;
    }

    snprintf(path, sizeof(path), "/%s/priv/lib/%s.sprx", sandbox_path, libname);
    if(!access(path, 0) && (*handle=sceKernelLoadStartModule(path, 0, 0, 0, 0, 0)) > 0) {
      return 0;
    }
    snprintf(path, sizeof(path), "/%s/common/lib/%s.sprx", sandbox_path, libname);
    if(!access(path, 0) && (*handle=sceKernelLoadStartModule(path, 0, 0, 0, 0, 0)) > 0) {
      return 0;
    }
  }

  snprintf(path, sizeof(path),"/system_ex/priv_ex/lib/%s.sprx", libname);
  if(!access(path, 0) && (*handle=sceKernelLoadStartModule(path, 0, 0, 0, 0, 0)) > 0) {
    return 0;
  }

  snprintf(path, sizeof(path),"/system_ex/common_ex/lib/%s.sprx", libname);
  if(!access(path, 0) && (*handle=sceKernelLoadStartModule(path, 0, 0, 0, 0, 0)) > 0) {
    return 0;
  }

  snprintf(path, sizeof(path),"/system/priv/lib/%s.sprx", libname);
  if(!access(path, 0) && (*handle=sceKernelLoadStartModule(path, 0, 0, 0, 0, 0)) > 0) {
    return 0;
  }

  snprintf(path, sizeof(path),"/system/common/lib/%s.sprx", libname);
  if(!access(path, 0) && (*handle=sceKernelLoadStartModule(path, 0, 0, 0, 0, sprx_error)) > 0) {
    return 0;
  }

  return -1;
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

