#!/bin/bash
# usage: tools/pstart.sh <fn> <workfile> <rom> <ninsns> <secs> <jobs> [flags]
cd /d/Projects/ws/s705
fn=$1; w=$2; rom=$3; n=$4; t=$5; j=$6; shift 6
powershell -NoProfile -File tools/ps.ps1 "bash tools/perm_sn.sh $fn $w $rom $n $*" 2>&1 | tail -1
powershell -NoProfile -File tools/pbg.ps1 $fn $t $j
