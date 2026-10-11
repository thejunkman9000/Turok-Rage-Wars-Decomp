#!/bin/bash
# pm.sh <pass> n1 n2 ... : first occurrences of pseudo numbers in the condensed RTL of ~/dd905/a.i.<pass>
p=$1; shift
python3 /mnt/d/Projects/ws/s905/tools/rtlc.py ~/dd905/a.i.$p 0 100000 | cut -c1-${W:-150} > ~/dd905/_pm.txt
for n in "$@"; do
  echo "== r$n"
  grep -m${M:-2} -E "[ (]r$n[ )]" ~/dd905/_pm.txt
done
