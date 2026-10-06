#!/usr/bin/env bash
# Print one function's instructions for each gcc version (libultra flags). usage: bash tools/ver_tail.sh <file.c> [flags]
cd ~/trw
f=$1; shift
flags=${*:--O2 -fforce-addr -fno-builtin}
for v in 2.7.2 2.7.2.3 2.8.1 2.91.66 2.95.2; do
  GCC_VER=$v CC_OPT="$flags" bash tools/cc.sh lu "$f" /tmp/vt.o 2>/dev/null || { echo "[$v] FAIL"; continue; }
  printf "[%-7s] " "$v"
  mips-linux-gnu-objdump -dz -M no-aliases,reg-names=numeric /tmp/vt.o | awk 'NF>=3 && $1 ~ /:$/ && !/sll.*\$0,\$0,0x0/ {printf "%s %s | ", $3, $4}'
  echo
done
