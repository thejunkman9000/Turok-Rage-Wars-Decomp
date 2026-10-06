#!/usr/bin/env bash
# list symbols whose address in the WSL build differs from symbol_addrs.txt (run in WSL)
cd ~/trw
mips-linux-gnu-nm build/turok_ragewars.elf | awk '{print $3, $1}' | sort > /tmp/nm.txt
grep -E '^[A-Za-z_0-9]+ = 0x[0-9A-Fa-f]+' /mnt/d/Projects/TurokRageWars/symbol_addrs.txt | sed -E 's/^([A-Za-z_0-9]+) = 0x([0-9A-Fa-f]+).*/\1 \2/' | tr 'A-F' 'a-f' | awk '{printf "%s %08x\n", $1, strtonum("0x"$2)}' | sort > /tmp/sa.txt
join /tmp/nm.txt /tmp/sa.txt | awk '$2 != $3 && $3 !~ /^8/ {print}' | head -20
