#!/usr/bin/env bash
# Compile one C file the way the original toolchain did (as best we know).
# usage: tools/cc.sh <lu|game> <in.c> <out.o>
#   lu   : libultra code  - gcc 2.8.1 -O2 -fforce-addr -fno-builtin; jr $ra delay slot filled by the assembler (modern gas behaviour)
#   lu3  : like lu2 but without -fforce-addr -fno-builtin (the debug-link code)
#   game : Acclaim's code - same compiler for now; `j $31` keeps a nop delay slot (old gas behaviour)
set -euo pipefail
mode=$1; in=$2; out=$3
# per-file override (mode_map.txt, generated from funcs.txt `mode=` tokens)
if [ -f mode_map.txt ]; then
  ov=$(awk -v n="$(basename "$in" .c)" '$1==n {print $2}' mode_map.txt)
  [ -n "$ov" ] && mode=$ov
fi
# mode may carry per-function build flags:  lu3+nb+ntj+nf+luret+o2   (nb = -fno-builtin, ntj = -fno-thread-jumps,
# nf = old assembler never fills the return slot after a block move, luret = bare `j $31` keeps its nop, o2 = no -mcpu=r4300)
spec=$mode; mode=${spec%%+*}; toks="+${spec#*+}"; [ "$spec" = "$mode" ] && toks=""
[ "$mode" = game ] && mode=lu3   # Acclaim game code: -O2 -mcpu=r4300, same assembler behaviour as libultra
ver=${GCC_VER:-2.8.1}
G=$PWD/tools/gcc/$ver
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT

xflags=""; gasmode=$mode
case "$toks" in *+nb*) xflags="$xflags -fno-builtin";; esac
case "$toks" in *+ntj*) xflags="$xflags -fno-thread-jumps";; esac
case "$toks" in *+luret*) gasmode=game;; esac
export GAS_NOFILL=0; case "$toks" in *+nf*) export GAS_NOFILL=1;; esac
case "$toks" in *+inl*) export GAS_INLINE=1;; esac   # li.s/li.d literals emitted at the point of use (csplayer, seqplayer)
export GAS_MULTFIX=1   # original toolchain never fills a branch delay slot with mult/div
"$G/gcc" -B"$G/" -meb ${CC_ISA:--mips3 -mgp32} -G 0 -mno-abicalls -fno-pic $xflags ${CC_OPT:-$(case "$mode" in lu) echo "-O3 -fforce-addr -fno-builtin -mcpu=r4300";; lu2) echo "-O2 -fforce-addr -fno-builtin -mcpu=r4300";; lu3) case "$toks" in *+o2*) echo "-O2";; *) echo "-O2 -mcpu=r4300";; esac;; lu4) echo "-O2 -msplit-addresses -mcpu=r4300 -mfp32";; *) echo -O2;; esac)} \
    -I include -DINCLUDE_ASM_USE_MACRO_INC=1 -D_LANGUAGE_C -S -o "$tmp/o.s" "$in" \
    || { [ -s "$tmp/o.s" ] || exit 1; echo "cc.sh: gcc reported errors for $in, using its output anyway (as tools/chk.py does)" >&2; }

# reproduce the original assembler's output (move -> addu, div/rem expansion, return delay slot)
base=$(basename "$in" .c)
ro_va=""
if [ -f rodata_map.txt ]; then
  off=$(awk -v n="$base" '$1==n {print $2}' rodata_map.txt)
  # the main image's data is addressed through KSEG0: VA = 0x80000000 + (ROM - 0xC00)
  if [ -n "$off" ]; then
    if [ $(( off )) -ge $(( 0x16E000 )) ]; then ro_va=$(printf '0x%X' $(( 0x400000 + off - 0x16E000 )))   # overlay A (VRAM 0x400000 = ROM 0x16E000)
    else ro_va=$(printf '0x%X' $(( 0x80000000 + off - 0xC00 ))); fi
  fi
  ro_size=$(awk -v n="$base" '$1==n {print $3}' rodata_map.txt)
  ro_real=$(awk -v n="$base" '$1==n {print $4}' rodata_map.txt)   # data proper, when the piece is larger (alignment tail comes from the ROM)
fi
case "$in" in src/game/*|src/ovl_a/*) export GAS_RO4=1;; esac
python3 tools/gas_compat.py "$gasmode" "$tmp/o.s" $ro_va ${ro_size:-} ${ro_real:-}

bash tools/as.sh "$tmp/o.s" "$out"

