#!/bin/bash
# dumpl.sh <src.c> [outdir] : cc1 (sn toolchain) with all RTL pass dumps; prints the dir.  Run in WSL (cwd ~/trw).
#   env LOW=1   : low code region options (-mcpu=r4000 -msplit-addresses);  env XF="-fno-builtin" : extra cc1 flags
cd "$HOME/trw" || exit 1
d=${2:-/tmp/dl}; rm -rf "$d"; mkdir -p "$d"
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their "$1" > "$d/t.i"
cpu=VR4300; sa=""; [ -n "$LOW" ] && { cpu=r4000; sa="-msplit-addresses"; }
cd "$d" && "$HOME/sn/cc1_281" -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=$cpu -mhard-float -mgp32 -mfp64 -mno-fix4300 $sa $XF -dr -ds -dg -dl -dS -dR -dj -dc -dL -df -dB -dt -dk t.i -o t.s 2>&1 | head -5
ls "$d"
