#!/usr/bin/env bash
# vbx.sh <fn> <rom hex> [--flags "@SN"] [--jobs N] [--top N] files... | --dir D | --file variants.txt   (WSL, ws root): sync include/ and the files, then run vb.py
SRC=/mnt/d/Projects/ws/s904; DST=$HOME/trw_s904
cd $SRC
rsync -a include/ $DST/include/ 2>/dev/null
rsync -a --exclude='_v_*' --exclude='vb/' wip/ $DST/wip/ 2>/dev/null
python3 tools/vb.py "$@" 2>&1 | grep -v SyntaxWarning
