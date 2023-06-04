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


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <ps5/kernel.h>


/**
 * Set uid of the running process to 0x1337.
 **/
int main(void) {
  uint64_t ucred = kernel_get_ucred(getpid());
  uint32_t uid = 0x1337;
  
  printf("[+] UID = 0x%x\n", getuid());

  kernel_copyin(&uid, ucred + KERNEL_OFFSET_UCRED_CR_UID, sizeof(uid));
  kernel_copyin(&uid, ucred + KERNEL_OFFSET_UCRED_CR_RUID, sizeof(uid));
  kernel_copyin(&uid, ucred + KERNEL_OFFSET_UCRED_CR_SVUID, sizeof(uid));
  kernel_copyin(&uid, ucred + KERNEL_OFFSET_UCRED_CR_RGID, sizeof(uid));

  printf("[+] UID = 0x%x\n", getuid());

  return EXIT_SUCCESS;
}

