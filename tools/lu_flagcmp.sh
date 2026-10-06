#!/usr/bin/env bash
# Compare libultra flag sets: number of exact matches and which functions are exact / near (>=50%).
cd /mnt/d/Projects/TurokRageWars
run() {
  FLAGS="$1" bash tools/lu_status.sh > /tmp/fc.txt 2>&1
  printf "### %s\n   exact: %s\n" "$1" "$(grep -c EXACT /tmp/fc.txt)"
  printf "   exact list: %s\n" "$(grep EXACT /tmp/fc.txt | awk '{printf "%s ", $1}')"
  printf "   near: %s\n" "$(grep -E ' [0-9]+/[0-9]+ ' /tmp/fc.txt | awk '{split($3,a,"/"); if (a[1]*2>=a[2]) printf "%s(%s) ", $1, $3}')"
}
run "-O2 -fforce-addr -fno-builtin"
run "-O2 -fforce-addr -fno-builtin -mcpu=r4300"
run "-O2 -fforce-addr -fno-builtin -mcpu=r4600"
