#!/usr/bin/env bash
# lowest function symbol (func_XXXXXXXX / named in symbol_addrs) whose linked address differs from its expected VA (run in WSL)
cd ~/trw
mips-linux-gnu-nm build/turok_ragewars.elf | awk '$2 ~ /[Tt]/ {print $3, $1}' | sort > /tmp/nm.txt
grep -E '^[A-Za-z_0-9]+ = 0x[0-9A-Fa-f]+; // type:func' /mnt/d/Projects/TurokRageWars/symbol_addrs.txt | sed -E 's/^([A-Za-z_0-9]+) = 0x([0-9A-Fa-f]+).*/\1 \2/' | awk '{printf "%s %08x\n", $1, strtonum("0x"$2)}' > /tmp/sa.txt
awk '$1 ~ /^func_[0-9A-F]{8}$/ {printf "%s %s\n", $1, tolower(substr($1,6))}' /tmp/nm.txt >> /tmp/sa.txt
sort /tmp/sa.txt | join - /tmp/nm.txt | awk '$2 != $3 {print $3, $1, $2}' | sort | head -5
