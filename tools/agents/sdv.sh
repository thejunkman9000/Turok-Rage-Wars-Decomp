#!/bin/bash
# sdv.sh <n lines> file1.c file2.c ... : side-by-side head (FULL) of each variant vs func_00290A68 @SN
n=$1; shift
cd /mnt/d/Projects/ws/s902
for f in "$@"; do echo "== $f"; FULL=1 bash tools/sd.sh $f func_00290A68 0x91668 @SN 2>&1 | grep -v SyntaxWarning | head -$n; done
