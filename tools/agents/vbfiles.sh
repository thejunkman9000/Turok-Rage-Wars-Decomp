#!/usr/bin/env bash
# vbfiles.sh <fn> <rom> <glob> [--top N]  : rank all files matching the glob (relative to ws root) with vb.py
fn=$1; rom=$2; g=$3; shift 3
cd /mnt/d/Projects/ws/s904
files=$(ls $g)
bash tools/vbx.sh $fn $rom --jobs 3 "$@" $files
