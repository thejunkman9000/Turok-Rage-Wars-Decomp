#!/bin/bash
# winscan.sh <file rel wip> [step]: windowed (structural operand) scores over the whole ROM function
f=$1; step=${2:-100}
cd /mnt/d/Projects/ws/s902 && rsync -a wip/ ~/trw_s902/wip/ --exclude='_v_*' >/dev/null
cd ~/trw_s902
for lo in $(seq 0 $step 767); do
  hi=$((lo+step))
  r=$(python3 /mnt/d/Projects/ws/s902/wip/sh/vbw.py func_00418224 0x186224 --flags '@SN' --win $lo $hi --top 1 --jobs 1 $f 2>&1 | grep structural | sed 's/.*structural/structural/')
  echo "$lo-$hi $r"
done
