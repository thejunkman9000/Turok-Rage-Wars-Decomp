#!/usr/bin/env bash
# lm.sh <file.c> [extra cc1 flags via EXTRA env] : loop.c movable log (Loop from.. / Insn.. lines) of a compile
f=$1
n=$(basename $f .c)
bash /mnt/d/Projects/ws/s904/tools/dump.sh $f /tmp/dd_s904_lm_$n >/dev/null 2>&1
grep -E "^Loop from|^Insn [0-9]+: regno" /tmp/dd_s904_lm_$n/a.i.loop | cut -c1-110
