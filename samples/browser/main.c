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

#ifndef PS5_URL
#define PS5_URL "http://192.168.1.1"
#endif


int sceUserServiceInitialize(void*);
int sceUserServiceTerminate(void);

int sceSystemServiceLaunchWebBrowser(const char *uri, void*);


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
 * launch browser
 **/
int
main() {
  if(sceSystemServiceLaunchWebBrowser(PS5_URL, 0)) {
    perror("sceSystemServiceLaunchWebBrowser");
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

