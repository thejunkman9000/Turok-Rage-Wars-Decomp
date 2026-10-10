#!/bin/bash
# cmp4.sh <file.c> <regex> <stage list...> : dump all stages, print matching lines for the given stages
f=$1; re=$2; shift 2
bash /mnt/d/Projects/ws/s806/wip/sh/dumpall.sh $f
cd ~/sndump_s806
for s in "$@"; do
  echo "== $s"
  python3 /mnt/d/Projects/ws/s806/tools/rtlc.py s.c.$s 0 100000 | cut -c1-${W:-170} | sed -E 's/ [0-9]+ [0-9]+ \(set/ (set/' | grep -v NOTE_INSN_DELETED | grep -n -E "$re" | head -${N:-14}
done
