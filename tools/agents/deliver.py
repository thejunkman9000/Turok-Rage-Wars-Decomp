#!/usr/bin/env python3
"""deliver.py <chk list file> : run chk (via WSL fk.sh) on every line; for EXACT lines add a results line to wip/out/results.txt
(only lines whose function is not already recorded EXACT with the same source).  Does not copy files (use cp)."""
import sys, subprocess, re
lst = sys.argv[1]
out = subprocess.run(['bash', 'tools/fk.sh', lst], capture_output=True, text=True).stdout
print(out)
