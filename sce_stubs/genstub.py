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
import base64
import logging
import os
import string
import sys

import xml.etree.ElementTree as ET

from pathlib import Path
from elftools.elf.elffile import ELFFile


logger = logging.getLogger('gensub')


# read NIDs from nid_db.xml
NID_DB = (os.path.dirname(__file__) or '.') + '/nid_db.xml'
nid_map = {entry.get('obf'): entry.get('sym')
           for entry in ET.parse(NID_DB).getroot()}


tmpl_func = string.Template('''
asm(".global $name\\n"
    ".type   $name, @function\\n"
    ".symver $name, $name@@$nid\\n"
    "$name:\\n");''')


tmpl_obj = string.Template('''
asm(".global $name\\n"
    ".type   $name, @object\\n"
    ".symver $name, $name@@$nid\\n"
    "$name:\\n");''')

tmpl_map = string.Template('''$nid { global: $name; };''')


def nid_decode(nid):
    val = b'\0'
    for i in range(4):
        try:
            val = base64.b64decode(nid + ('=' * i))
        except:
            continue

    return int.from_bytes(val, byteorder='big')


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

                if sym.entry['st_shndx'] == 'SHN_UNDEF':
                    continue

                if not sym.name:
                    continue

                nid, lid, mid = sym.name.split('#')
                if not nid in nid_map:
                    logger.warning(f'skipping unknown NID {nid}')
                    continue

                yield nid_map[nid], '0x%016X' % nid_decode(nid)


if __name__ == '__main__':
    logging.basicConfig(level=logging.WARNING)

    parser = argparse.ArgumentParser()
    parser.add_argument('SPRX_FILE')
    cli_args = parser.parse_args()

    libname = Path(cli_args.SPRX_FILE).stem
    filename = cli_args.SPRX_FILE

    funcs = sorted(set(symbols('STT_FUNC', filename)))
    gvars = sorted(set(symbols('STT_OBJECT', filename)))

    if not funcs and not gvars:
        sys.exit(0)

    fmap = open(f'{libname}.map', 'w')
    fsrc = open(f'{libname}.c', 'w')

    for name, nid in funcs:
        print(tmpl_func.substitute(name=name, nid=nid), file=fsrc)
        print(tmpl_map.substitute(nid=nid, name=name), file=fmap)

    for name, nid in gvars:
        print(tmpl_obj.substitute(name=name, nid=nid), file=fsrc)
        print(tmpl_map.substitute(nid=nid, name=name), file=fmap)

    fmap.close()
    fsrc.close()
