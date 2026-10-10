#!/bin/bash
# sdorder.sh <file.c> [n] : print the sched1 result order (uid:dest<-src) for the first n insns using sndump
cd ~/trw_s702
bash tools/sndump.sh $1 "-dS -dL -fsched-verbose=5" >/dev/null 2>&1
cd ~/sndump_s702
python3 /mnt/d/Projects/ws/s702/tools/rtlc.py s.c.sched 4 400 | grep -E "^\(insn|jump_insn" | head -${2:-45} | sed -E 's/ [0-9]+ [0-9]+ \(set/ (set/' | cut -c1-110
