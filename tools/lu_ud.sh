#!/usr/bin/env bash
# Compile a libultra file in WSL and write JSON for tools/lu_ud.py.
# usage: bash tools/lu_ud.sh <file.c> [name=0xROMOFF ...]    (GCC_VER / FLAGS env override defaults 2.8.1 / -O2 -fforce-addr -fno-builtin)
cd /mnt/d/Projects/TurokRageWars
f=$1; shift
rm -f build_ud.json
python3 tools/lu_json.py "${GCC_VER:-2.8.1}" "${FLAGS:--O2 -fforce-addr -fno-builtin}" "$f" /tmp/lu_ud.json "$@" || { echo "lu_ud: compile failed"; exit 1; }
cp /tmp/lu_ud.json build_ud.json
