#!/bin/bash
# diffonly.sh <file.c> <fn> <rom> <n> : side-by-side, only lines near differences (context 3)
cd /mnt/d/Projects/ws/s806
N=$4 bash tools/side.sh $1 $2 $3 > /tmp/_side.txt 2>&1
awk '{l[NR]=$0} /^ *[0-9]+ #/{m[NR]=1} END{for(i=1;i<=NR;i++){ok=0; for(d=-3;d<=3;d++) if(m[i+d]) ok=1; if(ok) print l[i]; else if(!sk){print "..."; sk=1} if(ok) sk=0}}' /tmp/_side.txt
