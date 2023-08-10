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

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <elf.h>

#include <ps5/kernel.h>

#include "dynlib.h"


/**
 *
 **/
typedef struct dynlib_dynsec {
  struct {
    intptr_t le_next;
    intptr_t le_prev;
  } list_entry;

  intptr_t sysvec;
  uint32_t refcount;
  size_t   size;

  intptr_t symtab;
  size_t   symtabsize;

  intptr_t strtab;
  size_t   strtabsize;

  intptr_t pltrela;
  size_t   pltrelasize;

  intptr_t rela;
  size_t   relasize;

  intptr_t hash;
  size_t   hashsize;

  intptr_t dynamic;
  size_t   dynamicsize;

  intptr_t sce_comment;
  size_t   sce_commentsize;

  intptr_t sce_dynlib;
  size_t   sce_dynlibsize;

  intptr_t unknown1;     // execpath?
  size_t   unknown1size;

  intptr_t buckets;
  size_t   bucketssize;
  uint32_t nbuckets;

  intptr_t chains;
  uint64_t chainssize;
  uint32_t nchains;

  uint64_t unknown2[7];
} dynlib_dynsec_t;


/**
 *
 **/
typedef struct dynlib_obj {
  intptr_t next;
  intptr_t path;
  uint64_t unknown0[2];
  uint32_t refcount;
  uint64_t handle;

  uint64_t mapbase;
  size_t   mapsize;
  size_t   textsize;

  intptr_t database;
  size_t   datasize;

  intptr_t unknown1;
  size_t   unknown1size;

  uint64_t vaddrbase;
  uint64_t relocbase;
  uint64_t entry;

  uint32_t tlsindex;
  intptr_t tlsinit;
  size_t   tlsinitsize;
  size_t   tlssize;
  off_t    tlsoffset;
  uint64_t tlsalign;

  intptr_t pltgot;

  uint64_t unknown2[6];

  intptr_t init;
  intptr_t fini;

  intptr_t eh_frame_hdr;
  size_t   eh_frame_hdr_size;

  intptr_t eh_frame;
  size_t   eh_frame_size;

  int status;
  int flags;

  uint64_t unknown5[5];
  intptr_t dynsec;
  uint64_t unknown6[6]; //fingerprint?
} dynlib_obj_t;


intptr_t
dynlib_resolve(pid_t pid, uint32_t handle, const char *nid) {
  intptr_t kproc = kernel_get_proc(pid);
  dynlib_dynsec_t dynsec;
  dynlib_obj_t obj;
  Elf64_Sym *symtab;
  intptr_t kaddr;
  intptr_t vaddr;
  char *strtab;

  if(!(kproc=kernel_get_proc(pid))) {
    return 0;
  }

  if(kernel_copyout(kproc + 0x3e8, &kaddr, sizeof(kaddr)) < 0) {
    return 0;
  }

  do {
    if(kernel_copyout(kaddr, &kaddr, sizeof(kaddr)) < 0) {
      return 0;
    }

    if(!kaddr) {
      return 0;
    }

    if(kernel_copyout(kaddr + offsetof(dynlib_obj_t, handle),
		      &obj.handle, sizeof(obj.handle)) < 0) {
      return 0;
    }
  } while(obj.handle != handle);

  if(kernel_copyout(kaddr, &obj, sizeof(obj)) < 0) {
    return 0;
  }

  if(kernel_copyout(obj.dynsec, &dynsec, sizeof(dynsec)) < 0) {
    return 0;
  }

  if(!(symtab=malloc(dynsec.symtabsize))) {
    return 0;
  }

  if(kernel_copyout(dynsec.symtab, symtab, dynsec.symtabsize) < 0) {
    free(symtab);
    return 0;
  }

  if(!(strtab=malloc(dynsec.strtabsize))) {
    free(symtab);
    return 0;
  }

  if(kernel_copyout(dynsec.strtab, strtab, dynsec.strtabsize) < 0) {
    free(symtab);
    free(strtab);
    return 0;
  }

  vaddr = 0;
  for(size_t i=0; i<dynsec.symtabsize / sizeof(Elf64_Sym); i++) {
    if(!strncmp(nid, strtab + symtab[i].st_name, 11)) {
      vaddr = obj.mapbase + symtab[i].st_value;
      break;
    }
  }

  free(symtab);
  free(strtab);

  return vaddr;
}


intptr_t
dynlib_resolve_sceKernelDlsym(pid_t pid) {
  return dynlib_resolve(pid, 0x2001, "LwG8g3niqwA");
}
