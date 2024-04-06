#!/usr/bin/env bash
SCRIPTDIR="${BASH_SOURCE[0]}"
SCRIPTDIR="$(dirname "${SCRIPTDIR}")"

cd $SCRIPTDIR
rm -rf build
cmake -B build || exit 1
make  -C build || exit 1
