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

#
# Toolchain parameters, override with, e.g.,
#   cmake -DPS5_KERNEL_LIBRARY=kernel_sys
#
set(PS5_PAYLOAD_SDK "${CMAKE_CURRENT_LIST_DIR}/.." CACHE PATH "")
set(PS5_KERNEL_LIBRARY "kernel_web" CACHE STRING "")
set(PS5_TARGET_TRIPLE "x86_64-sie-ps5" CACHE STRING "")

#
# The PS5 is running a modified FreeBSD kernel on a x86_64 CPU
#
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(CMAKE_SYSTEM_NAME FreeBSD)
set(CMAKE_SYSTEM_VERSION 9)
set(CMAKE_CROSSCOMPILING 1)

#
# Use llvm/clang/ld.lld version 15
#
set(CMAKE_ASM_COMPILER clang-15 CACHE PATH "")
set(CMAKE_C_COMPILER clang-15 CACHE PATH "")
set(CMAKE_CXX_COMPILER clang++-15 CACHE PATH "")
set(CMAKE_LINKER ld.lld-15 CACHE PATH "")
set(CMAKE_AR llvm-ar-15 CACHE PATH "")
set(CMAKE_RANLIB llvm-ranlib-15 CACHE PATH "")
set(CMAKE_STRIP llvm-strip-15 CACHE PATH "")

#
# Set sysroot and search paths
#
set(CMAKE_SYSROOT "${PS5_PAYLOAD_SDK}")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

#
# We only support positional independent executables
#
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "Shared libs not available")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#
# Set flags for assembly programs
#
set(CMAKE_ASM_FLAGS_INIT "-target ${PS5_TARGET_TRIPLE}")
set(CMAKE_ASM_LINK_EXECUTABLE
  "<CMAKE_LINKER> -pie -o <TARGET> <CMAKE_ASM_LINK_FLAGS> \
   -T${PS5_PAYLOAD_SDK}/ldscripts/elf_x86_64.x \
   -L${PS5_PAYLOAD_SDK}/usr/lib \
   --start-group \
     <OBJECTS> <LINK_LIBRARIES> \
   --end-group \
  ")

#
# Set flags for C programs
#
set(CMAKE_C_FLAGS_INIT "${CMAKE_ASM_FLAGS_INIT} -isystem ${PS5_PAYLOAD_SDK}/usr/include")
set(CMAKE_C_STANDARD_LIBRARIES "-lSceLibcInternal -l${PS5_KERNEL_LIBRARY}")
set(CMAKE_C_LINK_EXECUTABLE
  "<CMAKE_LINKER> -pie -o <TARGET> <CMAKE_C_LINK_FLAGS> \
   -T${PS5_PAYLOAD_SDK}/ldscripts/elf_x86_64.x \
   -L${PS5_PAYLOAD_SDK}/usr/lib \
   --start-group \
     ${PS5_PAYLOAD_SDK}/usr/lib/crt1.o \
     <OBJECTS> <LINK_LIBRARIES> \
   --end-group \
  ")

#
# Set flags for C++ programs
#
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_C_FLAGS_INIT}")
set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_C_STANDARD_LIBRARIES}")
set(CMAKE_CXX_LINK_EXECUTABLE
  "<CMAKE_LINKER> -pie -o <TARGET> <CMAKE_CXX_LINK_FLAGS> \
   -T${PS5_PAYLOAD_SDK}/ldscripts/elf_x86_64.x \
   -L${PS5_PAYLOAD_SDK}/usr/lib \
   --start-group \
     ${PS5_PAYLOAD_SDK}/usr/lib/crt1.o \
     <OBJECTS> <LINK_LIBRARIES> \
   --end-group \
  ")
