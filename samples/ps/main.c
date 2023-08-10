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


#include <sys/types.h>
#include <sys/proc.h>
#include <sys/user.h>
#include <sys/sysctl.h>
#include <stdio.h>

#include <ps5/kernel.h>

#ifndef PID_MAX
#define PID_MAX 99999
#endif


int
main() {
  int i, mib[4] = {1, 14, 1, 0};
  size_t len;
  char buf[10000];

  printf("     PID      PPID     PGID      SID      UID           AuthId          Emul  Command\n");
  for(i=0; i<=PID_MAX; i++) {
    len = sizeof(buf);
    mib[3] = i;
    if(sysctl(mib, 4, buf, &len, NULL, 0) != -1) {
      struct kinfo_proc *kp = (struct kinfo_proc*)buf;
      printf("%8u  %8u %8u %8u %8u %016lx   %11s  %s\n",
	     kp->ki_pid, kp->ki_ppid, kp->ki_pgid, kp->ki_sid,
	     kp->ki_uid, kernel_get_ucred_authid(kp->ki_pid),
	     kp->ki_emul, kp->ki_comm);
    }
  }

  return 0;
}

