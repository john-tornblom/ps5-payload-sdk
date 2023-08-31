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


#define TEST_RUN_ONCE 1


typedef struct app_info {
  uint32_t app_id;
  uint64_t unknown1;
  uint32_t app_type;
  char     title_id[10];
  char     unknown2[0x3c];
} app_info_t;


int sceKernelGetAppInfo(pid_t pid, app_info_t *info);


static pid_t
await_child(pid_t parent) {
  pid_t child = 0;

  if(pt_attach(parent) < 0) {
    return -1;
  }

  if(pt_follow_fork(parent) < 0) {
    pt_detach(parent);
    return -1;
  }

  if(pt_continue(parent) < 0) {
    pt_detach(parent);
    return -1;
  }

  if((child=pt_await_child(parent)) < 0) {
    pt_detach(parent);
    return -1;
  }

  if(pt_detach(child) < 0) {
    pt_detach(parent);
    return -1;
  }

  if(pt_detach(parent) < 0) {
    return -1;
  }

  return child;
}


static void*
watchdog_thread(void *args) {
  pid_t parent = getppid();
  app_info_t info;
  pid_t child;

  ui_notify("procpatch sample started");
  while(1) {
    if((child=await_child(parent)) < 0) {
      break;
    }

    memset(&info, 0, sizeof(info));
    if(!sceKernelGetAppInfo(child, &info)) {
      ui_notify("New application launch\n"
		"----------------------\n"
		"title_id = %s\n"
		"app_id = 0x%x\n"
		"app_type = 0x%x\n"
		"pid = %d\n",
		info.title_id, info.app_id, info.app_type, child);
      //TODO: do something useful
    } else {
      ui_perror("sceKernelGetAppInfo");
    }

#ifdef TEST_RUN_ONCE
    break;
#endif
  }

  return NULL;
}


int
main() {
  pthread_t trd;

  pthread_create(&trd, NULL, &watchdog_thread, NULL);

  return 0;
}
