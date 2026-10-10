#!/bin/bash
# cmp3.sh <file.c> <regex> : dump all stages, print matching condensed lines of sched, greg, sched2
bash /mnt/d/Projects/ws/s806/wip/sh/dumpall.sh $1
cd ~/sndump_s806
for s in sched greg sched2; do
  echo "== $s"
  python3 /mnt/d/Projects/ws/s806/tools/rtlc.py s.c.$s 0 100000 | cut -c${C1:-1}-${C2:-170} | sed -E 's/ [0-9]+ [0-9]+ \(set/ (set/' | grep -v NOTE_INSN_DELETED | grep -n -E "$2" | head -${N:-14}
done
