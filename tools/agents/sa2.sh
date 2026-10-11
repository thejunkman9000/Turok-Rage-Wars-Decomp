#!/bin/bash
# sa2.sh file.c : compile with the @SN toolchain; print the plain disassembly of .text (no relocs, no addresses)
f=$1; shift
SN=$HOME/sn; P=mips-linux-gnu
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT
cp "$f" $tmp/t.c
cd $tmp
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I $HOME/trw_s905/include -I $HOME/trw_s905/include/their t.c > t.i 2>/dev/null
$SN/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 "$@" t.i -o t.s 2>/dev/null || { echo COMPILE-FAIL; exit 1; }
grep -v '\.include' t.s > t2.s; mv t2.s t.s
$SN/n64link asn64 --as $P-as -I$HOME/trw_s905 -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3 t.s -o t.o >/dev/null 2>&1
$P-objdump -d t.o | grep -E '^\s+[0-9a-f]+:' | sed -e 's/^ *[0-9a-f]*:\t[0-9a-f ]*\t//'
