#!/bin/bash
# around.sh <stage> <regex> <before> <after> : condensed RTL lines around the first match
cd ~/sndump_s806
python3 /mnt/d/Projects/ws/s806/tools/rtlc.py s.c.$1 0 100000 | cut -c1-${W:-170} | sed -E 's/ [0-9]+ [0-9]+ \(set/ (set/' | grep -v 'NOTE_INSN_DELETED' > /tmp/_around.txt
n=$(grep -n -E "$2" /tmp/_around.txt | head -1 | cut -d: -f1)
s=$((n-$3)); [ $s -lt 1 ] && s=1
sed -n "${s},$((n+$4))p" /tmp/_around.txt
