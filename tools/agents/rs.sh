#!/bin/bash
# rs.sh <stage> [from] [to]  : condensed RTL of ~/sndump_s902/s.c.<stage> one insn per line (W=width)
cd ~/sndump_s902
python3 /mnt/d/Projects/ws/s902/tools/rtlc.py s.c.$1 0 100000 ${W:-180} | grep -v 'NOTE_INSN_DELETED' | sed -n "${2:-1},${3:-200}p"
