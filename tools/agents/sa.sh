#!/bin/bash
# sa.sh file.c : compile with the @SN toolchain (cc1 + asn64) and print the disassembly of .text
f=$1; shift
SN=$HOME/sn; P=mips-linux-gnu
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT
cp "$f" $tmp/t.c
cd $tmp
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I $HOME/trw_s703/include -I $HOME/trw_s703/include/their t.c > t.i
$SN/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 "$@" t.i -o t.s || exit 1
grep -v '\.include' t.s > t2.s; mv t2.s t.s
if [ -n "$RAW" ]; then cat t.s; exit 0; fi
$SN/n64link asn64 --as $P-as -I$HOME/trw_s703 -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3 t.s -o t.o 2>&1 | head -5
$P-objdump -dr t.o | grep -v "^$" | sed -e 's/^ *[0-9a-f]*:\t[0-9a-f ]*\t//' | head -${HEADN:-200}
