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
#include <string.h>
#include <unistd.h>

#include <sys/event.h>

#include "patch.h"
#include "pt.h"


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
await_child(void) {
  struct kevent evt;
  pid_t pid = -1;
  int kq;

  if((kq=kqueue()) < 0) {
    perror("kqueue");
    return -1;
  }

  EV_SET(&evt, getppid(), EVFILT_PROC, EV_ADD, NOTE_FORK | NOTE_TRACK, 0, NULL);
  if(kevent(kq, &evt, 1, NULL, 0, NULL) < 0) {
    perror("kevent");
    close(kq);
    return -1;
  }

  while(1) {
    if(kevent(kq, NULL, 0, &evt, 1, NULL) < 0) {
      perror("kevent");
      break;
    }

    if(evt.fflags & NOTE_CHILD) {
      pid = evt.ident;
      break;
    }
  }

  close(kq);

  return pid;
}


int main() {
  app_info_t info;
  pid_t child;

  while(1) {
    if((child=await_child()) < 0) {
      break;
    }

    if(pt_attach(child) < 0) {
      break;
    }

    memset(&info, 0, sizeof(info));
    if(!sceKernelGetAppInfo(child, &info)) {
      patch_app(child, info.app_id, info.app_type, info.title_id);
    } else {
      perror("sceKernelGetAppInfo");
    }

    if(pt_detach(child) < 0) {
      break;
    }

#ifdef TEST_RUN_ONCE
    break;
#endif
  }

  return 0;
}
