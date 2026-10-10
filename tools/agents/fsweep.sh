#!/usr/bin/env bash
# fsweep.sh <file.c rel> <fn> <rom hex> <n> : try single cc1 flags (WSL); prints struct/full metric per flag
f=$1; fn=$2; rom=$3; n=$4
cd ~/trw_s704
for fl in "" -fno-expensive-optimizations -fno-cse-follow-jumps -fno-cse-skip-blocks -fno-rerun-cse-after-loop -fno-schedule-insns -fno-schedule-insns2 -fno-strength-reduce -fno-thread-jumps -fno-defer-pop -fno-delayed-branch -fno-peephole -fno-force-mem -fno-caller-saves -fno-regmove -fno-optimize-register-move -fno-inline -fno-gcse -fno-move-all-movables -fno-reduce-all-givs -fno-unroll-loops -fno-merge-constants -fno-function-cse -fomit-frame-pointer -fno-omit-frame-pointer -ffast-math -fno-trapping-math -fno-peephole2 -fforce-mem -fno-jump-opt; do
  echo -n "$fl: "
  python3 /mnt/d/Projects/ws/s704/tools/vf.py $fn $rom $n "-fno-builtin $fl" $f 2>&1 | head -1
done
