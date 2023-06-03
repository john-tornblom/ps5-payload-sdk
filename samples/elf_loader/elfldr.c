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

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/mman.h>
#include <sys/user.h>
#include <elf.h>


/**
 * Allignment macros used to map virtual memory.
 **/
#define ROUND_PG(x) (((x) + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1))
#define TRUNC_PG(x) ((x) & ~(PAGE_SIZE - 1))


/**
 * Map ELF protection flags to mmap() protection flags
 **/
#define PFLAGS(x) ((((x) & PF_R) ? PROT_READ : 0) |		\
		   (((x) & PF_W) ? PROT_WRITE : 0) |		\
		   (((x) & PF_X) ? PROT_EXEC : 0))


/**
 * External dependencies to libkernel.
 **/
int sceKernelJitCreateSharedMemory(const char*, size_t, int, int*);
int sceKernelJitCreateAliasOfSharedMemory(int, int, int*);
int sceKernelDlsym(int, const char*, void*);


/**
 * Load an ELF into memory, and jump to its entry point.
 **/
int
elfldr_exec(uint8_t *elf, size_t size) {
  Elf64_Ehdr *ehdr = (Elf64_Ehdr*)elf;
  Elf64_Phdr *phdr = (Elf64_Phdr*)(elf + ehdr->e_phoff);
  Elf64_Shdr *shdr = (Elf64_Shdr*)(elf + ehdr->e_shoff);

  void *base_addr = MAP_FAILED;
  size_t base_size = 0;

  size_t min_vaddr = SIZE_MAX;
  size_t max_vaddr = 0;

  int error = 0;

  // Sanity check, we only support 64bit ELFs.
  if(ehdr->e_ident[EI_MAG0] != ELFMAG0 || ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
     ehdr->e_ident[EI_MAG2] != ELFMAG2 || ehdr->e_ident[EI_MAG3] != ELFMAG3 ||
     ehdr->e_ident[EI_CLASS] != ELFCLASS64 ||
     ehdr->e_ident[EI_VERSION] != EV_CURRENT) {
    return -1;
  }

  // Compute size of virtual memory region.
  for(int i=0; i<ehdr->e_phnum; i++) {
    if(phdr[i].p_type != PT_LOAD || phdr[i].p_memsz == 0) {
      continue;
    }

    if(phdr[i].p_vaddr < min_vaddr) {
      min_vaddr = phdr[i].p_vaddr;
    }

    if(max_vaddr < phdr[i].p_vaddr + phdr[i].p_memsz) {
      max_vaddr = phdr[i].p_vaddr + phdr[i].p_memsz;
    }
  }

  min_vaddr = TRUNC_PG(min_vaddr);
  max_vaddr = ROUND_PG(max_vaddr);
  base_size = max_vaddr - min_vaddr;

  int flags = MAP_PRIVATE | MAP_ANONYMOUS;
  if(ehdr->e_type == ET_DYN) {
    base_addr = 0;
  } else if(ehdr->e_type == ET_EXEC) {
    base_addr = (void*)min_vaddr;
    flags |= MAP_FIXED;
  } else {
    return -1;
  }

  // Reserve an address space of sufficient size.
  if((base_addr=mmap(base_addr, base_size, PROT_NONE,
		     flags, -1, 0)) == MAP_FAILED) {
    perror("mmap");
    return -1;
  }

  // Commit segments to reserved address space.
  for(int i=0; i<ehdr->e_phnum; i++) {
    size_t aligned_memsz = ROUND_PG(phdr[i].p_memsz);
    void *addr = base_addr + phdr[i].p_vaddr;

    if(phdr[i].p_type != PT_LOAD || phdr[i].p_memsz == 0) {
      continue;
    }

    if(phdr[i].p_flags & PF_X) {
      int alias_fd = -1;
      int shm_fd = -1;

      // Create shm with executable permissions.
      if(sceKernelJitCreateSharedMemory(0, aligned_memsz,
					PROT_WRITE | PFLAGS(phdr[i].p_flags),
					&shm_fd)) {
	perror("sceKernelJitCreateSharedMemory");
	error = 1;
	break;
      }

      // Map shm into an executable address space.
      if((addr=mmap(addr, aligned_memsz, PFLAGS(phdr[i].p_flags),
		    MAP_FIXED | MAP_SHARED, shm_fd, 0)) == MAP_FAILED) {
	perror("mmap");
	error = 1;
	break;
      }

      // Create an shm alias fd with write permissions.
      if(sceKernelJitCreateAliasOfSharedMemory(shm_fd, PROT_WRITE,
					       &alias_fd) != 0) {
	perror("sceKernelJitCreateAliasOfSharedMemory");
	error = 1;
	break;
      }

      // Map shm alias into a writable address space.
      if((addr=mmap(0, aligned_memsz, PROT_WRITE, MAP_SHARED,
		    alias_fd, 0)) == MAP_FAILED) {
	perror("mmap");
	error = 1;
	break;
      }

      // Copy segment data.
      memcpy(addr, elf + phdr[i].p_offset, phdr[i].p_memsz);

      // Cleanup resources.
      munmap(addr, aligned_memsz);
      close(alias_fd);
      close(shm_fd);

    } else {
      // Map segment into a writable address space.
      if((addr=mmap(addr, aligned_memsz, PROT_WRITE,
		    MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE,
		    -1, 0)) == MAP_FAILED) {
	perror("mmap");
	error = 1;
	break;
      }

      // Copy segment data.
      memcpy(addr, elf + phdr[i].p_offset, phdr[i].p_memsz);
    }
  }

  // Relocate positional independent symbols.
  for(int i=0; i<ehdr->e_shnum && !error; i++) {
    if(shdr[i].sh_type != SHT_RELA) {
      continue;
    }

    Elf64_Rela* rela = (Elf64_Rela*)(elf + shdr[i].sh_offset);

    for(int j=0; j<shdr[i].sh_size/sizeof(Elf64_Rela); j++) {
      if(ELF64_R_TYPE(rela[j].r_info) == R_X86_64_RELATIVE) {
	Elf64_Addr* value_addr = (base_addr + rela[j].r_offset);
	*value_addr = (Elf64_Addr)base_addr + rela[j].r_addend;
      }
    }
  }

  // Set protection bits on mapped segments.
  for(int i=0; i<ehdr->e_phnum && !error; i++) {
    size_t aligned_memsz = ROUND_PG(phdr[i].p_memsz);
    void *addr = base_addr + phdr[i].p_vaddr;

    if(phdr[i].p_type != PT_LOAD || phdr[i].p_memsz == 0) {
      continue;
    }

    if(mprotect(addr, aligned_memsz, PFLAGS(phdr[i].p_flags))) {
      perror("mprotect");
      error = 1;
      break;
    }
  }

  // Jump to entry point if ELF was loaded into memory correctly.
  if(!error) {
    void (*_start)(void*) = base_addr + ehdr->e_entry;
    _start(&sceKernelDlsym);
  }

  munmap(base_addr, base_size);

  return error;
}
