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
TOOLS   := x86_64-ps5-payload-cc x86_64-ps5-baremetal-cc \
	   x86_64-ps5-payload-cxx x86_64-ps5-baremetal-cxx \
	   x86_64-ps5-payload-ld x86_64-ps5-baremetal-ld

MAKEFILES := x86_64-ps5-payload.inc x86_64-ps5-baremetal.inc

all:

clean:

install: install-tools install-makefiles

install-tools: $(TOOLS)
	install -d $(DESTDIR)/host
	install $^ $(DESTDIR)/host

install-makefiles: $(MAKEFILES)
	install -d $(DESTDIR)/make
	install $^ $(DESTDIR)/make
