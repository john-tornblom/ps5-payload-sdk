/* Copyright (C) 2024 John Törnblom

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

#include "klog.h"
#include "payload.h"


/**
 * external dependencies.
 **/
static void  (*free)(void*) = 0;
static char* (*strdup)(const char*) = 0;
static char* (*strstr)(const char*, const char*) = 0;
static int   (*setenv)(const char*, const char*, int) = 0;
static char* (*getenv)(const char*) = 0;
static int   (*chdir)(const char*) = 0;


/**
 *
 **/
static void
parse_and_define(const char* var) {
  char *s = strdup(var);
  char* sep = strstr(s, "=");
  char* val = sep + 1;

  if(sep) {
    *sep = 0;
    if(setenv(s, val, 1)) {
      klog_perror("setenv");
    }
  } else {
    if(setenv(s, 0, 1)) {
      klog_perror("setenv");
    }
  }

  free(s);
}


/**
 *
 **/
__attribute__((constructor(105))) static void
env_constructor(payload_args_t *args, int argc, char** argv, char** envp) {
  const char* cwd;

  if(!envp || !envp[0]) {
    return;
  }

  if(args->sceKernelDlsym(0x1, "chdir", &chdir)) {
    return; // webkit entry point
  }

  if(args->sceKernelDlsym(0x2, "free", &free)) {
    klog_perror("Unable to resolve 'free'");
    return;
  }
  if(args->sceKernelDlsym(0x2, "strdup", &strdup)) {
    klog_perror("Unable to resolve 'strdup'");
    return;
  }
  if(args->sceKernelDlsym(0x2, "strstr", &strstr)) {
    klog_perror("Unable to resolve 'strstr'");
    return;
  }
  if(args->sceKernelDlsym(0x2, "setenv", &setenv)) {
    klog_perror("Unable to resolve 'setenv'");
    return;
  }
  if(args->sceKernelDlsym(0x2, "getenv", &getenv)) {
    klog_perror("Unable to resolve 'getenv'");
    return;
  }

  for (int i=0; envp[i]; i++) {
    parse_and_define(envp[i]);
  }

  if((cwd=getenv("PWD"))) {
    klog_printf("%s\n", cwd);
    chdir(cwd);
  }
}
