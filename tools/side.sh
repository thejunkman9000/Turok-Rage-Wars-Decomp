#!/bin/bash
# side.sh <src.c under the project> <mode> <fn> <rom hex> <n> [lo hi] : sync the tree pieces and run tools/side.py in ~/trw.  Run in WSL.
cd "$HOME/trw" || exit 1
rsync -a /mnt/d/Projects/TurokRageWars/include/ include/
rsync -a /mnt/d/Projects/TurokRageWars/wip/lo/ wip/lo/
cp /mnt/d/Projects/TurokRageWars/tools/side.py tools/side.py
python3 tools/side.py "$@"
