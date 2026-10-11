#!/usr/bin/env bash
# schedlog.sh <sched dump> <uid> [after]  : print the scheduler log (ready lists) of the basic block containing insn <uid>
f=$1; uid=$2; a=${3:-60}
python3 - "$f" "$uid" "$a" <<'EOF'
import sys, re
f, uid, a = sys.argv[1], int(sys.argv[2]), int(sys.argv[3])
L = open(f).read().splitlines()
# find the block headers
hdr = [i for i, l in enumerate(L) if l.startswith(';;\t -- basic block number')]
for k, h in enumerate(hdr):
    m = re.search(r'from (\d+) to (\d+)', L[h])
    end = hdr[k + 1] if k + 1 < len(hdr) else len(L)
    blk = L[h:end]
    if any(re.match(r';; insn\[\s*%d\]' % uid, x) for x in blk):
        print('\n'.join(x[:200] for x in blk[:a]))
        break
EOF
