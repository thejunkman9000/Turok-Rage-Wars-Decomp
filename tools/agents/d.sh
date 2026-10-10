#!/bin/bash
# usage: tools/d.sh path func rom flags...   -> only differing lines with 2 lines context
cd /d/Projects/ws/s705
powershell -NoProfile -File tools/side.ps1 "$@" 2>&1 | grep -v -i warning > /tmp/_d.txt
grep -n '^ *[0-9]* !' /tmp/_d.txt | cut -d: -f1 | head -0
awk '{l[NR]=$0; if($2=="!") m[NR]=1} END{for(i=1;i<=NR;i++){ if(m[i]||m[i-1]||m[i+1]||m[i-2]||m[i+2]) print l[i]; else if(m[i-3]) print "..."}}' /tmp/_d.txt
