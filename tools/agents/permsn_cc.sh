#!/usr/bin/env bash
# permuter compile for @SN: permsn_cc.sh in.c -o out.elf   env: PS_VRAM (hex), PS_FLAGS (extra cc1 flags), PS_272=1 for gcc 2.7.2
set -uo pipefail
in=$1; out=$3
R=$HOME/trw_s702; SN=$HOME/sn; P=mips-linux-gnu
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT
if [ "${PS_272:-0}" = 1 ]; then cc="$SN/cc1_272 -quiet -G0 -mips3 -mgp32 -mfp32 -O2 ${PS_FLAGS:-}"
else cc="$SN/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 ${PS_FLAGS:-}"; fi
$cc "$in" -o "$tmp/o.s" || exit 1
python3 "$R/tools/sn_expand.py" "$tmp/o.s"
sed -i '/\.include .include\/\(labels\|macro\)\.inc/d' "$tmp/o.s"
$SN/n64link asn64 --as $P-as -I$R -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3 "$tmp/o.s" -o "$tmp/o.o" || exit 1
python3 "$R/tools/permsn_link.py" "$tmp/o.o" "$PS_VRAM" "$out" || exit 1
