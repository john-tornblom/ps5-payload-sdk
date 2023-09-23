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
#include <string.h>
#include <unistd.h>

#ifndef PS5_TITLE_ID
#define PS5_TITLE_ID "PPSA01325" // ASTRO's PLAYROOM
#endif


typedef struct app_launch_ctx {
  uint32_t structsize;
  uint32_t user_id;
  uint32_t app_opt;
  uint64_t crash_report;
  uint32_t check_flag;
} app_launch_ctx_t;


int sceUserServiceInitialize(void*);
int sceUserServiceGetForegroundUser(uint32_t *user_id);
int sceUserServiceTerminate(void);

int sceSystemServiceLaunchApp(const char* title_id, const char** argv,
			      app_launch_ctx_t* ctx);


/**
 * init UserService
 **/
__attribute__((constructor)) static void
constructor(void) {
  if(sceUserServiceInitialize(0)) {
    perror("sceUserServiceInitialize");
  }
}


/**
 * launch app
 **/
int
main() {
  const char* argv[] = {0};
  app_launch_ctx_t ctx;

  memset(&ctx, 0, sizeof(ctx));
  if(sceUserServiceGetForegroundUser(&ctx.user_id)) {
    perror("sceUserServiceGetForegroundUser");
    return EXIT_FAILURE;
  }

  if(sceSystemServiceLaunchApp(PS5_TITLE_ID, argv, &ctx) < 0) {
    perror("sceSystemServiceLaunchApp");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}


/**
 * terminate UserService
 **/
__attribute__((destructor)) static void
destructor(void) {
  sceUserServiceTerminate();
}

