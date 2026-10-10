#!/bin/bash
# sizecheck.sh : for every mode=sn manifest entry compare the object's .text size with 4*insns (extra helper functions in a ported file inflate it)
cd ~/trw
for m in funcs.txt funcs_a.txt; do
  grep -E "mode=sn" /mnt/d/Projects/TurokRageWars/$m | while read name rom insns sub rest; do
    o=build/src/$sub/$name.o
    [ -f $o ] || continue
    sz=$(mips-linux-gnu-readelf -SW $o | awk '$2==".text" {print strtonum("0x"$6)}')
    [ "$sz" != "$((insns*4))" ] && echo "$name manifest=$((insns*4)) object=$sz"
  done
done
