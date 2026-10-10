#!/bin/bash
# sndump.sh <src.c> <dumpflags e.g. -dg> : run cc1 with RTL dump flags in a tmp dir, print the dump files list
SRC=$1; FL=$2
cd $HOME/trw_s702
tmp=$HOME/sndump_s702; rm -rf $tmp; mkdir -p $tmp
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $SRC > $tmp/s.c
cd $tmp
$HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $FL s.c -o s.s
ls $tmp
