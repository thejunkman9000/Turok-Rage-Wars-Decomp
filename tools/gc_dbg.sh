#!/usr/bin/env bash
# Debug gas_compat: show raw gcc .s for a source file and the result after gas_compat (lu mode).
cd ~/trw
G=$PWD/tools/gcc/2.8.1
cp "$1" /tmp/gd.c
$G/gcc -B$G/ -meb -mips2 -mgp32 -mfp32 -G 0 -mno-abicalls -fno-pic -O2 -fforce-addr -fno-builtin -I include -DINCLUDE_ASM_USE_MACRO_INC=1 -D_LANGUAGE_C -S -o /tmp/gd.s /tmp/gd.c
echo "=== raw"; grep -vE '^\s*(\.(file|ident|section|align|globl|type|size|text|ent|end|frame|mask|fmask)|#)|^\s*$' /tmp/gd.s | head -${2:-30}
cp /tmp/gd.s /tmp/gd2.s; python3 tools/gas_compat.py lu /tmp/gd2.s
echo "=== after gas_compat"; grep -vE '^\s*(\.(file|ident|section|align|globl|type|size|text|ent|end|frame|mask|fmask)|#)|^\s*$' /tmp/gd2.s | head -${2:-30}
