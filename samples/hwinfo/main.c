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


int  sceKernelGetHwModelName(char *);
int  sceKernelGetHwSerialNumber(char *);
long sceKernelGetCpuFrequency(void);
int  sceKernelGetCpuTemperature(int *);
int  sceKernelGetSocSensorTemperature(int, int *);


int
main() {
  char s[1000];
  int temp = 0;

  s[0] = '\0';

  if(sceKernelGetHwModelName(s)) {
    perror("sceKernelGetHwModelName");
  } else {
    printf("Model:\t\t %s\n", s);
  }

  if(sceKernelGetHwSerialNumber(s)) {
    perror("sceKernelGetHwSerialNumber");
  } else {
    printf("S/N:\t\t %s\n", s);
  }

  if(sceKernelGetSocSensorTemperature(0, &temp)) {
    perror("sceKernelGetSocSensorTemperature");
  } else {
    printf("SoC temp:\t %d °C\n", temp);
  }

  if(sceKernelGetCpuTemperature(&temp)) {
    perror("sceKernelGetCpuTemperature");
  } else {
    printf("CPU temp:\t %d °C\n", temp);
  }

  printf("CPU freq:\t %2.2ld MHz\n",
	 sceKernelGetCpuFrequency() / (1000*1000));

  return 0;
}

