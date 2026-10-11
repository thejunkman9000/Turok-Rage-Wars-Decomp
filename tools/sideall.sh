#!/bin/bash
# sideall.sh <fn> <rom hex> <n> <mode> file...: differing-word count of each file (tools/side.py), one line per file.  Run in WSL.
cd "$HOME/trw" || exit 1
rsync -a /mnt/d/Projects/TurokRageWars/include/ include/
rsync -a /mnt/d/Projects/TurokRageWars/wip/lo/ wip/lo/
cp /mnt/d/Projects/TurokRageWars/tools/side.py tools/side.py
fn=$1; rom=$2; n=$3; mode=$4; shift 4
for f in "$@"; do
  r=$(python3 tools/side.py "$f" "$mode" "$fn" "$rom" "$n" 0 0 2>&1 | tail -1)
  echo "$f: $r"
done
