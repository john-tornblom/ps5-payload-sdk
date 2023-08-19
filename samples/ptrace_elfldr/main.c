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

#include <unistd.h>
#include <pthread.h>

#include <ps5/kernel.h>

#include "elfldr.h"


/**
 * Embed the ELF socket server into the bootstrap ELF.
 **/
#ifdef ELFLDR_BOOTSRTAP
#include "elfldr-socksever_elf.c"
#endif


/**
 * Launch and ELF in its own thread.
 **/
static void*
main_thread(void *args) {
  pid_t pid = getpid();
  uint64_t authid;
  
  if(!(authid=kernel_get_ucred_authid(pid))) {
    return NULL;
  }

  if(kernel_set_ucred_authid(getpid(), 0x4800000000010003l)) {
    return NULL;
  }

#ifdef ELFLDR_BOOTSRTAP
  elfldr_exec("ScePartyDaemon", elfldr_socksever_elf, elfldr_socksever_elf_len);
#else
  elfldr_serve("SceRedisServer", SOCKET_PORT);
#endif

  kernel_set_ucred_authid(getpid(), authid);
  
  return NULL;
}


/**
 * Entry point of the payload.
 **/
int
main() {
  pthread_t trd;

  pthread_create(&trd, NULL, main_thread, NULL);

#ifdef ELFLDR_BOOTSRTAP
  pthread_join(trd, NULL);
#endif
  
  return 0;
}
