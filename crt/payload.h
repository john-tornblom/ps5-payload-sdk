#ifndef PS5SDK_PAYLOAD_H
#define PS5SDK_PAYLOAD_H

/**
 * Payload arguments.
 **/
typedef struct payload_args {
  int (*sceKernelDlsym)(int, const char*, void*);
  int  *rwpipe;
  int  *rwpair;
  long  kpipe_addr;
  long  kdata_base_addr;
  int  *payloadout;
} payload_args_t;


extern payload_args_t* __payload_args;


#endif // PS5SDK_PAYLOAD_H
