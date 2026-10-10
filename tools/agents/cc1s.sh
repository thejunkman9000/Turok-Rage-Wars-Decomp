#!/bin/bash
# usage: cc1s.sh file.c [cc1 flags]  -> prints n64link-normalised asm of a standalone test file
f=$1; shift
tmp=$(mktemp -d)
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 $f > $tmp/s.i
$HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 "$@" $tmp/s.i -o $tmp/s.s
python3 /mnt/d/Projects/ws/s702/tools/sn_expand.py $tmp/s.s
$HOME/sn/n64link asn64 $tmp/s.s > $tmp/n.s
mips-linux-gnu-as -EB -march=vr4300 -mabi=32 -mips3 -o $tmp/o.o $tmp/n.s 2>/dev/null
mips-linux-gnu-objdump -d -M no-aliases --no-show-raw-insn $tmp/o.o | grep -E '^\s+[0-9a-f]+:' | sed 's/^ *[0-9a-f]*:\t//'
rm -rf $tmp
