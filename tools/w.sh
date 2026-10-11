#!/usr/bin/env bash
# run a command in WSL (Ubuntu-24.04) in the current directory (Git-Bash path /d/x -> /mnt/d/x):  bash tools/w.sh "<cmd>"   (no $var / backslashes inside the quoted command: use a script file)
d=$(pwd | sed 's|^/\([a-zA-Z]\)/|/mnt/\L\1/|')
wsl -d Ubuntu-24.04 -- bash -c "cd '$d' && $1"
