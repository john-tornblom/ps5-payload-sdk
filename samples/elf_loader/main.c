#include "elfldr.h"
#include "payload_elf.c"


int
main() {
  return elfldr_exec(payload_elf, payload_elf_len);
}
