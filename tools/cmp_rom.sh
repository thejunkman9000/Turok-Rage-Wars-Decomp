#!/usr/bin/env bash
# Show built vs original bytes around an offset (default: first difference), run in WSL on ~/trw.
cd ~/trw
OFF=${1:-$(( $(cmp build/turok_ragewars.z64 baserom.us.v11.z64 2>/dev/null | head -1 | sed -E 's/.*byte ([0-9]+),.*/\1/') - 1 ))}
printf "first diff at 0x%X\n" "$OFF"
S=$(( OFF / 16 * 16 - 16 ))
echo "== built";    xxd -s $S -l 64 build/turok_ragewars.z64
echo "== original"; xxd -s $S -l 64 baserom.us.v11.z64
