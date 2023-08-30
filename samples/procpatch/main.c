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

#include <pthread.h>
#include <string.h>

#include "mdbg.h"
#include "pt.h"
#include "ui.h"


#define TESTING_MODE 1


static int
watchdog_loop(void) {
  struct ptrace_vm_entry ve;
  pid_t parent = getppid();
  pid_t child = 0;

  if(pt_attach(parent)) {
    return -1;
  }

  if(pt_follow_fork(parent)) {
    return pt_detach(parent);
  }

  if(pt_continue(parent)) {
    return pt_detach(parent);
  }

  while(1) {
    if((child=pt_await_child(parent)) < 0) {
      return pt_detach(parent);
    }

    // TODO: do something interesting
#ifdef TESTING_MODE
    memset(&ve, 0, sizeof(ve));
    if(!pt_vm_entry(child, &ve)) {
      ui_notify("pid %d vm entry 0 starts at: 0x%lx\n", child, ve.pve_start);
      uint8_t buf[ve.pve_end-ve.pve_start];
      memset(buf, 0, sizeof(buf));
      mdbg_copyout(child, ve.pve_start, buf, sizeof(buf));
    }
#endif

    if(pt_detach(child)) {
      return pt_detach(parent);
    }

#ifdef TESTING_MODE
    break;
#endif
  }

  pt_detach(parent);

  return 0;
}


static void*
watchdog_thread(void *args) {
  watchdog_loop();
  return NULL;
}


int
main() {
  pthread_t trd;
  return pthread_create(&trd, NULL, &watchdog_thread, NULL);
}
