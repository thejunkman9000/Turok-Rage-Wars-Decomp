#!/usr/bin/env bash
# adx.sh <file.c> <fn> <rom> [tokens] : sync file then aligned diff
cd /mnt/d/Projects/ws/s702
echo "$1 $2 $3 ${4:-@SN}" > wip/_adx_l.txt
bash tools/fk.sh wip/_adx_l.txt > /dev/null 2>&1
python3 tools/ad.py "$@" 2>&1 | grep -v SyntaxWarning
