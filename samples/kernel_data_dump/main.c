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
#include <stdio.h>
#include <unistd.h>

#include <ps5/kernel.h>


#ifndef PHYS_PAGE_SIZE
#define PHYS_PAGE_SIZE 0x1000
#endif


#ifndef NB_PAGES
#define NB_PAGES 0x40000
#endif


int main() {
  uint8_t buf[PHYS_PAGE_SIZE];

  for(int i=0; i<NB_PAGES; i++) {
    off_t offset = sizeof(buf) * i;
    if(kernel_copyout(KERNEL_ADDRESS_DATA_BASE + offset, buf, sizeof(buf))) {
      perror("kernel_copyout");
      return -1;
    }

    if(write(STDOUT_FILENO, buf, sizeof(buf)) != sizeof(buf)) {
      perror("write");
      return -1;
    }
  }

  return 0;
}
