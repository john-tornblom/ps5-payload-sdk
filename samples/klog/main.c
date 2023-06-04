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
#include <fcntl.h>


int
main() {
  struct timeval timeout;
  fd_set set;
  char ch;
  int fd;

  if((fd=open("/dev/klog", O_RDONLY)) < 0) {
    perror("open");
    return EXIT_FAILURE;
  }

  FD_ZERO(&set);
  FD_SET(fd, &set);

  timeout.tv_sec = 1;
  timeout.tv_usec = 0;

  while(1) {
    switch(select(fd+1, &set, NULL, NULL, &timeout)) {
    case -1: // on error
      perror("select");
      close(fd);
      return EXIT_FAILURE;

    case 0: // on timeout
      close(fd);
      return EXIT_SUCCESS;

    default: // on data
      if(read(fd, &ch, 1) != 1) {
	perror("read");
	close(fd);
	return EXIT_FAILURE;
      } else {
	printf("%c", ch);
      }
      break;
    }
  }

  close(fd);
  return EXIT_SUCCESS;
}

