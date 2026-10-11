#!/bin/bash
# objsize.sh <src.c> <mode> : compile like the real build and print the section table (text size in bytes) and the function symbols.  Run in WSL.
cd "$HOME/trw" || exit 1
rsync -a /mnt/d/Projects/TurokRageWars/wip/rd/ wip/rd/
rsync -a /mnt/d/Projects/TurokRageWars/include/ include/
bash tools/cc.sh "${2:-sn}" "$1" /tmp/objsize.o 2>&1 | grep -v warning
mips-linux-gnu-readelf -SW /tmp/objsize.o | grep -E "text|rodata"
mips-linux-gnu-objdump -d /tmp/objsize.o | tail -8
