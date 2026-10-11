#!/bin/bash
# dumpl.sh <src.c> [outdir] : cc1 (sn, low-region options -msplit-addresses -mcpu=r4000) with all RTL pass dumps; prints the dir.  Run in WSL (cwd ~/trw).
cd "$HOME/trw" || exit 1
d=${2:-/tmp/dl}; rm -rf "$d"; mkdir -p "$d"
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their "$1" > "$d/t.i"
cd "$d" && "$HOME/sn/cc1_281" -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=r4000 -mhard-float -mgp32 -mfp64 -mno-fix4300 -msplit-addresses -dr -ds -dg -dl -dS -dR -dj -dc -dL -df -dB -dt -dk t.i -o t.s 2>&1 | head -5
ls "$d"
