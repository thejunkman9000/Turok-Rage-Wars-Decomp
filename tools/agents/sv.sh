#!/bin/bash
# sv.sh <file.c rel ~/trw_s903 or ws> [extra cc1 flags]  : compile with all RTL dumps + sched verbose into ~/sv903/  (files s.c.<pass>)
f=$1; shift
rsync -a /mnt/d/Projects/ws/s903/wip/ ~/trw_s903/wip/ --exclude='_v_*' --exclude=vb --exclude=vp --exclude=mv
rsync -a /mnt/d/Projects/ws/s903/include/ ~/trw_s903/include/
tmp=$HOME/sv903; rm -rf $tmp; mkdir -p $tmp
cd ~/trw_s903
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $f > $tmp/s.c
cd $tmp
$HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -dr -ds -dg -dl -dS -dR -dL -fsched-verbose-5 "$@" s.c -o s.s 2>&1 | head -3
ls $tmp
