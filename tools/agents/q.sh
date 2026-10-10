#!/bin/bash
# usage: tools/q.sh path func rom flags...
cd /d/Projects/ws/s705
echo "$@" > wip/_q.txt
powershell -NoProfile -File tools/fchk.ps1 wip/_q.txt 2>&1 | grep -v -i warning | head -${QN:-8}
