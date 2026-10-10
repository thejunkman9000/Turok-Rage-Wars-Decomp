#!/bin/bash
# snrel.sh <src.c> : compile with the sn pipeline, print sections and the relocations that are not against D_/func_ symbols
SRC=$1
cd $HOME/trw
tmp=$(mktemp -d)
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $SRC > $tmp/s.i
$HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $tmp/s.i -o $tmp/s.s
grep -n "rdata\|rodata\|\.LC\|\.word\|\$L" $tmp/s.s | head -${2:-12}
$HOME/sn/n64link asn64 --as mips-linux-gnu-as -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3 $tmp/s.s -o $tmp/s.o 2>/dev/null
mips-linux-gnu-readelf -SW $tmp/s.o | grep -E "text|rodata|data|bss"
mips-linux-gnu-readelf -rW $tmp/s.o | grep -v "D_\|func_" | head -12
