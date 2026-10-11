#!/bin/bash
# rg.sh <pass> <regex> [n] : grep the condensed RTL of ~/dd905/a.i.<pass>
python3 /mnt/d/Projects/ws/s905/tools/rtlc.py ~/dd905/a.i.$1 0 100000 | cut -c1-${W:-200} | grep -v 'NOTE_INSN_DELETED' > ~/dd905/_g.txt
grep -n -E "$2" ~/dd905/_g.txt | head -${3:-60}
