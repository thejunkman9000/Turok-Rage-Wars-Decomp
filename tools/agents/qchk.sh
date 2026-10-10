#!/usr/bin/env bash
# quick chk: refresh include/ + wip/ only.  usage (WSL): bash /mnt/d/Projects/ws/s704/tools/qchk.sh <listfile>
SRC=/mnt/d/Projects/ws/s704; DST=$HOME/trw_s704
rsync -a "$SRC/include/" "$DST/include/"
rsync -a --exclude='_v_*' "$SRC/wip/" "$DST/wip/"
cd "$SRC" && python3 tools/chk.py "$1" 2>&1 | grep -v SyntaxWarning
