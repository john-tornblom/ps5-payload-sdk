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
PS5_PORT ?= 9020

CC := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-payload-cc
LD := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-payload-ld

CFLAGS := -O2
LDADD  := -lkernel_web -lSceLibcInternal
OBJS   := elfldr.o ptrace.o dynlib.o


all: elfldr-bootstrap.elf

elfldr-bootstrap.elf: main-bootstrap.o $(OBJS)
	$(LD) $^ $(LDADD) -o $@

elfldr-socksever.elf: main-socksever.o $(OBJS)
	$(LD) $^ $(LDADD) -o $@

main-bootstrap.o: main.c elfldr-socksever_elf.c
	$(CC) -DELFLDR_BOOTSRTAP -c $(CFLAGS) -o $@ $<

main-socksever.o: main.c
	$(CC) -DSOCKET_PORT=9021 -c $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

elfldr-socksever_elf.c: elfldr-socksever.elf
	xxd -i $< > $@

clean:
	rm -f *.o *.elf elfldr-socksever_elf.c

test: elfldr-bootstrap.elf
	nc -q0 $(PS5_HOST) $(PS5_PORT) < $^
