#!/usr/bin/env bash
# side-by-side: bash tools/sd.sh <file.c> <fn> <rom hex> [tokens...]   (shows only differing lines +-2 ctx unless FULL=1)
cd /mnt/d/Projects/ws/s702
f=$1; fn=$2; rom=$3; shift 3
tok="${*:-@SN}"
echo "$f $fn $rom $tok" > wip/_sd_l.txt
bash tools/fk.sh wip/_sd_l.txt | head -3
cd $HOME/trw_s702
python3 tools/side.py $f $fn $rom $tok > /tmp/_sd_$$.txt 2>&1
if [ -n "$FULL" ]; then cat /tmp/_sd_$$.txt; else
awk '{l[NR]=$0; if($2=="!") m[NR]=1} END{for(i=1;i<=NR;i++){ if(m[i]||m[i-1]||m[i+1]||m[i-2]||m[i+2]) print l[i]; else if(m[i-3]) print "..."}}' /tmp/_sd_$$.txt; fi
rm -f /tmp/_sd_$$.txt
