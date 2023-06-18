#!/usr/bin/env bash
SCRIPTDIR="${BASH_SOURCE[0]}"
SCRIPTDIR="$(dirname "${SCRIPTDIR}")"

if [[ -z "$PS5_PAYLOAD_SDK" ]]; then
    echo "error: PS5_PAYLOAD_SDK is undefined"
    exit 1
fi

cmake -B $SCRIPTDIR/build \
      -DCMAKE_TOOLCHAIN_FILE=$PS5_PAYLOAD_SDK/cmake/toolchain.cmake \
      $SCRIPTDIR || exit 1
make  -C $SCRIPTDIR/build || exit 1
