#!/bin/bash
cd $HOME/trw
tmp=$(mktemp -d)
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $1 > $tmp/s.i
$HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $tmp/s.i -o $tmp/s.s
$HOME/sn/n64link asn64 $tmp/s.s > $tmp/n.s
python3 /mnt/d/Projects/TurokRageWars/tools/snabs_dbg2.py $tmp/n.s
