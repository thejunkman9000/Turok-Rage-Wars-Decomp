#!/usr/bin/env bash
# Compile one C file the way the original toolchain did (as best we know).
# usage: tools/cc.sh <lu|game> <in.c> <out.o>
#   lu   : libultra code  - gcc 2.8.1 -O2; jr $ra delay slot filled by the assembler (modern gas behaviour)
#   game : Acclaim's code - same compiler for now; `j $31` keeps a nop delay slot (old gas behaviour)
set -euo pipefail
mode=$1; in=$2; out=$3
ver=${GCC_VER:-2.8.1}
G=$PWD/tools/gcc/$ver
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT

"$G/gcc" -B"$G/" -meb -mips2 -mgp32 -mfp32 -G 0 -mno-abicalls -fno-pic -O2 \
    -I include -DINCLUDE_ASM_USE_MACRO_INC=1 -D_LANGUAGE_C -S -o "$tmp/o.s" "$in"

# the original assembler expanded `move` to addu rather than or
sed -E -i 's/^([[:space:]]*)move[[:space:]]+(\$[a-z0-9]+),[[:space:]]*(\$[a-z0-9]+)/\1addu\t\2,\3,$0/' "$tmp/o.s"
if [ "$mode" = game ]; then
  sed -E -i 's/^([[:space:]]*)j[[:space:]]+\$31[[:space:]]*$/\1.set\tnoreorder\n\1j\t$31\n\1nop\n\1.set\treorder/' "$tmp/o.s"
fi

bash tools/as.sh "$tmp/o.s" "$out"
