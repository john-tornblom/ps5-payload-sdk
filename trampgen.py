#!/usr/bin/env python3
# encoding: utf-8
# Copyright (C) 2023 John Törnblom
#
# This program is free software; you can redistribute it and/or modify it
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

import argparse
import logging
import os
import xml.etree.ElementTree as ET

from pathlib import Path
from elftools.elf.elffile import ELFFile


logger = logging.getLogger('trampgen')


# read NIDs from nid_db.xml
NID_DB = (os.path.dirname(__file__) or '.') + '/nid_db.xml'
nid_map = {entry.get('obf'): entry.get('sym')
           for entry in ET.parse(NID_DB).getroot()}



def symbols(sym_type, filename):
    '''
    yield symbol names in PT_DYNAMIC segments using the NID lookup table
    'nid_db.xml'.
    '''
    with open(filename, 'rb') as f:
        elf = ELFFile(f)

        for segment in elf.iter_segments():
            if segment.header.p_type != 'PT_DYNAMIC':
                continue

            for sym in segment.iter_symbols():
                if sym_type != sym.entry['st_info']['type']:
                    continue

                sym_nid = sym.name[:11]
                if not sym_nid in nid_map:
                    logger.warning(f'skipping unknown NID {sym.name}')
                    continue

                yield nid_map[sym_nid]


if __name__ == '__main__':
    logging.basicConfig(level=logging.WARNING)

    parser = argparse.ArgumentParser()
    parser.add_argument('--prx', required=True)
    parser.add_argument('--module-id', required=True)

    cli_args = parser.parse_args()

    modid = cli_args.module_id
    funcs = sorted(set(symbols('STT_FUNC', cli_args.prx)))
    gvars = sorted(set(symbols('STT_OBJECT', cli_args.prx)))

    # declare functions
    for sym in funcs:
        print(f'static void* __{sym}__ = 0;')
        print('asm(')
        print('    ".intel_syntax noprefix\\n"')
        print(f'    ".global {sym}\\n"')
        print(f'    "{sym}:\\n"')
        print(f'    "jmp qword ptr [rip + __{sym}__]\\n");')
        print('')

    # initialize function pointers
    stem = Path(cli_args.prx).stem
    print(f'int {stem}_dlsym(int (*dlsym)(int, const char*, void*)) ' + '{')
    for sym in funcs:
        print(f'  if(dlsym({modid}, "{sym}", &__{sym}__)) return -1;')
    print('  return 0;')
    print('}')
