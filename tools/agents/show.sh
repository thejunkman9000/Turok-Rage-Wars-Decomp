#!/bin/bash
# show.sh <stage> [from] [to] : condensed RTL lines from/to (line numbers of the condensed listing)
cd ~/sndump_s806
python3 /mnt/d/Projects/ws/s806/tools/rtlc.py s.c.$1 0 100000 | cut -c1-${W:-140} | sed -E 's/ [0-9]+ [0-9]+ \(set/ (set/' | grep -v 'NOTE_INSN_DELETED' | sed -n "${2:-1},${3:-80}p"
