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

#pragma once

#include <stdint.h>
#include <sys/types.h>
#include <machine/reg.h>


/**
 * Attach to the process with the given pid.
 **/
int pt_attach(pid_t pid);


/**
 * Detach from the process with the given pid.
 **/
int pt_detach(pid_t pid);


/**
 * Set register values of the process with the given pid.
 **/
int pt_setregs(pid_t pid, const struct reg *r);


/**
 * Get register values of the process with the given pid.
 **/
int pt_getregs(pid_t pid, struct reg *r);


/**
 * Copy memory into the virtual address space of the process with
 * the given pid.
 **/
int pt_copyin(pid_t pid, void* buf, intptr_t addr, size_t len);


/**
 * Copy memory out from the virtual address space of the process with
 * the given pid.
 **/
void pt_copyout(pid_t pid, intptr_t addr, void* buf, size_t len);


/**
 * Invoke a a function in a process with the given pid.
 **/
uint64_t pt_call(pid_t pid, intptr_t addr, ...);


/**
 * Make a system call in the process with the given pid.
 **/
uint64_t pt_syscall(pid_t pid, int sysno, ...);


/**
 * Allocate shared memory address space for JIT in the process with the
 * given pid.
 **/
int pt_jitshm_create(pid_t pid, intptr_t name, size_t size, int flags);


/**
 * Create an alias address space for JIT in the process with the given pid.
 **/
int pt_jitshm_alias(pid_t pid, int fd, int flags);


/**
 * Create a new mapping in the virtual address space in the process
 * with the given pid.
 **/
intptr_t pt_mmap(pid_t pid, intptr_t addr, size_t len, int prot, int flags,
		 int fd, off_t off);


/**
 * Remove a mapping in the virtual address space in the process with the
 * given pid.
 **/
int pt_munmap(pid_t pid, intptr_t addr, size_t len);


/**
 * Set protection on a region of memory in the process with the given pid.
 **/
int pt_mprotect(pid_t pid, intptr_t addr, size_t len, int prot);


/**
 * print a system error message form the process with the given pid.
 **/
void pt_perror(pid_t pid, const char *s);


/**
 * close a file descriptor in the process with the given pid.
 **/
int pt_close(pid_t pid, int fd);
