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


typedef struct payload_args {
  int (*sceKernelDlsym)(int, const char*, void*);
  int *rwpipe;
  int *rwpair;
  long kpipe_addr;
  long kdata_base_addr;
  int *payloadout;
} payload_args_t;


extern int main(int argc, char*argv[]);


int
_start(payload_args_t *args, int sock_fd) {
  //TODO: init modules
  
  *args->payloadout = main(0, 0);

  return *args->payloadout;
}


