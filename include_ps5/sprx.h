#ifndef PS5SDK_SPRX_H
#define PS5SDK_SPRX_H

int sprx_dlopen(const char* libname, unsigned short *handle);
int sprx_dlsym(unsigned short handle, const char *symname, void *addr);
int sprx_dlclose(unsigned short handle);

#endif // PS5SDK_SPRX_H
