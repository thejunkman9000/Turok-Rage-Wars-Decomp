#!/usr/bin/env python3
"""Keep only one function of a preprocessed C file (for decomp-permuter).

usage: python3 perm_strip.py <preprocessed.c> <function>   (prints the result)
Everything outside function bodies (typedefs, externs, prototypes, tables) is kept; every other function
definition is dropped.  A definition is recognised by `)` right before the first `{` of a top-level chunk.
"""
import re, sys

src = open(sys.argv[1]).read()
want = sys.argv[2]
out = []
i, n = 0, len(src)
chunk_start = 0
depth = 0
first_brace = None
while i < n:
    c = src[i]
    if c == '{':
        if depth == 0 and first_brace is None:
            first_brace = i
        depth += 1
    elif c == '}':
        depth -= 1
        if depth == 0 and first_brace is not None:
            head = src[chunk_start:first_brace].rstrip()
            if head.endswith(')'):
                # function definition: ends here
                name = re.findall(r'([A-Za-z_]\w*)\s*\(', head)
                fname = name[-1] if name else ''
                # the last identifier before '(' that is followed by the parameter list
                m = re.search(r'([A-Za-z_]\w*)\s*\([^()]*(?:\([^()]*\)[^()]*)*\)\s*$', head)
                fname = m.group(1) if m else fname
                if fname == want:
                    out.append(src[chunk_start:i + 1])
                chunk_start = i + 1
                first_brace = None
    elif c == ';' and depth == 0:
        out.append(src[chunk_start:i + 1])
        chunk_start = i + 1
        first_brace = None
    i += 1
out.append(src[chunk_start:])
sys.stdout.write(''.join(out))
