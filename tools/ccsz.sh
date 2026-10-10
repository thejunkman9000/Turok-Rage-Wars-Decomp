#!/bin/bash
# ccsz.sh <mode> <src.c> : build one object with tools/cc.sh in ~/trw and print its section sizes
cd $HOME/trw
bash tools/cc.sh $1 $2 /tmp/ccsz.o && mips-linux-gnu-readelf -SW /tmp/ccsz.o | grep -E "text|rodata|data" ; mips-linux-gnu-objdump -s -j .rodata /tmp/ccsz.o | head -12
