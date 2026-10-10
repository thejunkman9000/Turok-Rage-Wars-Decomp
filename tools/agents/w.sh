#!/bin/bash
# run a command inside WSL at the workspace root:  tools/w.sh "bash tools/fk.sh wip/lists/x.txt"
export MSYS_NO_PATHCONV=1
wsl -d Ubuntu-24.04 -- bash -c "cd /mnt/d/Projects/ws/s806 && $*"
