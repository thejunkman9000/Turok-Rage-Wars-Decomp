#!/usr/bin/env bash
# rtlregion.sh <src.c (abs or rel to ~/trw_s901)> <dump letters> <suffix: jump|cse|combine|sched|lreg|greg|cse2|rtl> <regex> [before] [after]
# dumps with cc1_281 (@SN settings), condenses with rtlc.py and prints the lines around the first regex match
src=$1; letters=$2; suf=$3; pat=$4; b=${5:-6}; a=${6:-30}
case "$src" in /*) ;; *) src=$HOME/trw_s901/$src;; esac
XF= bash /mnt/d/Projects/ws/s901/tools/dumpj.sh "$src" "$letters" >/dev/null
f=$(ls /tmp/dj901/zz.i.* | grep -E "\.$suf\$" | head -1)
python3 /mnt/d/Projects/ws/s901/tools/rtlc.py "$f" > /tmp/_rr.txt
n=$(grep -n -E "$pat" /tmp/_rr.txt | head -1 | cut -d: -f1)
[ -z "$n" ] && { echo "no match"; exit 1; }
s=$((n-b)); [ $s -lt 1 ] && s=1
sed -n "${s},$((n+a))p" /tmp/_rr.txt | cut -c1-220
