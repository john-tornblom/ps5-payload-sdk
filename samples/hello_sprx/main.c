#include <stdint.h>
#include <stdio.h>
#include <string.h>


int sceRandomGetRandomNumber(uint8_t* buf, size_t size);


static void
hexdump(uint8_t* buf, size_t size) {
  for(int i=0; i<size; i++) {
    if(i%16 == 0 && i!= 0) {
      printf("\n");
    }
    printf("%02x ", buf[i]);
  }
  printf("\n");
}


int main() {
  uint8_t buf[0x40];

  memset(buf, 0, sizeof(buf));
  if(!sceRandomGetRandomNumber(buf, sizeof(buf))) {
    hexdump(buf, sizeof(buf));
  }
  
  return 0;
}
