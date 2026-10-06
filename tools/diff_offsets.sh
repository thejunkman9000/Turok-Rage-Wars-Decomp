#!/usr/bin/env bash
# List differing byte offsets (hex, 0-based) between the built ROM in ~/trw and the base ROM, grouped into ranges.
cd ~/trw
cmp -l build/turok_ragewars.z64 baserom.us.v11.z64 | awk '
  { o = $1 - 1
    if (start == "" ) { start = o; last = o }
    else if (o - last > 8) { printf "0x%X-0x%X\n", start, last; start = o }
    last = o }
  END { if (start != "") printf "0x%X-0x%X\n", start, last }'
