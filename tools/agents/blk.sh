#!/bin/bash
# blk.sh <file.c> <outdir> : compile with dumps (tools/ldump.sh) and condense sched/sched2/jump into <outdir>/*.txt
cd /mnt/d/Projects/ws/s903
bash tools/ldump.sh "$1" "$2" >/dev/null 2>&1
for n in sched sched2 jump combine loop greg lreg; do
  if [ -f $2/a.i.$n ]; then RTLC_W=5000 python3 tools/rtlc.py $2/a.i.$n > $2/$n.txt 2>/dev/null; fi
done
ls $2
