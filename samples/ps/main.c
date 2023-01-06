#include <sys/types.h>
#include <sys/proc.h>
#include <sys/user.h>
#include <sys/sysctl.h>
#include <stdio.h>

#ifndef PID_MAX
#define PID_MAX 99999
#endif


int
main() {
  int i, mib[4] = {1, 14, 1, 0};
  size_t len;
  char buf[10000];

  printf("     PID      PPID     PGID      SID          Emul  Command\n");
  for(i=0; i<=PID_MAX; i++) {
    len = sizeof(buf);
    mib[3] = i;
    if(sysctl(mib, 4, buf, &len, NULL, 0) != -1) {
      struct kinfo_proc *kp = (struct kinfo_proc*)buf;
      printf("%8u  %8u %8u %8u   %11s  %s\n",
	     kp->ki_pid, kp->ki_ppid, kp->ki_pgid, kp->ki_sid,
	     kp->ki_emul, kp->ki_comm);
    }
  }

  return 0;
}

