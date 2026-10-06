#!/usr/bin/env bash
# Show raw gcc output lines matching a pattern, for a source file in ~/trw with extra -D flags.
# usage: bash tools/gcc_raw.sh <file.c> <egrep pattern> [-DFOO=1 ...]
cd ~/trw
f=$1; pat=$2; shift 2
G=$PWD/tools/gcc/2.8.1
cp "$f" /tmp/raw_in.c
( cd /tmp && $G/gcc -B$G/ -meb -mips3 -mgp32 -G 0 -mno-abicalls -fno-pic -O3 -fforce-addr -fno-builtin -mcpu=r4300 \
    -I ~/trw/include -DINCLUDE_ASM_USE_MACRO_INC=1 "$@" -S -o /tmp/raw_out.s raw_in.c )
grep -n -B2 -A2 -E "$pat" /tmp/raw_out.s
