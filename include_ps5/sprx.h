#ifndef PS5SDK_SPRX_H
#define PS5SDK_SPRX_H

#include <sys/types.h>

int sprx_dlopen(const char* libname, uint16_t *handle);
int sprx_dlsym(uint16_t handle, const char *symname, void *addr);
int sprx_dlclose(uint16_t handle);

#endif // PS5SDK_SPRX_H
