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


/**
 * Prototype for module constructors.
 **/
typedef int (*init_module_t)(const payload_args_t*);


/**
 * Prototype for module destructors.
 **/
typedef void (*fini_module_t)(void);


#endif // PS5SDK_PAYLOAD_H
