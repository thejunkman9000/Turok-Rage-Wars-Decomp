#!/usr/bin/env python3
"""Exact per-function MIPS assembly for every game function, straight from the ROM.
Function boundaries come from docs/game_funcs.txt / funcs_a.txt (the project's authoritative list: name, ROM address, instruction
count); the name encodes the virtual address.  Code that lies beyond those lists (the end of overlay A) uses port/asm_tail's
detection.  Disassembly: mips-linux-gnu-objdump in WSL.  Output: port/build/asm_func/<name>.s in splat style (glabel + `.L` labels)
plus port/build/asm_func/index.txt (name vaddr ninsns)."""
import os, re, struct, subprocess, sys

ROM = None
def rom():
    global ROM
    if ROM is None: ROM = open('baserom.us.v11.z64', 'rb').read()
    return ROM

# main program: ROM 0x1000 -> vaddr 0x200400; overlay A: ROM 0x16E000 -> vaddr 0x400000
REGIONS = [(0x001000, 0x16E000, 0x200400), (0x16E000, 0x1BCDA0, 0x400000)]

SYMS = {}
for _l in open('symbol_addrs.txt'):
    _m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+);\s*//\s*type:func', _l)
    if _m: SYMS[int(_m.group(2), 16) & 0x0FFFFFFF] = _m.group(1)

def fname(a):
    return SYMS.get(a & 0x0FFFFFFF, 'func_%08X' % (a & 0x0FFFFFFF))

def function_list():
    funcs = {}
    for l in open('docs/game_funcs.txt'):
        if l.startswith('#'): continue
        f = l.split()
        if len(f) >= 3 and f[1].startswith('func_'): funcs[f[1]] = (int(f[0], 16), int(f[2]))
    for l in open('funcs_a.txt'):
        f = l.split('#')[0].split()
        if len(f) >= 3 and f[0].startswith('func_'): funcs.setdefault(f[0], (int(f[1], 16), int(f[2])))
    return funcs

def disassemble():
    """{vaddr: (word, text)} for the code regions"""
    ins = {}
    r = rom()
    for lo, hi, vbase in REGIONS:
        path = 'port/build/asm_region_%X.bin' % lo
        open(path, 'wb').write(r[lo:hi])
        p = subprocess.run(['wsl', 'mips-linux-gnu-objdump', '-D', '-b', 'binary', '-mmips:4300', '-EB', '--adjust-vma=0x%X' % vbase, path], capture_output=True, text=True)
        for l in p.stdout.split('\n'):
            m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S.*)$', l)
            if m: ins[int(m.group(1), 16)] = (int(m.group(2), 16), m.group(3).strip())
    return ins

REGS = re.compile(r'(?<![\w$.])(f\d+|zero|at|v[01]|a[0-3]|t[0-9]|s[0-8]|k[01]|gp|sp|fp|ra)(?![\w])')
def dollar(t): return REGS.sub(lambda m: '$' + m.group(1), t)

BRANCH_OPS = (1, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17)
def is_branch(w):
    op = w >> 26
    return op in BRANCH_OPS or (op == 0x11 and ((w >> 21) & 31) == 8)
def boff(w):
    off = w & 0xFFFF
    return off - 0x10000 if off & 0x8000 else off

def conv(txt, lo, hi):
    mn = txt.split()[0]; ops = txt[len(mn):].strip()
    if mn in ('jal', 'j'):
        t = int(ops.split()[0], 16)
        if mn == 'j' and lo <= t < hi: return 'j .L%08X' % t
        return '%s %s' % (mn, fname(t))
    if mn.startswith('b') and mn not in ('break',) and ops:
        parts = ops.split(',')
        tgt = int(parts[-1].split()[0], 16)
        regs = [dollar(p) for p in parts[:-1]]
        name = '.L%08X' % tgt if lo <= tgt < hi else fname(tgt)
        return '%s %s%s' % (mn, ''.join(r + ', ' for r in regs), name)
    return '%s %s' % (mn, dollar(ops)) if ops else mn

_ROMWORDS = None
def jump_tables(lo, hi):
    """runs of >= 3 consecutive ROM words that are word-aligned addresses inside [lo, hi): switch tables of that function"""
    global _ROMWORDS
    if _ROMWORDS is None:
        r = rom(); nw = len(r) // 4
        _ROMWORDS = struct.unpack('>%dI' % nw, r[:nw * 4])
    ws = _ROMWORDS; runs = []
    i = 0x0C0000 // 4
    while i < len(ws):
        if lo <= ws[i] < hi and ws[i] % 4 == 0:
            j = i
            while j < len(ws) and lo <= ws[j] < hi and ws[j] % 4 == 0: j += 1
            if j - i >= 3: runs.append(list(ws[i:j]))
            i = j
        else: i += 1
    return runs

def function_text(name, vaddr, n, ins, rom_base):
    lo, hi = vaddr, vaddr + 4 * n
    targets = set()
    has_jr = any((ins[a][0] & 0xFC1FFFFF) == 0x00000008 and ((ins[a][0] >> 21) & 31) != 31 for a in range(lo, hi, 4) if a in ins)   # jr $reg (not ra)
    tables = jump_tables(lo, hi) if has_jr else []
    for run in tables: targets.update(run)
    for a in range(lo, hi, 4):
        if a not in ins: return None
        w = ins[a][0]
        if is_branch(w):
            t = a + 4 + boff(w) * 4
            if lo <= t < hi: targets.add(t)
        elif (w >> 26) == 2:
            t = ((w & 0x3FFFFFF) << 2) & 0x0FFFFFFF
            if lo <= t < hi: targets.add(t)
    out = ['glabel %s' % name]
    for a in range(lo, hi, 4):
        if a in targets: out.append('.L%08X:' % a)
        w, txt = ins[a]
        line = '.word 0x%08X' % w if txt.startswith('.word') else conv(txt, lo, hi)
        out.append('    /* %X %08X %08X */  %s' % (rom_base + (a - lo), a, w, line))
    for run in tables: out.append('.jtbl ' + ' '.join('.L%08X' % t for t in run))
    return '\n'.join(out) + '\n'

