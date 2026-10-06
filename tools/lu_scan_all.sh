#!/usr/bin/env bash
# Scan every libreultra C source against the ROM with the project's libultra flags. Prints per-function status.
cd /mnt/d/Projects/TurokRageWars
SRCS=$(ls ~/libreultra/lib/src/*.c ~/libreultra/lib/src/math/*.c 2>/dev/null | xargs -n1 basename | tr '\n' ' ')
for f in $SRCS; do
  python3 tools/lu_match.py 2.8.1 ${FLAGS:--O3 -fforce-addr -fno-builtin -mcpu=r4300} -- $f 2>&1 | grep -v '^--'
done
