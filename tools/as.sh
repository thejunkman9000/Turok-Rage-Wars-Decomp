#!/usr/bin/env bash
# Assemble one .s the way our build needs it.
# usage: tools/as.sh <in.s> <out.o>
#
# Modern gas rounds a section's size up to its alignment (16 for .text/.rodata), which pads every object and shifts
# everything after it whenever a split point is not 16-byte aligned. Assemble into sections with default
# alignment 1 (.text.piece / .rodata.piece) and rename them back so the linker script (which maps .text and
# .rodata) still works.
set -euo pipefail
in=$1; out=$2
sed -E \
  -e 's/^([[:space:]]*)(\.section[[:space:]]+\.text([[:space:]]*,.*)?|\.text)[[:space:]]*$/\1.section .text.piece,"ax",@progbits/' \
  -e 's/^([[:space:]]*)\.section[[:space:]]+\.(rodata|rdata)([[:space:]]*,.*)?[[:space:]]*$/\1.section .rodata.piece,"a",@progbits/' \
  "$in" |
  mips-linux-gnu-as -EB -march=vr4300 -mabi=32 -mno-pdr -W -I include -I . -o "$out" -
mips-linux-gnu-objcopy \
  --rename-section .text.piece=.text,alloc,load,readonly,code,contents \
  --rename-section .rodata.piece=.rodata,alloc,load,readonly,data,contents \
  "$out"
