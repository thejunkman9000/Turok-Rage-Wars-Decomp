#!/bin/bash
# passes.sh file.c regex : for every dump pass, print matching condensed RTL lines
D=~/dd_p; rm -rf $D; mkdir -p $D
rsync -a /mnt/d/Projects/ws/s905/wip/ ~/trw_s905/wip/ 2>/dev/null
cd ~/trw_s905 && cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $1 > $D/a.i
cd $D && ~/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -dr -dj -ds -dL -dt -dc -dN -dS -dl -dg -dR -dJ -df a.i -o a.s 2>&1 | grep -v warning | head -3
for f in rtl jump cse loop cse2 flow combine sched lreg greg sched2 jump2; do
  [ -f $D/a.i.$f ] || continue
  echo "=== $f"
  python3 /mnt/d/Projects/ws/s905/tools/rtlc.py $D/a.i.$f 0 100000 | cut -c1-170 | grep -E "$2" | head -${3:-8}
done
