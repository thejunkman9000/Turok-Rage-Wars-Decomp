#!/bin/bash
# grepst.sh <stage> <pattern> : condensed lines matching pattern with their index
cd ~/sndump_s806
python3 /mnt/d/Projects/ws/s806/tools/rtlc.py s.c.$1 0 100000 | cut -c1-${W:-150} | sed -E 's/ [0-9]+ [0-9]+ \(set/ (set/' | grep -v 'NOTE_INSN_DELETED' | grep -n -E "$2" | head -${N:-30}
