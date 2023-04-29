#!/bin/bash

export DESTDIR=$(mktemp -d)
trap 'rm -rf -- "$DESTDIR"' EXIT

CC=clang LD=ld.lld make clean install || exit 1
CC=gcc LD=ld make clean install || exit 1


SAMPLES=("hello_world"
	 "hello_stdio"
	 "hwinfo"
	 "klog"
	 "list_files"
	 "mntinfo"
	 "pipe_pirate"
	 "ps"
	 "remount")

export PS5_PAYLOAD_SDK=$DESTDIR
for SAMPLE in "${SAMPLES[@]}"; do
    CC=clang make LD=ld.lld -C samples/$SAMPLE clean all || exit 1
    CC=gcc LD=ld make -C samples/$SAMPLE clean all || exit 1
done

