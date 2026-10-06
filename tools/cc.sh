#!/usr/bin/env bash
# Compile one C file the way the original toolchain did (as best we know).
# usage: tools/cc.sh <lu|game> <in.c> <out.o>
#   lu   : libultra code  - gcc 2.8.1 -O2 -fforce-addr -fno-builtin; jr $ra delay slot filled by the assembler (modern gas behaviour)
#   game : Acclaim's code - same compiler for now; `j $31` keeps a nop delay slot (old gas behaviour)
set -euo pipefail
mode=$1; in=$2; out=$3
ver=${GCC_VER:-2.8.1}
G=$PWD/tools/gcc/$ver
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT

"$G/gcc" -B"$G/" -meb -mips2 -mgp32 -mfp32 -G 0 -mno-abicalls -fno-pic ${CC_OPT:-$([ "$mode" = lu ] && echo "-O2 -fforce-addr -fno-builtin -mcpu=r4300" || echo -O2)} \
    -I include -DINCLUDE_ASM_USE_MACRO_INC=1 -D_LANGUAGE_C -S -o "$tmp/o.s" "$in"

# reproduce the original assembler's output (move -> addu, div/rem expansion, return delay slot)
python3 tools/gas_compat.py "$mode" "$tmp/o.s"

bash tools/as.sh "$tmp/o.s" "$out"
