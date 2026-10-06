#!/usr/bin/env bash
# Compile a C file with several flag sets and print the instruction sequence of one function for each.
# usage: bash tools/flag_sweep.sh <file.c> <function>   (after wsl_build.sh so ~/trw exists)
cd ~/trw
f=$1; fn=$2
for opt in "-O2" "-O1" "-O3" "-O2 -fno-schedule-insns" "-O2 -fno-schedule-insns2" "-O2 -fno-delayed-branch" "-O2 -fno-gcse" "-O2 -fno-strength-reduce" "-O2 -fno-rerun-cse-after-loop" "-O2 -fno-force-mem" "-O2 -fforce-addr" "-O2 -mcpu=r4000" "-O2 -fno-thread-jumps" "-O2 -fomit-frame-pointer" "-O2 -fno-defer-pop"; do
  CC_OPT="$opt" bash tools/cc.sh lu "$f" /tmp/fs.o 2>/dev/null || { echo "[$opt] COMPILE FAIL"; continue; }
  seq=$(mips-linux-gnu-objdump -dz -M no-aliases,reg-names=numeric /tmp/fs.o | awk -v fn="<$fn>:" '$0 ~ fn {on=1;next} /^[0-9a-f]+ <.*>:/ {on=0} on && NF>=3 {printf "%s%s", $3, (NF>3?" ":""); if(NF>3) printf "%s", $4; printf " | "}' | cut -c1-230)
  printf "%-34s %s\n" "[$opt]" "$seq"
done
