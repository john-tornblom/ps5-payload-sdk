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

CC     ?= cc
CFLAGS := -ffreestanding -fno-builtin -nostdlib -static -masm=intel

PYTHON  := python3
DESTDIR ?= /opt/ps5-payload-sdk

MOD_SOURCES  := libkernel.c libkernel_sys.c libkernel_web.c \
                libSceLibcInternal.c
MOD_ARCHIVES := $(MOD_SOURCES:.c=.a)

NID_DB_URL  := https://raw.githubusercontent.com/astrelsky/GhidraOrbis/master/data/nid_db.xml


all: crt1.o $(MOD_ARCHIVES)

nid_db.xml:
	wget $(NID_DB_URL)

libkernel.c: libkernel.sprx nid_db.xml trampgen.py
	$(PYTHON) trampgen.py --module-id 0x2001 --prx $< > $@

libkernel_sys.c: libkernel_sys.sprx nid_db.xml trampgen.py
	$(PYTHON) trampgen.py --module-id 0x2001 --prx $< > $@

libkernel_web.c: libkernel_web.sprx nid_db.xml trampgen.py
	$(PYTHON) trampgen.py --module-id 0x2001 --prx $< > $@

libSceLibcInternal.c: libSceLibcInternal.sprx nid_db.xml trampgen.py
	$(PYTHON) trampgen.py --module-id 0x2 --prx $< > $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

libkernel.a: libkernel.o kernel.o
	ar rcs $@ $^

libkernel_web.a: libkernel_web.o kernel.o
	ar rcs $@ $^

libkernel_sys.a: libkernel_sys.o kernel.o
	ar rcs $@ $^

%.a: %.o
	ar rcs $@ $^

clean:
	rm -f *.o *.a nid_db.xml

install: linker.x crt1.o $(MOD_ARCHIVES)
	install -d $(DESTDIR)/usr/lib
	install linker.x $(DESTDIR)
	install crt1.o $(MOD_ARCHIVES) $(DESTDIR)/usr/lib
	cp -r include_bsd/. $(DESTDIR)/usr/include
	cp -r include_ps5/. $(DESTDIR)/usr/include/ps5
