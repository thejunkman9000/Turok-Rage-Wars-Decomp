#!/bin/bash
# probe.sh <file.c> : dump rtl/jump/cse stages and report frame-address pseudos (set rN (plus $fp K)) surviving after the first jump pass,
#                    plus the final asm lines that mention s0/16(s0)  (for the func_00403658 inline-frame investigation)
f=$1
cd /mnt/d/Projects/ws/s902
rsync -a --exclude='_v_*' /mnt/d/Projects/ws/s902/wip/ ~/trw_s902/wip/ ; rsync -a /mnt/d/Projects/ws/s902/include/ ~/trw_s902/include/
cd ~/trw_s902
bash /mnt/d/Projects/ws/s902/tools/sndump.sh $f "-dr -dj -ds" >/dev/null 2>&1
cd ~/sndump_s902
echo "--- jump stage: frame-address pseudos"
python3 /mnt/d/Projects/ws/s902/tools/rtlc.py s.c.jump 0 100000 200 | grep -E "\(set r[0-9]+ \(plus:SI r30:fp" | head -20
echo "--- cse stage: frame-address pseudos"
python3 /mnt/d/Projects/ws/s902/tools/rtlc.py s.c.cse 0 100000 200 | grep -E "\(set r[0-9]+ \(plus:SI r30:fp" | head -20
echo "--- asm"
grep -n "s0\|16(" s.s | head -0
