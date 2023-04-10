#!/bin/bash

export DESTDIR=$(mktemp -d)
trap 'rm -rf -- "$DESTDIR"' EXIT

CC=gcc make clean install || exit 1
CC=clang make clean install || exit 1

SAMPLES=("hello_world"
	 "hwinfo"
	 "klog"
	 "list_files"
	 "mntinfo"
	 "pipe_pirate"
	 "ps"
	 "remount")

export PS5_PAYLOAD_SDK=$DESTDIR
for SAMPLE in "${SAMPLES[@]}"; do
    CC=gcc make -C samples/$SAMPLE clean all || exit 1
    CC=clang CFLAGS="-target " make -C samples/$SAMPLE clean all || exit 1
done

