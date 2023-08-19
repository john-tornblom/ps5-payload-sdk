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


/**
 * Launch a socket server on the given port that execute ELFs
 * within inside process with the given name.
 **/
int elfldr_serve(const char* procname, uint16_t port);


/**
 * Execute an ELF inside the process with the given name.
 **/
int elfldr_exec(const char* procname, uint8_t *elf, size_t size);
