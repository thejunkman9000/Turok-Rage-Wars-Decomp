#!/bin/bash
# _agg.sh <variants.txt> : run vb2 and summarize distinct (structural,operand,movs) outcomes with counts and one example
cd /mnt/d/Projects/ws/s905
python3 tools/vb2.py func_00235AD0 0x366D0 --file $1 --jobs ${2:-6} --top 100000 2>&1 | grep -v Warning | grep 'structural=' | sed -E 's/^([^:]+): (structural=[0-9]+ operand=[0-9]+) exact=[0-9] (movs=[0-9] n=[0-9]+).*/\2 \3 \1/' | sort | awk '{k=$1" "$2" "$3" "$4; c[k]++; if (!(k in ex)) ex[k]=$5} END {for (k in c) print c[k], k, ex[k]}' | sort -t= -k2 -n | head -${3:-25}
