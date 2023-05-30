#!/bin/bash

export DESTDIR=$(mktemp -d)
trap 'rm -rf -- "$DESTDIR"' EXIT

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

CCLIST=("gcc"
	"clang")

LDLIST=("ld"
	"ld.lld")

export PS5_PAYLOAD_SDK=$DESTDIR

for CC in "${CCLIST[@]}"; do
    export CC
    for LD in "${LDLIST[@]}"; do
	export LD
	make clean install || exit 1
	for PS5_PAYLOAD_CC in "${CCLIST[@]}"; do
	    export PS5_PAYLOAD_CC
	    for PS5_PAYLOAD_LD in "${LDLIST[@]}"; do
		export PS5_PAYLOAD_LD
		for SAMPLE in "${SAMPLES[@]}"; do
		    make -C samples/$SAMPLE clean all || exit 1
		done
	    done
	done
    done
done
