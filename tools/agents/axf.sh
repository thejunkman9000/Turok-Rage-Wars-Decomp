#!/usr/bin/env bash
# axf.sh <file.c> <lo> <hi> : full aligned listing (ours | rom) for rows lo..hi (row index of ours or rom)
cd /mnt/d/Projects/ws/s905
echo "$1 func_00235AD0 0x366D0 @SN" > wip/_axf_l_$$.txt
bash tools/fk.sh wip/_axf_l_$$.txt > /dev/null 2>&1
FULL=1 python3 tools/ad.py "$1" func_00235AD0 0x366D0 @SN 2>&1 | grep -v SyntaxWarning > /tmp/axf_$$.txt
rm -f wip/_axf_l_$$.txt
awk -v lo=$2 -v hi=$3 '{ n=$0; match(substr(n,4), /[0-9]+/); v=substr(n,4)+0; if (v>=lo && v<=hi) print }' /tmp/axf_$$.txt
rm -f /tmp/axf_$$.txt
