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

#include "kernel.h"
#include "mdbg.h"
#include "payload.h"
#include "syscall.h"


#define ELF64_R_SYM(info) ((info) >> 32)

#define DT_NULL    0
#define DT_NEEDED  1
#define DT_STRTAB  5
#define DT_SYMTAB  6
#define DT_RELA    7
#define DT_RELASZ  8

#define R_X86_64_GLOB_DAT 6
#define R_X86_64_JMP_SLOT 7
#define R_X86_64_RELATIVE 8


typedef struct {
  long d_tag;
  union {
    unsigned long d_val;
    unsigned long d_ptr;
  } d_un;
} Elf64_Dyn;


typedef struct {
  unsigned int   st_name;
  unsigned char  st_info;
  unsigned char  st_other;
  unsigned short st_shndx;
  unsigned long  st_value;
  unsigned long  st_size;
} Elf64_Sym;


typedef struct {
  unsigned long r_offset;
  unsigned long r_info;
  long          r_addend;
} Elf64_Rela;


typedef struct rtld_lib {
  int              handle;
  struct rtld_lib* next;
} rtld_lib_t;


/**
 * dependencies provided by the ELF linker.
 **/
extern unsigned char __text_start[] __attribute__((weak));
extern unsigned char __text_end[] __attribute__((weak));

extern Elf64_Dyn _DYNAMIC[];


/**
 * global private variables.
 **/
static rtld_lib_t* libhead = 0;
static Elf64_Sym* symtab = 0;
static char* strtab = 0;
static unsigned long base_addr = 0;


/**
 * external dependencies.
 **/
static void* (*malloc)(unsigned long) = 0;
static void  (*free)(void*) = 0;
static char* (*strcat)(char*, const char*);
static int   (*strcmp)(const char*, const char*) = 0;
static int   (*strlen)(const char*) = 0;
static int   (*printf)(const char*, ...) = 0;
static int   (*sprintf)(char*, const char*, ...) = 0;
static int   (*sceKernelLoadStartModule)(const char*, unsigned long, const void*,
					 unsigned int, void*, int*);
static int   (*sceKernelStopUnloadModule)(int, unsigned long, const void*, unsigned int,
					  const void*, void*);

static const char*
LD_LIBRARY_PATH[] = {
  "/system/priv_ex/lib",
  "/system/common_ex/lib",
  "/system/priv/lib",
  "/system/common/lib"
};


/**
 *
 **/
static rtld_lib_t*
rtld_open(const char* basename) {
  rtld_lib_t *lib = 0;
  char filename[255];
  int handle = 0;

  if(!strcmp(basename, "libkernel.so") ||
     !strcmp(basename, "libkernel_web.so") ||
     !strcmp(basename, "libkernel_sys.so")) {
    lib           = malloc(sizeof(rtld_lib_t));
    lib->handle   = 0x2001;
    lib->next     = 0;
    return lib;
  }

  if(!strcmp(basename, "libSceLibcInternal.so")) {
    lib           = malloc(sizeof(rtld_lib_t));
    lib->handle   = 0x2;
    lib->next     = 0;
    return lib;
  }

  for(int i=0; i<sizeof(LD_LIBRARY_PATH)/sizeof(LD_LIBRARY_PATH[0]); i++) {
    sprintf(filename, "%s/%s", LD_LIBRARY_PATH[i], basename);
    filename[strlen(filename)-2] = 0;
    strcat(filename, "sprx");
    if(syscall(SYS_access, filename, 0) < 0) {
      continue;
    }

   if((handle=sceKernelLoadStartModule(filename, 0, 0, 0, 0, 0)) > 0) {
      break;
    }
  }

  if(handle <= 0) {
    return 0;
  }

  lib         = malloc(sizeof(rtld_lib_t));
  lib->handle = handle;
  lib->next   = 0;
  
  return lib;
}


/**
 *
 **/
static unsigned long
rtld_sym(rtld_lib_t* lib, const char* name) {
  unsigned long addr = 0;

  syscall(SYS_sprx_dlsym, lib->handle, name, &addr);

  return addr;
}


static int
rtld_close(rtld_lib_t* lib) {
  int handle = lib->handle;

  free(lib);

  return sceKernelStopUnloadModule(handle, 0, 0, 0, 0, 0);
}


