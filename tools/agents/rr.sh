#!/bin/bash
# rr.sh <pass> [regex] [maxlines] : condensed RTL of ~/dd905/a.i.<pass> (rtlc), optionally filtered
f=~/dd905/a.i.$1
python3 /mnt/d/Projects/ws/s905/tools/rtlc.py $f 0 100000 | cut -c1-${W:-150} | grep -v 'NOTE_INSN_DELETED' > ~/dd905/_c.txt
if [ -n "$2" ]; then grep -n -E "$2" ~/dd905/_c.txt | head -${3:-60}; else head -${3:-100} ~/dd905/_c.txt; fi
