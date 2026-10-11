#!/bin/bash
# _agg2.sh <variants.txt> [jobs] : run vb2 and print per-label results (label = text after //==== )
cd /mnt/d/Projects/ws/s905
python3 - "$1" <<'PY'
import re, sys
txt = open(sys.argv[1], encoding='utf-8').read()
labels = re.findall(r'^//==== (.*)$', txt, flags=re.M)
open('/tmp/labels.txt', 'w').write('\n'.join(labels))
PY
python3 tools/vb2.py func_00235AD0 0x366D0 --file $1 --jobs ${2:-6} --top 100000 2>&1 | grep -v Warning | grep 'structural=' | python3 -c "
import sys, re
labels = open('/tmp/labels.txt').read().split('\n')
rows = []
for l in sys.stdin:
    m = re.match(r'wip/vb/v(\d+)\.c: structural=(\d+) operand=(\d+) exact=\d movs=(\d) n=(\d+)', l)
    if m:
        k = int(m.group(1)); rows.append((int(m.group(2))*3+int(m.group(3)), int(m.group(2)), int(m.group(3)), m.group(4), m.group(5), labels[k-1]))
rows.sort()
for r in rows[:${3:-40}]: print(*r[1:])
"
