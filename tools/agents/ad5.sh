#!/usr/bin/env bash
# ad5.sh <file.c> <fn> <rom> [tokens] : aligned diff
cd /mnt/d/Projects/ws/s903
bash tools/adx.sh "$@" 2>&1 | grep -v Warning
