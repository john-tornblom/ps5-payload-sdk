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


typedef struct notify_request {
  char useless1[45];
  char message[3075];
} notify_request_t;


void
_start(void* args) {
  notify_request_t req;

  int (*sceKernelDlsym)(int, const char*, void*) = (void*)args;
  int (*sceKernelSendNotificationRequest)(int, notify_request_t*, long, int);
  int (*bzero)(void*, unsigned long);
  int (*sprintf)(char *, const char*, ...);
  int (*getpid)(void);

  sceKernelDlsym(0x2, "bzero", &bzero);
  sceKernelDlsym(0x2, "sprintf", &sprintf);
  sceKernelDlsym(0x2001, "getpid", &getpid);
  sceKernelDlsym(0x2001, "sceKernelSendNotificationRequest",
		 &sceKernelSendNotificationRequest);

  bzero(&req, sizeof req);
  sprintf(req.message, "Hello from pid %d", getpid());

  sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
}

