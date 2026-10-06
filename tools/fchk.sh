#!/usr/bin/env bash
# Fast chk without the full project sync (only include/, src/, wip/ are refreshed).  Run inside WSL:
#   wsl -d Ubuntu-24.04 -- bash /mnt/d/Projects/TurokRageWars/tools/fchk.sh <listfile>     (or tools/fchk.ps1)
SRC=/mnt/d/Projects/TurokRageWars; DST=$HOME/trw
[ -d "$DST/tools/gcc" ] || bash "$SRC/tools/wsl_sync.sh"
mkdir -p "$DST/wip"
rsync -a "$SRC/include/" "$DST/include/"
rsync -a "$SRC/src/" "$DST/src/"
rsync -a --exclude='_v_*' "$SRC/wip/" "$DST/wip/"
cd "$SRC" && python3 tools/chk.py "$1" 2>&1
