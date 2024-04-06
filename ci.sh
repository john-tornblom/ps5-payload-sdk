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

make clean install || exit 1

MAKE_SAMPLES=("arbitrary_syscall"
	      "browser"
	      "hello_sprx"
	      "hello_stdio"
	      "hello_world"
	      "hwinfo"
	      "list_files"
	      "mntinfo"
	      "ps")

CMAKE_SAMPLES=("hello_cmake"
	      )

export PS5_PAYLOAD_SDK=$DESTDIR

for SAMPLE in "${MAKE_SAMPLES[@]}"; do
    make -C samples/$SAMPLE clean all || exit 1
done

for SAMPLE in "${CMAKE_SAMPLES[@]}"; do
    cmake -B $DESTDIR/build/$SAMPLE \
	  -DCMAKE_TOOLCHAIN_FILE=$PS5_PAYLOAD_SDK/cmake/toolchain.cmake \
	  samples/$SAMPLE || exit 1
    make  -C $DESTDIR/build/$SAMPLE clean all || exit 1
done
