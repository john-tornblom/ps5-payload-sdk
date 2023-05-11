#!/bin/bash

export DESTDIR=$(mktemp -d)
trap 'rm -rf -- "$DESTDIR"' EXIT

make clean install || exit 1

SAMPLES=("hello_sprx"
	 "hello_stdio"
	 "hello_world"
	 "hwinfo"
	 "klog"
	 "list_files"
	 "mntinfo"
	 "pipe_pirate"
	 "ps"
	 "remount")

export PS5_PAYLOAD_SDK=$DESTDIR
for SAMPLE in "${SAMPLES[@]}"; do
    make CC=gcc   LD=ld     -C samples/$SAMPLE clean all || exit 1
    make CC=gcc   LD=ld.lld -C samples/$SAMPLE clean all || exit 1
    make CC=clang LD=ld     -C samples/$SAMPLE clean all || exit 1
    make CC=clang LD=ld.lld -C samples/$SAMPLE clean all || exit 1
done
