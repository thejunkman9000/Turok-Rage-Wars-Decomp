#!/usr/bin/env bash
# dumpj.sh <file.c> <dump letters e.g. jrscgld>   -> /tmp/dj901/zz.i.<pass> (cc1_281, @SN settings; extra flags in $XF)
f=$1; letters=${2:-jrsc}
inc=$HOME/trw_s901/include
d=/tmp/dj901; rm -rf $d; mkdir -p $d; cp "$f" $d/zz.c; cd $d
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I$inc -I$inc/their zz.c > zz.i
flags=""; for ((k=0; k<${#letters}; k++)); do flags="$flags -d${letters:$k:1}"; done
$HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $XF $flags zz.i -o zz.s
ls $d
