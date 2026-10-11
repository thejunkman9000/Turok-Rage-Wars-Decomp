#!/usr/bin/env python3
"""Frame canaries for the diagnostic build (PORT_SSP=1 in port/build_clang.py), added to the LLVM IR AFTER the big-endian rewrite.

Matched C may write past its locals (a callee that fills a 0x40-byte matrix through a pointer to a Vec3f, an index the original never lets get out of
range): on the MIPS frame that lands in padding, on the host frame it runs over the saved registers or the return address.  Clang's own
-fstack-protector-all does not work in this pipeline (the cookie code goes through the rewrite), so the canary is inserted here:
  - the first alloca of the function is a canary word (the backend gives the first stack object the slot nearest to the saved registers, so a write
    that runs upward from any local has to cross it first),
  - it is set to a fixed pattern on entry and checked before every `ret`; on a mismatch port_stack_smash(<address of the function>) logs
    `STACKSMASH fn=<rva>` once per function (port/ssp.c) and the code carries on.
usage (from build_clang.py): instrument(ir_text) -> ir_text"""
import re

PATTERN = 0x5A5AC3C3
DEFINE = re.compile(r'^define\b[^\n]*?@([\w.$]+)\(.*\{\s*$')

def instrument(text):
    lines = text.split('\n'); out = []; i = 0; k = 0; any_fn = False
    while i < len(lines):
        l = lines[i]
        m = DEFINE.match(l)
        if not m:
            out.append(l); i += 1; continue
        name = m.group(1)
        if not any_fn: out.append('declare void @port_stack_smash(i32)')
        any_fn = True
        out.append(l); i += 1
        if i < len(lines) and re.match(r'^[\w.$-]+:', lines[i]): out.append(lines[i]); i += 1          # an explicitly labelled entry block
        out.append('  %__canary = alloca i32, align 4')
        out.append('  store volatile i32 %d, ptr %%__canary, align 4' % PATTERN)
        while i < len(lines) and lines[i] != '}':
            r = re.match(r'^(\s*)ret\b(.*)$', lines[i])
            if r:
                k += 1
                out.append('  %%__cv%d = load volatile i32, ptr %%__canary, align 4' % k)
                out.append('  %%__cb%d = icmp ne i32 %%__cv%d, %d' % (k, k, PATTERN))
                out.append('  br i1 %%__cb%d, label %%__smash%d, label %%__ret%d' % (k, k, k))
                out.append('__smash%d:' % k)
                out.append('  call void @port_stack_smash(i32 ptrtoint (ptr @%s to i32))' % name)
                out.append('  br label %%__ret%d' % k)
                out.append('__ret%d:' % k)
                out.append(lines[i])
            else:
                out.append(lines[i])
            i += 1
    return '\n'.join(out)
