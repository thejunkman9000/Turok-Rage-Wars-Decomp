#!/usr/bin/env bash
# Compile one preprocessed C file the way tools/cc.sh does for libultra (relocatable object, no rodata placement).
# For decomp-permuter: invoked as `permcc.sh input.c -o output.o`.   Env: PERM_FLAGS (gcc flags), PERM_MODE (lu|lu2|game)
set -euo pipefail
in=$1; out=$3
R=$HOME/trw
G=$R/tools/gcc/2.8.1
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT
"$G/gcc" -B"$G/" -meb -mips3 -mgp32 -G 0 -mno-abicalls -fno-pic ${PERM_FLAGS:--O3 -fforce-addr -fno-builtin -mcpu=r4300} \
    -D_LANGUAGE_C -S -o "$tmp/o.s" "$in"
python3 "$R/tools/gas_compat.py" "${PERM_MODE:-lu}" "$tmp/o.s"
cd "$R"
bash tools/as.sh "$tmp/o.s" "$out"
