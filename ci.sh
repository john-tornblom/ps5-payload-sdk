#!/usr/bin/env bash
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

export DESTDIR=$(mktemp -d)
trap 'rm -rf -- "$DESTDIR"' EXIT

SAMPLES=("arbitrary_syscall"
         "elf_loader"
	 "hello_sprx"
	 "hello_stdio"
	 "hello_world"
	 "hwinfo"
	 "klog"
	 "list_files"
	 "mntinfo"
	 "pipe_pirate"
	 "ps"
	 "remount")

CCLIST=("gcc"
	"clang")

LDLIST=("ld"
	"ld.lld")

export PS5_PAYLOAD_SDK=$DESTDIR

for CC in "${CCLIST[@]}"; do
    export CC
    for LD in "${LDLIST[@]}"; do
	export LD
	make clean install || exit 1
	for PS5_PAYLOAD_CC in "${CCLIST[@]}"; do
	    export PS5_PAYLOAD_CC
	    for PS5_PAYLOAD_LD in "${LDLIST[@]}"; do
		export PS5_PAYLOAD_LD
		for SAMPLE in "${SAMPLES[@]}"; do
		    make -C samples/$SAMPLE clean all || exit 1
		done
	    done
	done
    done
done
