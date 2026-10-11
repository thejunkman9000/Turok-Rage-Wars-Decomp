#!/bin/bash
# _q3.sh file.c : cpp + cc1 with rtl dumps in ~/dd_t/
D=~/dd_t; rm -rf $D; mkdir -p $D
cd /mnt/d/Projects/ws/s905 && cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $1 > $D/a.i
cd $D && ~/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -dr -dj -ds -dL -dg -dN a.i -o a.s 2>&1 | head -3
ls $D | tr '\n' ' '
