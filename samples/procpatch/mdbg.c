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
#include <string.h>
#include <unistd.h>

#include <ps5/kernel.h>

#include "ui.h"


/**
 *
 **/
#define MDBG_MEMOP_READ  0x12
#define MDBG_MEMOP_WRITE 0x13


/**
 *
 **/
typedef struct mdbg_cmd {
  uint64_t type;
  uint64_t cmd;
} mdbg_cmd_t;


/**
 *
 **/
typedef struct mdbg_memop_args {
  pid_t pid;
  intptr_t src;
  intptr_t dst;
  size_t len;
} mdbg_memop_args_t;


/**
 *
 **/
typedef struct mdbg_res {
  int status;
  size_t len;
} mdbg_res_t;



/**
 *
 **/
static int
mdbg_memop(int memop, mdbg_memop_args_t *args) {
  mdbg_cmd_t cmd = {1, memop};
  pid_t pid = getpid();
  uint64_t authid;
  mdbg_res_t res;
  long err;

  if(!(authid=kernel_get_ucred_authid(pid))) {
    return -1;
  }

  if(kernel_set_ucred_authid(pid, 0x4800000000000006l)) {
    return -1;
  }

  do {
    memset(&res, 0, sizeof(res));
    if((err=syscall(573, &cmd, args, &res)) == -1) {
      ui_perror("mdbg");
      break;
    }
    args->src += res.len;
    args->dst += res.len;
    args->len -= res.len;
  } while(res.status != 0 && args->len && res.len);

  if(kernel_set_ucred_authid(pid, authid)) {
    return -1;
  }

  return err;
}


int
mdbg_copyout(pid_t pid, intptr_t addr, void *buf, size_t len) {
  mdbg_memop_args_t args = {pid, addr, (intptr_t)buf, len};
  return mdbg_memop(MDBG_MEMOP_READ, &args);
}


int
mdbg_copyin(pid_t pid, const void* buf, intptr_t addr, size_t len) {
  mdbg_memop_args_t args = {pid, (intptr_t)buf, addr, len};
  return mdbg_memop(MDBG_MEMOP_WRITE, &args);
}
