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

#include <unistd.h>
#include <sys/ptrace.h>


/**
 *
 **/
int pt_attach(pid_t pid);


/**
 *
 **/
int pt_detach(pid_t pid);


/**
 *
 **/
int pt_vm_entry(pid_t pid, struct ptrace_vm_entry *ve);
