#!/bin/bash
# rodoc_all.sh <func> ... : run the rodata doctor (tools/rodoc.py) on the newest EXACT worker result of each function.  Run in WSL: the cwd must be the Linux-side tree (~/trw).
cd "$HOME/trw" || exit 1
for f in "$@"; do
  res=""
  for r in /mnt/d/Projects/ws/*/wip/out/results.txt; do
    if grep -q "^$f .*EXACT" "$r" 2>/dev/null; then res=$r; fi
  done
  if [ -z "$res" ]; then echo "== $f: no EXACT result found"; continue; fi
  ws=${res%/wip/out/results.txt}
  echo "== $f ($ws)"
  python3 /mnt/d/Projects/TurokRageWars/tools/rodoc.py --results "$res" "$ws" "$f"
done