static int
dt_needed(const char* basename) {
  rtld_lib_t* lib;

  if((lib=rtld_open(basename))) {
    lib->next = libhead;
    libhead = lib;
    return 0;
  }

  printf("Unable to find %s\n", basename);

  return -1;
}


static int
r_glob_dat(Elf64_Rela* rela) {
  Elf64_Sym* sym = symtab + ELF64_R_SYM(rela->r_info);
  unsigned long loc = base_addr + rela->r_offset;
  const char* name = strtab + sym->st_name;
  int pid = syscall(SYS_getpid);
  unsigned long val = 0;

  for(rtld_lib_t *lib=libhead; lib!=0; lib=lib->next) {
    if((val=rtld_sym(lib, name))) {
      return mdbg_copyin(pid, &val, loc, sizeof(val));
    }
  }

  printf("Unable to resolve %s\n", name);

  return -1;
}


static int
r_jmp_slot(Elf64_Rela* rela) {
  Elf64_Sym* sym = symtab + ELF64_R_SYM(rela->r_info);
  unsigned long loc = base_addr + rela->r_offset;
  const char* name = strtab + sym->st_name;
  int pid = syscall(SYS_getpid);
  unsigned long val = 0;

  for(rtld_lib_t *lib=libhead; lib!=0; lib=lib->next) {
    if((val=rtld_sym(lib, name))) {
      return mdbg_copyin(pid, &val, loc, sizeof(val));
    }
  }

  printf("Unable to resolve %s\n", name);

  return -1;
}



static int
rtld_load(void) {
  Elf64_Rela* rela = 0;
  long relasz = 0;

  // find lookup tables
  for(int i=0; _DYNAMIC[i].d_tag!=DT_NULL; i++) {
    switch(_DYNAMIC[i].d_tag) {
    case DT_SYMTAB:
      symtab = (Elf64_Sym*)(__text_start + _DYNAMIC[i].d_un.d_ptr);
      break;

    case DT_STRTAB:
      strtab = (char*)(__text_start + _DYNAMIC[i].d_un.d_ptr);
      break;

    case DT_RELA:
      rela = (Elf64_Rela*)(__text_start + _DYNAMIC[i].d_un.d_ptr);
      break;

    case DT_RELASZ:
      relasz = _DYNAMIC[i].d_un.d_val;
      break;
    }
  }

  // load needed libraries
  for(int i=0; _DYNAMIC[i].d_tag!=DT_NULL; i++) {
    switch(_DYNAMIC[i].d_tag) {
    case DT_NEEDED:
      if(dt_needed(strtab + _DYNAMIC[i].d_un.d_val)) {
	return -1;
      }
      break;
    }
  }

  // Apply relocations.
  for(int i=0; i<relasz/sizeof(Elf64_Rela); i++) {
    switch(rela[i].r_info & 0xffffffffl) {
    case R_X86_64_JMP_SLOT:
      if(r_jmp_slot(&rela[i])) {
	return -1;
      }
      break;

    case R_X86_64_GLOB_DAT:
      if(r_glob_dat(&rela[i])) {
	return -1;
      }
      break;
    }
  }

  return 0;
}


__attribute__((constructor(104))) static void
rtld_constructor(const payload_args_t *args) {
  int pid = syscall(SYS_getpid);
  unsigned long rootdir = 0;
  int error = 0;

  if(!args) {
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

  if((error=args->sceKernelDlsym(0x2, "strcat", &strcat))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2, "strcmp", &strcmp))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2, "strlen", &strlen))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2, "printf", &printf))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2, "sprintf", &sprintf))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "sceKernelLoadStartModule",
				 &sceKernelLoadStartModule))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "sceKernelStopUnloadModule",
				 &sceKernelStopUnloadModule))) {
    *args->payloadout = error;
    return;
  }

  base_addr = (long)__text_start;
  rootdir = kernel_get_proc_rootdir(pid);
  kernel_set_proc_rootdir(pid, kernel_get_root_vnode());
  *args->payloadout = rtld_load();
  kernel_set_proc_rootdir(pid, rootdir);
}


__attribute__((destructor(104))) static void
rtld_destructor(const payload_args_t *args) {
  while(libhead) {
    rtld_lib_t *next = libhead->next;
    if(rtld_close(libhead)) {
      *args->payloadout = -1;
    }
    libhead = next;
  }
}
