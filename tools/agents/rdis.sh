#!/bin/bash
# rdis.sh <rom hex start> <n insns> [ovl]  : disassemble ROM words (WSL)
off=$((16#${1#0x})); n=$2
dd if=/mnt/d/Projects/ws/s806/baserom.us.v11.z64 of=/tmp/_rdis.bin bs=1 skip=$off count=$((n*4)) 2>/dev/null
base=$off
if [ "$3" = "ovl" ]; then base=$((off - 0x16E000 + 0x400000)); else base=$((off + 0x1FF400)); fi
mips-linux-gnu-objdump -D -b binary -mmips:4300 -EB --no-show-raw-insn -M no-aliases --adjust-vma=$base /tmp/_rdis.bin | tail -n +8
