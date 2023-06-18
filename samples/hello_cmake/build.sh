#!/usr/bin/env bash

if [[ -z "$PS5_PAYLOAD_SDK" ]]; then
    echo "error: PS5_PAYLOAD_SDK is undefined"
    exit 1
fi

cmake -B build -DCMAKE_TOOLCHAIN_FILE=$PS5_PAYLOAD_SDK/cmake/toolchain.cmake || exit 1
make  -C build || exit 1
