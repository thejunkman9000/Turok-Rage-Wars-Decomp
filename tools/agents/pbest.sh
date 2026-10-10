#!/bin/bash
# pbest.sh fn : copy best permuter output source to /mnt/d/.../wip/perm_<fn>.c and print its score dir
d=$HOME/perm/s703_$1
b=$(ls -d $d/output-* 2>/dev/null | sort -t- -k2 -n | head -1)
echo $b
[ -n "$b" ] && cp $b/source.c /mnt/d/Projects/ws/s703/wip/perm_$1.c
