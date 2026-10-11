#!/bin/bash
# kmov.sh <file.c> : compile with loop dump; print the movable lines of all 0x66666667 loads in the loop dump
f=$1
d=~/kd_$$
bash /mnt/d/Projects/ws/s903/tools/ldump.sh $f $d >/dev/null 2>&1
for r in $(grep -B1 '(const_int 1717986919)' $d/a.i.jump | grep -o '(reg:SI [0-9]*)' | grep -o '[0-9]*'); do
  echo "K reg=$r"
  grep -E "Insn [0-9]+: regno $r " $d/a.i.loop
done
grep -E "^Loop from" $d/a.i.loop | head -1
rm -rf $d
