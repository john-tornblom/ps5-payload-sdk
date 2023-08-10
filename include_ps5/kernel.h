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

#ifndef PS5SDK_KERNEL_H
#define PS5SDK_KERNEL_H

#include <sys/types.h>

// Absolute kernel pointers
extern const intptr_t KERNEL_ADDRESS_DATA_BASE;
extern const intptr_t KERNEL_ADDRESS_ALLPROC;
extern const intptr_t KERNEL_ADDRESS_PRISON0;
extern const intptr_t KERNEL_ADDRESS_ROOTVNODE;
extern const intptr_t KERNEL_ADDRESS_SECURITY_FLAGS;
extern const intptr_t KERNEL_ADDRESS_UTOKEN_FLAGS;
extern const intptr_t KERNEL_ADDRESS_QA_FLAGS;

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

intptr_t kernel_get_proc(pid_t pid);
intptr_t kernel_get_ucred(pid_t pid);

uint64_t kernel_get_ucred_authid(pid_t pid);
int32_t  kernel_set_ucred_authid(pid_t pid, uint64_t authid);

uint64_t kernel_get_ucred_caps0(pid_t pid);
int32_t  kernel_set_ucred_caps0(pid_t pid, uint64_t caps);

uint64_t kernel_get_ucred_caps1(pid_t pid);
int32_t  kernel_set_ucred_caps1(pid_t pid, uint64_t caps);

uint8_t kernel_get_ucred_attrs(pid_t pid);
int32_t kernel_set_ucred_attrs(pid_t pid, uint64_t attr);

int32_t kernel_get_qaflags(uint8_t qaflags[16]);
int32_t kernel_set_qaflags(uint8_t qaflags[16]);

#endif // PS5SDK_KERNEL_H
