#!/usr/bin/env bash
# adf.sh <file.c rel ws> <fn> <rom hex> [@SN ...]   (WSL, from ws root)
# copies the file (+ include/) into ~/trw_s904 and prints the aligned diff (ad.py). env TAIL=1 -> only the summary line, HEAD=n -> first n lines.
SRC=/mnt/d/Projects/ws/s904; DST=$HOME/trw_s904
f=$1; fn=$2; rom=$3; shift 3
[ -n "$*" ] && X="$*" || X="@SN"
mkdir -p "$DST/$(dirname $f)"
cp "$SRC/$f" "$DST/$f"
rsync -a $SRC/include/ $DST/include/ 2>/dev/null
cd $SRC
if [ -n "$TAIL" ]; then python3 tools/ad.py $f $fn $rom $X 2>&1 | grep -v SyntaxWarning | tail -1
elif [ -n "$HEAD" ]; then python3 tools/ad.py $f $fn $rom $X 2>&1 | grep -v SyntaxWarning | head -$HEAD
else python3 tools/ad.py $f $fn $rom $X 2>&1 | grep -v SyntaxWarning; fi
