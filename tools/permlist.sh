#!/bin/bash
# one line per running permuter: elapsed seconds + target directory argument
ps -eo etimes,args | grep '[p]ermuter.py' | awk '{print $1, $4, $5, $6, $7}' | sort -n | head -${1:-40}
echo "total: $(pgrep -fc permuter.py)  load: $(cut -d' ' -f1-3 /proc/loadavg)"
