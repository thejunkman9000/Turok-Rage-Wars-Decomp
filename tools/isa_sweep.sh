#!/usr/bin/env bash
# Try ISA/FP option combinations for a float function; print the float registers used and whether it compiles.
# usage: bash tools/isa_sweep.sh <file.c>   (run after wsl_sync.sh)
cd ~/trw
f=$1
for isa in "-mips2 -mgp32 -mfp32" "-mips2 -mgp32 -mfp64" "-mips3 -mgp32" "-mips3 -mgp32 -mfp64" "-mips3 -mgp32 -mfp32" "-mips2 -mgp32" "-mips1 -mgp32 -mfp64" "-mips4 -mgp32" "-mips3" "-mips2 -mfp64"; do
  for v in 2.8.1 2.7.2 2.95.2; do
    cp "$f" /tmp/is.c
    out=$(cd /tmp && ~/trw/tools/gcc/$v/gcc -B$HOME/trw/tools/gcc/$v/ -meb $isa -G 0 -mno-abicalls -fno-pic -O2 -fforce-addr -fno-builtin -mcpu=r4300 -I ~/trw/include -DINCLUDE_ASM_USE_MACRO_INC=1 -S -o /tmp/is.s is.c 2>&1 | head -1)
    if [ -n "$out" ]; then printf "%-26s %-7s ERR %s\n" "$isa" "$v" "$(echo $out | cut -c1-60)"; continue; fi
    regs=$(grep -o '\$f[0-9]*' /tmp/is.s | sort -u | tr '\n' ' ')
    printf "%-26s %-7s ok  %s\n" "$isa" "$v" "$regs"
  done
done
