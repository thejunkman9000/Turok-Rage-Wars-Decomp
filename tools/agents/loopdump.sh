#!/usr/bin/env bash
# loopdump.sh <file.c> [281]  : run cc1 (2.7.2 default, 281 for 2.8.1 + extra flags in $XF) with -dL and print the loop dump's strength-reduce commentary
f=$1; v=${2:-272}
inc=$HOME/trw_s901/include
tmp=/tmp/ld901; rm -rf $tmp; mkdir -p $tmp; cp "$f" $tmp/x.c; cd $tmp
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I$inc -I$inc/their x.c > x.i
if [ "$v" = 281 ]; then
  $HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $XF -dL -dS -dR -dg -dl -dr -ds x.i -o x.s
else
  $HOME/sn/cc1_272 -quiet -G0 -mips3 -mgp32 -mfp32 -O2 $XF -dL -dS -dR -dg -dl -dr -ds x.i -o x.s
fi
ls $tmp