def tail_functions():
    """overlay A's tail (ROM 0x1B8100...) is not in the lists: reuse asm_tail's detection (it writes ovl_tail.s with glabels)"""
    return []

def entry_candidates(ins):
    """addresses that something treats as a function entry: jal targets, lui/addiu(ori) constants, code pointers in data"""
    r = rom(); nw = len(r) // 4
    ws = struct.unpack('>%dI' % nw, r[:nw * 4])
    cands = set()
    def in_code(v): return v % 4 == 0 and ((0x200400 <= v < 0x2C0000) or (0x400000 <= v < 0x44EDA0))
    for i, w in enumerate(ws):
        if in_code(w): cands.add(w)                                   # pointer in data (jump tables point INTO functions, but are filtered below)
    for i, w in enumerate(ws[:0x1BD000 // 4]):
        op = w >> 26
        if op == 3:
            t = (w & 0x3FFFFFF) << 2
            if in_code(t): cands.add(t)
        elif op == 0x0F and (w & 0xFFFF) in list(range(0x20, 0x30)) + [0x40, 0x41, 0x42, 0x43, 0x44]:
            rt = (w >> 16) & 31
            for k in range(1, 5):
                if i + k >= nw: break
                x = ws[i + k]; xop = x >> 26
                if xop in (0x09, 0x0D) and ((x >> 21) & 31) == rt:
                    imm = x & 0xFFFF
                    if xop == 0x09 and imm & 0x8000: imm -= 0x10000
                    v = ((w & 0xFFFF) << 16) + imm
                    if in_code(v): cands.add(v)
                    break
    return cands

def split_points(lo, hi, ins, cands):
    """(splits, blocked): entries glued into the middle of a project function.  A candidate becomes a split when it follows an
    unconditional jr ra / j (+ delay slot) and no branch located before it reaches it or any address after it (the function really ends
    there).  Candidates that are reached by earlier branches stay inside the function but are returned in `blocked`: they are real
    entry points as well and get an overlapping standalone copy."""
    maxt = lo; pts = []; blocked = []
    for a in range(lo, hi, 4):
        w = ins[a][0]
        if a in cands and a >= lo + 8:
            w1 = ins.get(a - 8, (0,))[0]
            if w1 == 0x03E00008 or (w1 >> 26) == 2:
                if maxt <= a: pts.append(a)
                else: blocked.append(a)
        if is_branch(w): maxt = max(maxt, a + 4 + boff(w) * 4)
        elif (w >> 26) == 2:
            t = ((w & 0x3FFFFFF) << 2) & 0x0FFFFFFF
            if lo <= t < hi and t > a: maxt = max(maxt, t)
    return pts, blocked

def run():
    funcs = function_list()
    ins = disassemble()
    cands = entry_candidates(ins)
    os.makedirs('port/build/asm_func', exist_ok=True)
    n_ok = 0; idx = []
    for name, (romaddr, n) in sorted(funcs.items(), key=lambda kv: kv[1][0]):
        vaddr = int(name[5:], 16)
        if any(vaddr + 4 * i not in ins for i in range(n)): continue
        pts, blocked = split_points(vaddr, vaddr + 4 * n, ins, cands)
        bounds = [vaddr] + pts + [vaddr + 4 * n]
        for q in blocked:                                    # overlapping standalone copy of an entry that lies inside another piece
            nxt = [x for x in bounds if x > q][0]
            qn = 'func_%08X' % q
            open('port/build/asm_func/%s.s' % qn, 'w', encoding='utf-8', newline='\n').write(function_text(qn, q, (nxt - q) // 4, ins, romaddr + (q - vaddr)))
            idx.append('%s %08X %d' % (qn, q, (nxt - q) // 4)); n_ok += 1
        for k in range(len(bounds) - 1):
            a, b = bounds[k], bounds[k + 1]
            pname = name if k == 0 else 'func_%08X' % a
            txt = function_text(pname, a, (b - a) // 4, ins, romaddr + (a - vaddr))
            open('port/build/asm_func/%s.s' % pname, 'w', encoding='utf-8', newline='\n').write(txt)
            idx.append('%s %08X %d' % (pname, a, (b - a) // 4)); n_ok += 1
    # overlay A tail functions (detected by asm_tail.py) are appended as individual files too
    if os.path.exists('port/build/asm_extra/ovl_tail.s'):
        cur = None; lines = []
        def flush():
            if cur: open('port/build/asm_func/%s.s' % cur, 'w', encoding='utf-8', newline='\n').write('\n'.join(lines) + '\n'); idx.append('%s %08X 0' % (cur, int(cur[5:], 16)) if cur.startswith('func_') else cur)
        for l in open('port/build/asm_extra/ovl_tail.s', encoding='utf-8').read().split('\n'):
            m = re.match(r'glabel (\S+)', l)
            if m:
                flush(); cur = m.group(1); lines = [l]
            elif cur: lines.append(l)
        flush()
    open('port/build/asm_func/index.txt', 'w').write('\n'.join(idx) + '\n')
    print('functions written:', len(idx), '(from lists:', n_ok, ')')

if __name__ == '__main__':
    run()
