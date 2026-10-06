#!/usr/bin/env bash
# Sync the project into ~/trw (Linux side) without building.
set -euo pipefail
SRC=/mnt/d/Projects/TurokRageWars; DST=$HOME/trw
mkdir -p "$DST"
rsync -a --delete --exclude=.git --exclude=.venv --exclude=build --exclude=tools/gcc --exclude=__pycache__ "$SRC/" "$DST/"
[ -d "$DST/tools/gcc" ] || cp -a "$SRC/tools/gcc" "$DST/tools/gcc"
