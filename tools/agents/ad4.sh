#!/usr/bin/env bash
# ad4.sh <file.c> [tokens]  : aligned diff for func_0023A4D0 (WSL)
cd /mnt/d/Projects/ws/s903
bash tools/adx.sh $1 func_0023A4D0 0x3B0D0 ${2:-@SN} 2>&1 | grep -v Warning
