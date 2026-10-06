#!/usr/bin/env bash
# Print .text size/alignment of each built object (in ~/trw) next to the byte count of its source range.
cd ~/trw
for o in build/asm/BFEFC.o build/asm/C0398.o build/src/libultra/osViBlack.o build/src/libultra/osCreateMesgQueue.o; do
  echo "== $o"
  mips-linux-gnu-readelf -SW "$o" | grep -E '\.text|\.data|\.rodata' | sed -E 's/^ +\[ *[0-9]+\] +//'
done
echo "== asm/C0398.s (the 2-word padding chunk):"
grep -vE '^\s*(\.|$)' asm/C0398.s | head -8
echo "== tail of build/src/libultra/osCreateMesgQueue .s (gcc output):"
G=$PWD/tools/gcc/2.8.1; cd /tmp && cp ~/trw/src/libultra/osCreateMesgQueue.c t.c && $G/gcc -B$G/ -meb -mips2 -mgp32 -mfp32 -G 0 -mno-abicalls -fno-pic -O2 -I ~/trw/include -S -o t.s t.c && grep -nE 'align|\.end|\.size|text' t.s
