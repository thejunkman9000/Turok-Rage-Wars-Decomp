#!/usr/bin/env bash
# kill all s705 permuter/queue processes (only those started from the s705 workspace / perm dirs)
for p in $(pgrep -f 'ws/s705/tools/(runq|pgo2).sh'); do kill $p 2>/dev/null; done
sleep 1
for p in $(pgrep -f 'permuter.py /home/johns/perm/s705'); do kill $p 2>/dev/null; done
echo killed
