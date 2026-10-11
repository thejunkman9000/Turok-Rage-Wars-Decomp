#!/usr/bin/env bash
# fsweep_sn.sh <file.c rel ws> <fn> <rom hex> <n> : single extra cc1 flags under @SN via wvb.py (WSL)
f=$1; fn=$2; rom=$3; n=$4
cd /mnt/d/Projects/ws/s901
rsync -a --exclude='_v_*' wip/ ~/trw_s901/wip/ >/dev/null
for fl in "" -fno-expensive-optimizations -fno-cse-follow-jumps -fno-cse-skip-blocks -fno-rerun-cse-after-loop -fno-schedule-insns -fno-schedule-insns2 -fno-strength-reduce -fno-thread-jumps -fno-defer-pop -fno-delayed-branch -fno-peephole -fno-force-mem -fno-caller-saves -fno-function-cse -fomit-frame-pointer -fno-gcse -fno-crossjumping -fno-optimize-register-move -fforce-mem -fforce-addr -fcaller-saves -fno-jump-opt -fno-inline -fno-unroll-loops; do
  echo -n "[$fl] "
  python3 tools/wvb.py $fn $rom $n --flags "@SN $fl" --jobs 1 --top 1 $f 2>&1 | grep -v Warn | head -1
done
