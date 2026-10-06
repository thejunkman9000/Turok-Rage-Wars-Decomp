#!/bin/bash
# usage: wip/ck.sh fn1:rom1 fn2:rom2 ...   (files wip/c/<fn>.c)  -> runs chk
cd /mnt/d/Projects/ws/p2
rm -f wip/_list.txt
for a in "$@"; do f=${a%%:*}; r=${a##*:}; echo "wip/c/$f.c $f $r -O2 -mcpu=r4300" >> wip/_list.txt; done
python3 tools/chk.py wip/_list.txt 2>&1
