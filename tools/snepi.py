#!/usr/bin/env python3
"""@EPI helper: rewrite the gcc 2.8.1 epilogue `.set noreorder; j $31; addu $sp,$sp,N` into `addu $sp,$sp,N; j $31` (the
unfilled-return form of the ROM's low code region 0x1000-0x38xx; asn64 then adds the delay-slot nop)."""
import re, sys
p = sys.argv[1]
s = open(p).read()
s = re.sub(r'(?:\t\.set\tnoreorder\n\t\.set\tnomacro\n)?\tj\t\$31\n\taddu\t(\$sp,\$sp,\d+)\n(?:\t\.set\tmacro\n\t\.set\treorder\n)?',
           r'\taddu\t\1\n\tj\t$31\n', s)
open(p, 'w').write(s)
