#!/bin/bash
# lregs.sh <file.c>  : dump + print allocation order, dispositions and per-pseudo stats (first 14)
f=$1; n=$(basename $f .c)
bash /mnt/d/Projects/ws/s705/tools/dump.sh $f >/dev/null
d=/tmp/dd_$n
sed -n 3p $d/a.i.greg | cut -c1-400
grep -A12 "Register dispositions" $d/a.i.greg | head -14
grep -E "^Register [0-9]+ used" $d/a.i.lreg | head -${2:-30}
