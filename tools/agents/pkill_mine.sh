#!/usr/bin/env bash
# pkill_mine.sh : kill only permuter processes started from my perm dirs (perm/s904_*)
pkill -f "permuter.py /home/johns/perm/s904_" 2>/dev/null
sleep 1
pgrep -af "permuter.py /home/johns/perm/s904_" || echo "none left"
