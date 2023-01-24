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

