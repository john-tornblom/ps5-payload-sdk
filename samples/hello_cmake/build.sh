#!/usr/bin/env bash
SCRIPTDIR="${BASH_SOURCE[0]}"
SCRIPTDIR="$(dirname "${SCRIPTDIR}")"

cmake -B $SCRIPTDIR/build || exit 1
make  -C $SCRIPTDIR/build || exit 1
