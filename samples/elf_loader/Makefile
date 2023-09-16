#   Copyright (C) 2023 John Törnblom
#
# This file is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING. If not see
# <http://www.gnu.org/licenses/>.

ifndef PS5_PAYLOAD_SDK
    $(error PS5_PAYLOAD_SDK is undefined)
endif

PS5_HOST ?= ps5
PS5_PORT ?= 9021

CC := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-payload-cc
LD := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-payload-ld

CFLAGS := -O2
LDADD  := -lkernel_sys -lSceLibcInternal

# Build the payload for a bare-metal runtime environment
CC_BM := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-baremetal-cc
LD_BM := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-baremetal-ld


all: loader.elf

loader.elf: elfldr.o main.o
	$(LD) $^ $(LDADD) -o $@

elfldr.o: elfldr.c
	$(CC) -c $(CFLAGS) -o $@ $<

main.o: main.c payload_elf.c
	$(CC) -c $(CFLAGS) -o $@ $<

payload_elf.c: payload.elf
	xxd -i $< > $@

payload.elf: payload.o
	$(LD_BM) $< -o $@

payload.o: payload.c
	$(CC_BM) -c -o $@ $<

clean:
	rm -f *.o *.elf payload_elf.c

test: loader.elf
	nc -q0 $(PS5_HOST) $(PS5_PORT) < $^

