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

DESTDIR ?= /opt/ps5-payload-sdk

CC := clang
LD := ld.lld

CFLAGS  := -ffreestanding -fno-builtin -nostdlib -fPIC
CFLAGS  += -target x86_64-sie-ps5 -fno-stack-protector

all: crt1.o

crt1.o: crt.o klog.o kernel.o rtld.o patch.o mdbg.o env.o
	$(LD) -r -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f *.o

install: crt1.o
	install -d $(DESTDIR)/usr/lib
	install $^ $(DESTDIR)/usr/lib
