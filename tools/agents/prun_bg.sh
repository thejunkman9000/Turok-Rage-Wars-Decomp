#!/usr/bin/env bash
# prun_bg.sh <fn> <secs> <jobs> : run the private permuter copy on ~/perm/s904_<fn> (stop on zero), log to run.log
fn=$1; t=$2; j=$3
cd ~/permuter_s904 && timeout $t python3 permuter.py ~/perm/s904_$fn -j $j --stop-on-zero > ~/perm/s904_$fn/run.log 2>&1
echo "permuter finished $(date)" >> ~/perm/s904_$fn/run.log
