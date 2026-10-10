#!/bin/bash
# dpass.sh file.c : run dump.sh then print count of lines per pass file
bash /mnt/d/Projects/ws/s703/tools/dump.sh "$@" >/dev/null 2>&1
cd ~/dmp703; wc -l t.c.* | head -20
