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

PYTHON ?= python3
CC     ?= cc
CFLAGS := -ffreestanding -fno-builtin -nostdlib -O2
CFLAGS += -mcmodel=large -fPIC -fno-plt -masm=intel

SPRXS := $(wildcard *.sprx)
STUBS := $(SPRXS:.sprx=.c)

SOURCES   := $(wildcard *.c)
ARCHIVES  := $(SOURCES:.c=.a)

NID_DB_URL := https://raw.githubusercontent.com/astrelsky/GhidraOrbis/master/data/nid_db.xml

DESTDIR ?= /opt/ps5-payload-sdk


all: $(SOURCES) $(ARCHIVES)
stubs: nid_db.xml $(STUBS)


nid_db.xml:
	wget -O $@ $(NID_DB_URL)

%.c: %.sprx
	$(PYTHON) trampgen.py $*.sprx > $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

%.a: %.o
	ar rcs $@ $^

clean:
	rm -f *.o *.a nid_db.xml

install: $(ARCHIVES)
	install -d $(DESTDIR)/usr/lib
	install $(ARCHIVES) $(DESTDIR)/usr/lib
