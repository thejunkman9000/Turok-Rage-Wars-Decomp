#!/bin/bash
# dd.sh <file.c rel to workspace> : cpp + cc1 with all RTL dumps into ~/dd905/ (files a.i.<pass>)
rsync -a --exclude='_v_*' /mnt/d/Projects/ws/s905/wip/ ~/trw_s905/wip/
rsync -a /mnt/d/Projects/ws/s905/include/ ~/trw_s905/include/
D=~/dd905; rm -rf $D; mkdir -p $D
cd ~/trw_s905 && cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $1 > $D/a.i
cd $D && ~/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $EXTRA -dr -dj -ds -dL -dt -dc -dN -dS -dl -dg -dR -dJ -df a.i -o a.s 2>&1 | head -3
ls $D | tr '\n' ' '
