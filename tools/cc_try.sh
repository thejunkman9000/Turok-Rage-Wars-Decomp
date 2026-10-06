#!/usr/bin/env bash
# Usage: tools/cc_try.sh <gcc-version> <file.c> [extra flags]  -> disassembly of the compiled object
# Sources are copied to /tmp first (old cpp chokes on 64-bit inode numbers from /mnt/d).
set -e
V=$1; SRC=$2; shift 2
G=$PWD/tools/gcc/$V
cp "$SRC" /tmp/try_src.c
( cd /tmp && $G/gcc -B$G/ -meb -mips2 -mgp32 -mfp32 -G 0 -O2 -mno-abicalls -fno-pic "$@" -S -o /tmp/try.s try_src.c )
# old assembler expanded `move` to addu; modern gas emits or
sed -E -i 's/^([[:space:]]*)move[[:space:]]+(\$[a-z0-9]+),[[:space:]]*(\$[a-z0-9]+)/\1addu\t\2,\3,$0/' /tmp/try.s
# old gas left the delay slot of a return empty; modern gas pulls the sp adjust into it
sed -E -i 's/^([[:space:]]*)j[[:space:]]+\$31[[:space:]]*$/\1.set\tnoreorder\n\1j\t$31\n\1nop\n\1.set\treorder/' /tmp/try.s
mips-linux-gnu-as -EB -march=vr4300 -mabi=32 -mno-pdr -W -o /tmp/try.o /tmp/try.s
mips-linux-gnu-objdump -dz -M no-aliases,reg-names=numeric /tmp/try.o | sed -n '/<f/,$p' | cut -c1-80 | grep -v 'sll.*\$0,\$0,0x0$'
