#!/bin/bash
# usage: full_adopt.sh <ver> <ws>
cd /d/Projects/TurokRageWars
.venv/Scripts/python.exe tools/mkver.py $1 --out D:/Projects/ws/$2 2>&1 | grep -i "manifest units"
(cd /d/Projects/ws/$2 && powershell -File tools/cycle.ps1 2>&1 | grep -v warning | tail -3)
.venv/Scripts/python.exe wip/adopt_gaps.py $1 D:/Projects/ws/$2 --apply 2>&1 | tail -2
.venv/Scripts/python.exe tools/mkver.py $1 --out D:/Projects/ws/$2 2>&1 | tail -1
(cd /d/Projects/ws/$2 && powershell -File tools/cycle.ps1 2>&1 | grep -v warning | tail -3)
