#!/usr/bin/env bash
# Compile one C file the way the original toolchain did (as best we know).
# usage: tools/cc.sh <lu|game> <in.c> <out.o>
#   lu   : libultra code  - gcc 2.8.1 -O2 -fforce-addr -fno-builtin; jr $ra delay slot filled by the assembler (modern gas behaviour)
#   game : Acclaim's code - same compiler for now; `j $31` keeps a nop delay slot (old gas behaviour)
set -euo pipefail
mode=$1; in=$2; out=$3
# per-file override (mode_map.txt, generated from funcs.txt `mode=` tokens)
if [ -f mode_map.txt ]; then
  ov=$(awk -v n="$(basename "$in" .c)" '$1==n {print $2}' mode_map.txt)
  [ -n "$ov" ] && mode=$ov
fi
ver=${GCC_VER:-2.8.1}
G=$PWD/tools/gcc/$ver
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT

"$G/gcc" -B"$G/" -meb ${CC_ISA:--mips3 -mgp32} -G 0 -mno-abicalls -fno-pic ${CC_OPT:-$(case "$mode" in lu) echo "-O3 -fforce-addr -fno-builtin -mcpu=r4300";; lu2) echo "-O2 -fforce-addr -fno-builtin -mcpu=r4300";; *) echo -O2;; esac)} \
    -I include -DINCLUDE_ASM_USE_MACRO_INC=1 -D_LANGUAGE_C -S -o "$tmp/o.s" "$in"

# reproduce the original assembler's output (move -> addu, div/rem expansion, return delay slot)
base=$(basename "$in" .c)
ro_va=""
if [ -f rodata_map.txt ]; then
  off=$(awk -v n="$base" '$1==n {print $2}' rodata_map.txt)
  # the main image's data is addressed through KSEG0: VA = 0x80000000 + (ROM - 0xC00)
  [ -n "$off" ] && ro_va=$(printf '0x%X' $(( 0x80000000 + off - 0xC00 )))
  ro_size=$(awk -v n="$base" '$1==n {print $3}' rodata_map.txt)
fi
python3 tools/gas_compat.py "$mode" "$tmp/o.s" $ro_va ${ro_size:-}

bash tools/as.sh "$tmp/o.s" "$out"
