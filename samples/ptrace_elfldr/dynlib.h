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


/**
 * Resolve a symbol with the given *nid* from an sprx with the given *handle*
 * that is loaded in a process with the given pid.
 **/
intptr_t dynlib_resolve(pid_t pid, uint32_t handle, const char *nid);


/**
 * Resolve sceKernelDlsym() loaded in a process with the given pid.
 **/
intptr_t dynlib_resolve_sceKernelDlsym(pid_t pid);
