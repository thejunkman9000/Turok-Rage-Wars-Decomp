#!/usr/bin/env bash
# Build in a Linux-side copy of the tree (~/trw): the old gcc/cpp cannot stat files on /mnt/d.
# usage (from PowerShell):  wsl -d Ubuntu-24.04 -- bash /mnt/d/Projects/TurokRageWars/tools/wsl_build.sh [make args]
set -euo pipefail
SRC=/mnt/d/Projects/TurokRageWars
DST=$HOME/trw
mkdir -p "$DST"
if command -v rsync >/dev/null; then
  rsync -a --delete --exclude=.git --exclude=.venv --exclude=build --exclude=tools/gcc --exclude=__pycache__ "$SRC/" "$DST/"
else
  echo "rsync missing: sudo apt install -y rsync"; exit 1
fi
[ -d "$DST/tools/gcc" ] || cp -a "$SRC/tools/gcc" "$DST/tools/gcc"
make -C "$DST" -j"$(nproc)" "$@"
