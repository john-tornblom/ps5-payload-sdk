#ifndef PS5SDK_KERNEL_H
#define PS5SDK_KERNEL_H

#include <sys/types.h>

extern const intptr_t KERNEL_ADDRESS_DATA_BASE;
extern const intptr_t KERNEL_ADDRESS_ALLPROC;

// Proc field offsets
extern const off_t KERNEL_OFFSET_PROC_P_UCRED;
extern const off_t KERNEL_OFFSET_PROC_P_PID;

// Ucred field offsets
extern const off_t KERNEL_OFFSET_UCRED_CR_UID;
extern const off_t KERNEL_OFFSET_UCRED_CR_RUID;
extern const off_t KERNEL_OFFSET_UCRED_CR_SVUID;
extern const off_t KERNEL_OFFSET_UCRED_CR_RGID;
extern const off_t KERNEL_OFFSET_UCRED_CR_SCEAUTHID;
extern const off_t KERNEL_OFFSET_UCRED_CR_SCECAPS0;
extern const off_t KERNEL_OFFSET_UCRED_CR_SCECAPS1;
extern const off_t KERNEL_OFFSET_UCRED_CR_SCEATTR0;

uint32_t kernel_get_fw_version(void);

int32_t  kernel_copyin(const void *udaddr, intptr_t kaddr, size_t len);
int32_t  kernel_copyout(const intptr_t kaddr, void *udaddr, size_t  len);


intptr_t kernel_get_ucred(pid_t pid);
intptr_t kernel_get_proc(pid_t pid);

uint64_t kernel_get_proc_authid(pid_t pid);
int32_t  kernel_set_proc_authid(pid_t pid, uint64_t authid);

#endif // PS5SDK_KERNEL_H
