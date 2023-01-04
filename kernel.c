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

unsigned long KERNEL_OFFSET_ALLPROC = 0;


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
long
kernel_get_fw_version(void) {
  unsigned int version = 0;
  unsigned long size = sizeof(version);

  if(sysctlbyname("kern.sdk_version", &version, &size, 0, 0)) {
    return 0;
  }

  return version;
}



/**
 *
 **/
__attribute__((constructor(101))) static int
kernel_init_rw(const payload_args_t *args) {
  int error = 0;

  if((error=args->sceKernelDlsym(0x2001, "_read", &_read))) {
    return error;
  }

  if((error=args->sceKernelDlsym(0x2001, "_write", &_write))) {
    return error;
  }

  if((error=args->sceKernelDlsym(0x2001, "_setsockopt", &_setsockopt))) {
    return error;
  }

  if((error=args->sceKernelDlsym(0x2001, "_getsockopt", &_getsockopt))) {
    return error;
  }

  if((error=args->sceKernelDlsym(0x2001, "sysctlbyname", &sysctlbyname))) {
    return error;
  }

  if((master_sock=args->rwpair[0]) < 0) {
    return -1;
  }

  if((victim_sock=args->rwpair[1]) < 0) {
    return -1;
  }

  if((rw_pipe[0]=args->rwpipe[0]) < 0) {
    return -1;
  }

  if((rw_pipe[1]=args->rwpipe[1]) < 0) {
    return -1;
  }

  if(!(pipe_addr=args->kpipe_addr)) {
    return -1;
  }

  if(!(KERNEL_ADDRESS_DATA_BASE=args->kdata_base_addr)) {
    return -1;
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
    return -1;
  }

  return 0;
}


/**
 *
 **/
static int
kwrite(unsigned long addr, unsigned long *data) {
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
kernel_copyin(const void *udaddr, void* kaddr, unsigned long len) {
  unsigned long write_buf[3];

  // Set pipe flags
  write_buf[0] = 0;
  write_buf[1] = 0x4000000000000000;
  write_buf[2] = 0;
  if(kwrite(pipe_addr, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Set pipe data addr
  write_buf[0] = (unsigned long)kaddr;
  write_buf[1] = 0;
  write_buf[2] = 0;
  if(kwrite(pipe_addr + 0x10, (unsigned long *) &write_buf)) {
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
kernel_copyout(const void *kaddr, void *udaddr, unsigned long len) {
  unsigned long write_buf[3];

  // Set pipe flags
  write_buf[0] = 0x4000000040000000;
  write_buf[1] = 0x4000000000000000;
  write_buf[2] = 0;
  if(kwrite(pipe_addr, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Set pipe data addr
  write_buf[0] = (unsigned long)kaddr;
  write_buf[1] = 0;
  write_buf[2] = 0;
  if(kwrite(pipe_addr + 0x10, (unsigned long *) &write_buf)) {
    return -1;
  }

  // Perform read across pipe
  if(_read(rw_pipe[0], udaddr, len) < 0) {
    return -1;
  }

  return 0;
}

