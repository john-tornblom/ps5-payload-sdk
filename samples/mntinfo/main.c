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
#include <sys/mount.h>


/**
 * Get all mount points.
 **/
static int
get_mount_info(struct statfs **bufp, int mode) {
  struct statfs *buf;
  int nitems = 0;
  int size = 0;
  int size2 = 0;

  // get number of mount points
  if((nitems = getfsstat(0, 0, MNT_NOWAIT)) < 0) {
    perror("getfsstat");
    return -1;
  }

  // allocate sufficient space
  size = sizeof(struct statfs) * nitems;
  if(!(buf = malloc(size))) {
    perror("malloc");
    return -1;
  }

  // get the mount points
  memset(buf, 0, size);
  if((size2 = getfsstat(buf, size, mode)) < 0) {
    perror("getfsstat");
    return -1;
  }

  *bufp = buf;

  return nitems;
}


/**
 * Print all mount points to stdout.
 **/
int
main(void) {
  struct statfs *buf = 0;
  int nitems = 0;

  if((nitems = get_mount_info(&buf, MNT_WAIT)) < 0) {
    return EXIT_FAILURE;
  }

  for(int i=0; i<nitems; i++) {
    printf("%s on %s (%s, flags=0x%lx)\n",
	   buf[i].f_mntfromname,
	   buf[i].f_mntonname,
	   buf[i].f_fstypename,
	   buf[i].f_flags);
  }

  free(buf);

  return EXIT_SUCCESS;
}

