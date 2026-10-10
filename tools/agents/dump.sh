#!/bin/bash
# dump.sh <file.c> [outdir]  -> runs cc1 with -dr -ds -dg -dl -dS -dR into /tmp/dd_<name>/ ; prints dir
f=$1; n=$(basename $f .c); d=${2:-/tmp/dd_$n}
rm -rf $d; mkdir -p $d
cd ~/trw_s705 && cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $f > $d/a.i
cd $d && ~/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $EXTRA -dr -ds -dg -dl -dS -dR -dL a.i -o a.s 2>&1 | head -5
echo $d
