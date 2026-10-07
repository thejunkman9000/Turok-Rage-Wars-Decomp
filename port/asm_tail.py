#!/usr/bin/env python3
"""Disassemble the code in ROM 0x1B9498-0x1BCDA0 (overlay A tail, shown as .word data by splat) into per-function asm that m2c
can read.  Function starts: stack-frame prologues after a return/data, jal targets, plus addresses given on the command line.
Output: port/build/asm_extra/ovl_tail.s  (glabel func_XXXXXXXX + splat-style lines)"""
import re, struct, subprocess, sys, os
ROM_LO, ROM_HI, VBASE = 0x1B8100, 0x1BCDA0, 0x44A100
rom = open('baserom.us.v11.z64', 'rb').read()
os.makedirs('port/build/asm_extra', exist_ok=True)
open('port/build/ovl_tail.bin', 'wb').write(rom[ROM_LO:ROM_HI])
r = subprocess.run(['wsl', 'mips-linux-gnu-objdump', '-D', '-b', 'binary', '-mmips:4300', '-EB', '--adjust-vma=0x%X' % VBASE, 'port/build/ovl_tail.bin'],
                   capture_output=True, text=True)
ins = {}
for l in r.stdout.split('\n'):
    m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S.*)$', l)
    if m:
        a = int(m.group(1), 16); ins[a] = (int(m.group(2), 16), m.group(3).strip())
words = {a: v[0] for a, v in ins.items()}
explicit = set(int(x, 16) for x in sys.argv[1:])
starts = set(explicit)
for a, ww in words.items():
    if (ww >> 16) == 0x27BD and (ww & 0x8000) and (ww & 0xFFFF) < 0xFFF8:       # addiu sp,sp,-N
        if a == VBASE or words.get(a - 8) == 0x03E00008 or words.get(a - 4) in (0, 0x03E00008):
            starts.add(a)
    if (ww >> 26) == 3:
        t = ((ww & 0x3FFFFFF) << 2) & 0x0FFFFFFF
        if VBASE <= t < VBASE + (ROM_HI - ROM_LO): starts.add(t)
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_all
_cands = asm_all.entry_candidates({})
for _a in _cands:
    if _a in words:                                        # something treats this address as a function entry; accept when it looks like one
        _w = words[_a]
        if ((_w >> 16) == 0x27BD and (_w & 0x8000)) or (_a in {t for t in ()}):
            starts.add(_a)
starts = sorted(s for s in starts if s in words)
BRANCH_OPS = (1, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17)
def is_branch(ww):
    op = ww >> 26
    return op in BRANCH_OPS or (op == 0x11 and ((ww >> 21) & 31) == 8)
def boff(ww):
    off = ww & 0xFFFF
    return off - 0x10000 if off & 0x8000 else off
def fn_end(s):
    a = s; maxt = s
    while a in words:
        ww = words[a]
        if is_branch(ww): maxt = max(maxt, a + 4 + boff(ww) * 4)
        if (ww >> 26) == 2:                                   # j: a forward jump inside the region is local control flow
            jt = ((ww & 0x3FFFFFF) << 2) & 0x0FFFFFFF
            if a < jt < VBASE + (ROM_HI - ROM_LO) and jt - a < 0x400: maxt = max(maxt, jt + 4)
        if ww == 0x03E00008 and a + 4 >= maxt: return a + 8
        a += 4
        if a - s > 0x3000: break
    return None
SYMS = {}
for _l in open('symbol_addrs.txt'):
    _m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+);\s*//\s*type:func', _l)
    if _m: SYMS[int(_m.group(2), 16) & 0x0FFFFFFF] = _m.group(1)
def fname(a): return SYMS.get(a & 0x0FFFFFFF, 'func_%08X' % a)
REGS = re.compile(r'(?<![\w$.])(f\d+|zero|at|v[01]|a[0-3]|t[0-9]|s[0-8]|k[01]|gp|sp|fp|ra)(?![\w])')
def dollar(t): return REGS.sub(lambda m: '$' + m.group(1), t)
def conv(txt):
    mn = txt.split()[0]; ops = txt[len(mn):].strip()
    if mn in ('jal', 'j'):
        return '%s %s' % (mn, fname(int(ops.split()[0], 16)))
    if mn.startswith('b') and mn not in ('break',) and ops:
        parts = ops.split(',')
        tgt = int(parts[-1].split()[0], 16)
        regs = [dollar(p) for p in parts[:-1]]
        return '%s %s.L%08X' % (mn, ''.join(r + ', ' for r in regs), tgt)
    return '%s %s' % (mn, dollar(ops)) if ops else mn
# a function that ends with jr ra is followed by the next function when the next word decodes as an instruction
work = list(starts); known = set(starts)
while work:
    s0 = work.pop()
    e0 = fn_end(s0)
    if e0 is not None and e0 in words and e0 not in known and words[e0] != 0 and not ins[e0][1].startswith('.word'):
        known.add(e0); work.append(e0)
starts = sorted(known)
out = []; done = set()
jal_starts = {((ww & 0x3FFFFFF) << 2) & 0x0FFFFFFF for ww in words.values() if (ww >> 26) == 3}
starts_sorted = sorted(starts)
for s in starts:
    if s in done and s not in explicit: continue
    e = fn_end(s)
    if e is None: continue
    nxt = [t for t in starts_sorted if t > s]
    if nxt and nxt[0] < e and (nxt[0] in jal_starts or nxt[0] in explicit): e = nxt[0]          # a jal target inside the range really is a function start: cut here
    done.update(range(s, e, 4))
    targets = {a + 4 + boff(words[a]) * 4 for a in range(s, e, 4) if is_branch(words[a])}
    targets |= {((words[a] & 0x3FFFFFF) << 2) & 0x0FFFFFFF for a in range(s, e, 4) if (words[a] >> 26) == 2 and s <= (((words[a] & 0x3FFFFFF) << 2) & 0x0FFFFFFF) < e}
    out.append('glabel func_%08X' % s)
    for a in range(s, e, 4):
        if a in targets: out.append('.L%08X:' % a)
        ww, txt = ins[a]
        line = '.word 0x%08X' % ww if txt.startswith('.word') else conv(txt)
        if (ww >> 26) == 2 and s <= (((ww & 0x3FFFFFF) << 2) & 0x0FFFFFFF) < e: line = 'j .L%08X' % (((ww & 0x3FFFFFF) << 2) & 0x0FFFFFFF)
        out.append('    /* %X %08X %08X */  %s' % (ROM_LO + a - VBASE, a, ww, line))
    out.append('')
open('port/build/asm_extra/ovl_tail.s', 'w', encoding='utf-8', newline='\n').write('\n'.join(out))
print('functions:', sum(1 for l in out if l.startswith('glabel')))
