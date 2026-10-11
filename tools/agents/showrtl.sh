#!/usr/bin/env bash
# showrtl.sh <dumpfile> <pattern> [before] [after] : print condensed RTL (rtlc.py) lines around the first match of a regex
f=$1; pat=$2; b=${3:-6}; a=${4:-40}
python3 /mnt/d/Projects/ws/s901/tools/rtlc.py "$f" > /tmp/_showrtl.txt
n=$(grep -n -E "$pat" /tmp/_showrtl.txt | head -1 | cut -d: -f1)
[ -z "$n" ] && { echo "no match"; exit 1; }
s=$((n-b)); [ $s -lt 1 ] && s=1
sed -n "${s},$((n+a))p" /tmp/_showrtl.txt | cut -c1-200
