#!/usr/bin/env bash
# raw272.sh <file.c> [cc1 flags]  : preprocess and run cc1_272 (gcc 2.7.2) -O2, print raw asm.  RAW=281 uses cc1_281
f=$1; shift
inc=$HOME/trw_s901/include
tmp=$(mktemp -d)
cp "$f" $tmp/x.c
cd $tmp
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I$inc -I$inc/their x.c > x.i
if [ "$RAW" = 281 ]; then
  $HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 "$@" x.i -o x.s
else
  $HOME/sn/cc1_272 -quiet -G0 -mips3 -mgp32 -mfp32 -O2 "$@" x.i -o x.s
fi
cat x.s
rm -rf $tmp
