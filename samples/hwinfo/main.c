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

  printf("CPU freq:\t %2.2f MHz\n",
	 sceKernelGetCpuFrequency() / (double)(1000*1000));

  return 0;
}

