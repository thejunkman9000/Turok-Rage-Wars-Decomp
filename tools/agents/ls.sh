#!/usr/bin/env bash
# ls.sh <file.c> <fn> <rom> <lo> <hi> [tokens]: side by side listing ours | ROM by index (no alignment)
cd /mnt/d/Projects/ws/s905
echo "$1 $2 $3 ${6:-@SN}" > wip/_ls_l_$$.txt
bash tools/fk.sh wip/_ls_l_$$.txt > /dev/null 2>&1
python3 tools/lst.py wip/_ls_l_$$.txt "$2" "$4" "$5" 2>&1 | grep -v Warning
rm -f wip/_ls_l_$$.txt
