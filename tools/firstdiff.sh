#!/usr/bin/env bash
# first differing ROM offsets (>= LO, default 0x1001) between the WSL build and the base ROM (run inside WSL)
lo=${1:-4097}
cd ~/trw
cmp -l build/turok_ragewars.z64 /mnt/d/Projects/TurokRageWars/baserom.us.v11.z64 | awk -v lo=$((lo)) '$1-1>=lo{printf "0x%X\n", $1-1; n++; if (n>=6) exit}'
