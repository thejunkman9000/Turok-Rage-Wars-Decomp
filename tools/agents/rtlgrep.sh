#!/usr/bin/env bash
# rtlgrep.sh <src.c> <dump letters> <suffix> <regex> <nth match> [before] [after]
src=$1; letters=$2; suf=$3; pat=$4; nth=${5:-1}; b=${6:-6}; a=${7:-30}
case "$src" in /*) ;; *) src=$HOME/trw_s901/$src;; esac
XF= bash /mnt/d/Projects/ws/s901/tools/dumpj.sh "$src" "$letters" >/dev/null
f=$(ls /tmp/dj901/zz.i.* | grep -E "\.$suf\$" | head -1)
python3 /mnt/d/Projects/ws/s901/tools/rtlc.py "$f" > /tmp/_rg.txt
n=$(grep -n -E "$pat" /tmp/_rg.txt | sed -n "${nth}p" | cut -d: -f1)
[ -z "$n" ] && { echo "no match"; exit 1; }
s=$((n-b)); [ $s -lt 1 ] && s=1
sed -n "${s},$((n+a))p" /tmp/_rg.txt | cut -c1-230
