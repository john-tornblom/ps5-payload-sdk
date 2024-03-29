#   Copyright (C) 2024 John Törnblom
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

CC   := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-payload-cc
LD   := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-payload-ld
MAKE ?= make

CFLAGS ?=
LDADD  ?= 
LDADD  += -lSceLibcInternal
