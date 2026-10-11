#!/usr/bin/env bash
# usage (WSL): bash tools/prun903.sh <fn> <seconds> <jobs>   logs to ~/perm/s903_<fn>/run.log (own permuter copy ~/permuter_s903)
fn=$1; t=$2; j=${3:-3}
cd ~/permuter_s903 && timeout $t python3 permuter.py ~/perm/s903_$fn -j $j --stop-on-zero > ~/perm/s903_$fn/run.log 2>&1
