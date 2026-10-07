#!/usr/bin/env bash
# Source fixes for worker results that clash with later versions of the shared headers (re-run after apply_results.py)
cd "$(dirname "$0")/.."
sed -i 's/\bB04Sel\b/B04SelL/g' src/game/func_002166F4.c
sed -i 's/\bB04Menu\b/B04MenuL/g' src/game/func_002191B8.c
grep -q '^typedef struct B18Tab' src/game/func_0027CA7C.c && sed -i '3,15d' src/game/func_0027CA7C.c
sed -i 's/\r$//' src/game/*.c include/*.h
sed -i 's/1\.5707963f/1.5707964f/g' src/game/*.c
sed -i 's/func_00255C58(&D_80103F70, n);/func_00255C58((u8 *)\&D_80103F70 + 0x600, n);/' src/game/func_002549C8.c
sed -i 's/-1\.5707964f/-1.57079649f/' src/game/func_00203908.c
sed -i 's/\r$//' src/ovl_a/*.c 2>/dev/null
sed -i 's/1\.5707964f/1.57079649f/' src/game/func_0020388C.c
