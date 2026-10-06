#!/usr/bin/env bash
# Compile every libreultra source and dump a JSON per file into ud_json/ (for tools/lu_locate_all.py).
cd /mnt/d/Projects/TurokRageWars
rm -f ud_json/*.json
for f in $(ls ~/libreultra/lib/src/*.c ~/libreultra/lib/src/math/*.c | xargs -n1 basename); do
  python3 tools/lu_json.py 2.8.1 "-O2 -fforce-addr -fno-builtin -mcpu=r4300" "$f" "ud_json/${f%.c}.json" >/dev/null 2>&1 || echo "fail $f"
done
ls ud_json | wc -l
