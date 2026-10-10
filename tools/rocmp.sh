#!/bin/bash
# rocmp.sh <src.c> : rodata of a ported file: (A) n64link --as pipeline (their object) vs (B) tools/cc.sh sn (ours), plus the ROM rodata at the ro= piece
SRC=$1
cd $HOME/trw
tmp=$(mktemp -d)
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $SRC > $tmp/s.i
$HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $tmp/s.i -o $tmp/s.s
$HOME/sn/n64link asn64 --as mips-linux-gnu-as -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3 $tmp/s.s -o $tmp/a.o 2>/dev/null
echo "== their object"; mips-linux-gnu-objdump -s -j .rdata $tmp/a.o | tail -n +4 | head -14
bash tools/cc.sh sn $SRC $tmp/b.o
echo "== ours"; mips-linux-gnu-objdump -s -j .rodata $tmp/b.o | tail -n +4 | head -14
