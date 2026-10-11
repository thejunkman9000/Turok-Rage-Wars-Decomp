#!/usr/bin/env bash
# sdf.sh <file.c> <fn> <rom hex> [tokens...] : FULL side-by-side (ours | ROM) to stdout (WSL)
cd /mnt/d/Projects/ws/s904
f=$1; fn=$2; rom=$3; shift 3
tok="${*:-@SN}"
cp "$f" $HOME/trw_s904/$f 2>/dev/null || { mkdir -p $HOME/trw_s904/$(dirname $f); cp "$f" $HOME/trw_s904/$f; }
rsync -a include/ $HOME/trw_s904/include/ 2>/dev/null
cd $HOME/trw_s904
python3 tools/side.py $f $fn $rom $tok 2>&1
