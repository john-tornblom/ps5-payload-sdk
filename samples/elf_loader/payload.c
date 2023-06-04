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

/**
 * Assume argument to _start() is a function pointer to sceKernelDlsym,
 * load puts() from libSceLibcInternal, and print "Hello world!" to stdout.
 **/
void
_start(void* args) {
  int (*sceKernelDlsym)(int, const char*, void*) = (void*)args;
  void (*puts)(const char*);

  if(!sceKernelDlsym(0x2, "puts", &puts)) {
    puts("Hello, world!");
  }
}
