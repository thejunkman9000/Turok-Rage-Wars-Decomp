#!/bin/bash
# rdsize.sh <func> [...] : object text size and function symbols of wip/rd/<func>.c compiled like the real build (mode from wip/rd/list.txt flags).  Run in WSL.
cd "$HOME/trw" || exit 1
cp /mnt/d/Projects/TurokRageWars/tools/rodoc.py tools/rodoc.py
rsync -a /mnt/d/Projects/TurokRageWars/wip/rd/ wip/rd/
rsync -a /mnt/d/Projects/TurokRageWars/include/ include/
for f in "$@"; do
  flags=$(grep " $f " /mnt/d/Projects/TurokRageWars/wip/rd/list.txt | cut -d' ' -f4-)
  m=sn
  case " $flags " in *" -fno-builtin "*) m=sn+nb;; esac
  echo "== $f ($m)"
  python3 tools/rodoc.py wip/rd/$f.c $m 0x0 0 2>&1 | head -3
done
