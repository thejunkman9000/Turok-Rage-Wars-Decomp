#!/bin/bash
# lifek.sh <file.c> <constant>: compile with loop dump, print loop.c decisions for the movable that loads <constant>
f=$1; k=$2
rsync -a /mnt/d/Projects/ws/s903/wip/ ~/trw_s903/wip/ --exclude=vb --exclude=vp --exclude=mv --exclude=ai >/dev/null 2>&1
rsync -a /mnt/d/Projects/ws/s903/include/ ~/trw_s903/include/ >/dev/null 2>&1
d=/tmp/lk_$$; mkdir -p $d; cd ~/trw_s903
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $f > $d/a.i
cd $d; ~/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $EXTRA -dL a.i -o a.s 2>&1 | head -3
grep -n "const = $k\|$k" a.i.loop | head -3
grep -E "Insn [0-9]+: regno [0-9]+ \(life [0-9]+\)" a.i.loop | grep -n "" | head -0
# print the movable lines near the one whose set insn mentions the constant: find reg number from the possible-biv line
r=$(grep -m1 "const = $k" a.i.loop | sed -E 's/.*reg ([0-9]+),.*/\1/')
echo "reg=$r"; grep -E "regno $r " a.i.loop
rm -rf $d
