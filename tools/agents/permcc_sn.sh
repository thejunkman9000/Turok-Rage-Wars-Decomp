#!/usr/bin/env bash
# permuter compile script for the @SN toolchain: permcc_sn.sh input.c -o output.o  (input already preprocessed). Env PERM_XF extra cc1 flags
set -euo pipefail
in=$1; out=$3
R=$HOME/trw_s703; SN=$HOME/sn
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT
"$SN/cc1_281" -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 ${PERM_XF:-} "$in" -o "$tmp/s.s"
"$SN/n64link" asn64 "$tmp/s.s" | grep -v "[.]include" > "$tmp/n.s"
cd "$R"
bash tools/as.sh "$tmp/n.s" "$out"
