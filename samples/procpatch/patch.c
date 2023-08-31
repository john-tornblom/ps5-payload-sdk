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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/ptrace.h>

#include "mdbg.h"
#include "patch.h"
#include "pt.h"
#include "ui.h"


int
patch_app(pid_t pid, uint32_t app_id, uint32_t app_type, const char* title_id) {
  struct ptrace_vm_entry ve;
  uint8_t *buf;
  size_t len;

  ui_notify("New application launched\n"
	    "------------------------\n"
	    "title_id = %s\n"
	    "app_id = 0x%x\n"
	    "app_type = 0x%x\n"
	    "pid = %d\n",
	    title_id, app_id, app_type, pid);

  // TODO: something useful. For now, just sanity test mdbg
  memset(&ve, 0, sizeof(ve));
  if(pt_vm_entry(pid, &ve)) {
    return -1;
  }

  len = ve.pve_end - ve.pve_start;
  if(!(buf=malloc(len))){
    return -1;
  }

  ui_notify("pid %d vm entry 0 starts at: 0x%lx\n", pid, ve.pve_start);

  if(mdbg_copyout(pid, ve.pve_start, buf, len)) {
    free(buf);
    return -1;
  }

  if(mdbg_copyin(pid, buf, ve.pve_start, len)) {
    free(buf);
    return -1;
  }

  free(buf);

  return 0;
}
