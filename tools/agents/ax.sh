#!/usr/bin/env bash
# ax.sh <file.c> <fn> <rom> [tokens]  -> aligned diff, summary at the end.  run in WSL
cd /mnt/d/Projects/ws/s905
echo "$1 $2 $3 ${4:-@SN}" > wip/_ax_l_$$.txt
bash tools/fk.sh wip/_ax_l_$$.txt > /dev/null 2>&1
python3 tools/ad.py "$1" "$2" "$3" ${4:-@SN} 2>&1 | grep -v SyntaxWarning
rm -f wip/_ax_l_$$.txt
