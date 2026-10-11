#!/bin/bash
# sdiff.sh <src.c> <mode> <fn> <rom hex> <n> : like side.sh but prints only the differing instruction blocks (difflib alignment, so inserted/missing insns do not shift the rest).  Run in WSL.
cd "$HOME/trw" || exit 1
rsync -a /mnt/d/Projects/TurokRageWars/include/ include/
rsync -a /mnt/d/Projects/TurokRageWars/wip/lo/ wip/lo/
cp /mnt/d/Projects/TurokRageWars/tools/sdiff.py tools/sdiff.py
python3 tools/sdiff.py "$@"
