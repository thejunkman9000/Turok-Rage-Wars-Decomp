#!/usr/bin/env bash
# Show bytes around the first mismatch and the ovl_a section sizes from the map.
OFF=${1:-0x1BCD80}
echo "== built   @ $OFF"; xxd -s $((OFF)) -l 48 build/turok_ragewars.z64
echo "== original@ $OFF"; xxd -s $((OFF)) -l 48 baserom.us.v11.z64
echo "== map: ovl_a pieces"
grep -E "^ \.(text|data|rodata|bss)|16E000.o|ovl_a_tail" build/turok_ragewars.map | head -12
echo "== sizes"
mips-linux-gnu-size -A build/asm/16E000.o | head -8
