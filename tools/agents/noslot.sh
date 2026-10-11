#!/bin/bash
# noslot.sh <file.c> [N] [extra cc1 flags] : asm head of the function with delay-slot filling disabled (pre-reorg order)
f=$1; n=${2:-40}; shift 2
rsync -a --exclude='_v_*' /mnt/d/Projects/ws/s902/wip/ ~/trw_s902/wip/
cd ~/trw_s902
bash /mnt/d/Projects/ws/s902/tools/sndump.sh $f "-fno-delayed-branch $*" >/dev/null 2>&1
grep -v '^\s*\.\(set\|align\|ent\|end\|frame\|mask\|fmask\|globl\|type\|size\|file\|section\|text\|rdata\|ident\|option\)' ~/sndump_s902/s.s | grep -v '^\s*#' | grep -n . | sed -n "1,${n}p"
