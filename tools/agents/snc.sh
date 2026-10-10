#!/usr/bin/env bash
# usage (WSL): bash tools/snc.sh file.c [cc1 flags]  -> normalised asm (n64link asn64 output)
f=$(readlink -f $1); shift
tmp=$(mktemp -d)
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I $HOME/trw_s706/include -I $HOME/trw_s706/include/their $f > $tmp/s.i
$HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 "$@" $tmp/s.i -o $tmp/s.s && $HOME/sn/n64link asn64 $tmp/s.s | grep -v '^\s*\.\(set\|file\|section\|align\|globl\|size\|type\|ent\|end\|frame\|mask\|fmask\|ident\)'
rm -rf $tmp
