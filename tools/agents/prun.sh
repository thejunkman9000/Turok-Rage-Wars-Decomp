#!/usr/bin/env bash
# usage in WSL: bash tools/prun.sh <fn> <seconds> <jobs> ; logs to ~/perm/<fn>/run.log
fn=$1; t=$2; j=$3
cd ~/permuter && timeout $t python3 permuter.py ~/perm/s702_$fn -j $j --stop-on-zero > ~/perm/s702_$fn/run.log 2>&1
