#!/bin/bash
# ldump.sh <file.c> <outdir> [extra cc1 flags]: compile with -dL -dS (loop + sched dumps) into <outdir>
f=$1; d=$2; shift 2
rsync -a /mnt/d/Projects/ws/s903/wip/ ~/trw_s903/wip/ --exclude=vb --exclude=vp --exclude=mv --exclude=ai >/dev/null 2>&1
rsync -a /mnt/d/Projects/ws/s903/include/ ~/trw_s903/include/ >/dev/null 2>&1
mkdir -p $d; cd ~/trw_s903
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $f > $d/a.i
cd $d; ~/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 "$@" -dL -dS -dR -dg -dj -dc -dl a.i -o a.s 2>&1 | head -3
ls $d
