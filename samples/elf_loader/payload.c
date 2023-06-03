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
