#include "elfldr.h"
#include "payload_elf.c"

#include <stdio.h>

int
main() {
  return elfldr_exec(payload_elf, payload_elf_len);
}
