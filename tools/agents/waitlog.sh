#!/bin/bash
# waitlog.sh <logfile> <pattern> <max seconds>
f=$1; p=$2; m=${3:-540}
for ((i=0;i<m;i+=10)); do grep -q "$p" "$f" 2>/dev/null && break; sleep 10; done
cat "$f" 2>/dev/null
