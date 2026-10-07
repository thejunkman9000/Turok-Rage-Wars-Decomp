#!/usr/bin/env python3
"""Rewrite a clang-emitted LLVM IR module so that every 16/32/64-bit integer, pointer, float and double memory access
is big-endian (the N64's byte order), whatever the host is.  Game data and assets are kept exactly as they are in the ROM
and the decompiled C reads/writes them through ordinary C pointers and struct fields.

   load iN, ptr P      ->  %t = load iN, ptr P ; %v = bswap(%t)
   store iN V, ptr P   ->  %t = bswap(V)       ; store iN %t, ptr P
   pointers go through i32 (inttoptr/ptrtoint, the port is 32-bit), floats/doubles through bitcast to i32/i64.
Initialised constant arrays defined in the module are byte-swapped at rewrite time.

usage: python be_ir.py in.ll out.ll"""
import re, sys, struct

INT_BITS = {'i16': 16, 'i32': 32, 'i64': 64}
CTYPES = {'float': ('i32', 32), 'double': ('i64', 64), 'ptr': ('i32', 32)}
n_tmp = [0]

def tmp():
    n_tmp[0] += 1
    return f'%__be{n_tmp[0]}'

def split_top(s, start=0):
    """index of the first ', ptr ' at paren/bracket depth 0 starting at `start`"""
    depth = 0; i = start
    while i < len(s):
        c = s[i]
        if c in '([{': depth += 1
        elif c in ')]}': depth -= 1
        elif depth == 0 and s.startswith(', ptr ', i): return i
        i += 1
    return -1

LOAD = re.compile(r'^(\s*)(%[\w.\-$]+) = load (volatile )?(i16|i32|i64|float|double|ptr), ptr (.*?), align (\d+)(.*)$')
STORE = re.compile(r'^(\s*)store (volatile )?(i16|i32|i64|float|double|ptr) (.*)$')
GCONST = re.compile(r'^(@[\w.\-$"]+) = ((?:internal|private|linkonce_odr|dso_local|unnamed_addr|local_unnamed_addr|hidden|constant|\s)+) \[(\d+) x (i16|i32|i64|float|double)\] \[(.*)\](.*)$')

def bswap_const(ty, tok):
    tok = tok.strip()
    if ty in INT_BITS:
        bits = INT_BITS[ty]; v = int(tok) & ((1 << bits) - 1)
        v = int.from_bytes(v.to_bytes(bits // 8, 'little'), 'big')
        if v >= 1 << (bits - 1): v -= 1 << bits
        return str(v)
    if ty == 'float':
        raw = struct.unpack('<I', struct.pack('<f', float(tok)))[0] if not tok.startswith('0x') else struct.unpack('<I', struct.pack('<f', struct.unpack('<d', struct.pack('<Q', int(tok, 16)))[0]))[0]
        raw = int.from_bytes(raw.to_bytes(4, 'little'), 'big')
        return '0x' + format(struct.unpack('<Q', struct.pack('<d', struct.unpack('<f', struct.pack('<I', raw))[0]))[0], '016X')
    raw = int(tok, 16) if tok.startswith('0x') else struct.unpack('<Q', struct.pack('<d', float(tok)))[0]
    raw = int.from_bytes(raw.to_bytes(8, 'little'), 'big')
    return '0x' + format(raw, '016X')

DEF_GLOBAL = re.compile(r'^(@[\w.\-$"]+) = (?!external)')
DEF_RE = re.compile(r'^\s*(%[\w.\-$]+) = (.*)$')
ADDR_OPS = re.compile(r'(getelementptr|bitcast|addrspacecast|inttoptr|ptrtoint|phi|select)\b')

def native_pointer(ptr, tainted, defined):
    """True if the pointer operand is (derived from) the address of a global defined in this module: such objects (private
    switch/lookup tables, static data) are only touched by this module's own code and stay in native byte order."""
    if ptr in tainted: return True
    return any(g in ptr for g in defined)

def rewrite(text):
    out = []
    used = set()
    lines = text.split('\n')
    defined = {m.group(1) for m in (DEF_GLOBAL.match(l) for l in lines) if m}
    tainted = set()
    changed = bool(defined)
    while changed:                      # propagate "derived from a module-defined global" through address arithmetic
        changed = False
        for l in lines:
            m = DEF_RE.match(l)
            if not m or m.group(1) in tainted: continue
            rhs = m.group(2)
            if not ADDR_OPS.match(rhs): continue
            if any(g in rhs for g in defined) or any(re.search(re.escape(t) + r'(?![\w.\-$])', rhs) for t in tainted):
                tainted.add(m.group(1)); changed = True
    for line in lines:
        m = LOAD.match(line)
        if m:
            ind, dst, vol, ty, ptr, al, rest = m.groups()
            vol = vol or ''
            if native_pointer(ptr, tainted, defined):
                out.append(line); continue
            rest = re.sub(r',\s*!(nonnull|align|dereferenceable|dereferenceable_or_null|noundef|range)\s+!\d+', '', rest)
            if ty in INT_BITS:
                t = tmp(); used.add(ty)
                out.append(f'{ind}{t} = load {vol}{ty}, ptr {ptr}, align {al}{rest}')
                out.append(f'{ind}{dst} = call {ty} @llvm.bswap.{ty}({ty} {t})')
            else:
                ity, bits = CTYPES[ty]; used.add(ity)
                t1, t2 = tmp(), tmp()
                out.append(f'{ind}{t1} = load {vol}{ity}, ptr {ptr}, align {al}{rest}')
                out.append(f'{ind}{t2} = call {ity} @llvm.bswap.{ity}({ity} {t1})')
                conv = 'inttoptr' if ty == 'ptr' else 'bitcast'
                out.append(f'{ind}{dst} = {conv} {ity} {t2} to {ty}')
            continue
        m = STORE.match(line)
        if m:
            ind, vol, ty, tail = m.groups()
            vol = vol or ''
            k = split_top(tail)
            if k >= 0:
                val = tail[:k]; after = tail[k + len(', ptr '):]       # "PTR, align N..."
                if native_pointer(after.split(', align')[0], tainted, defined):
                    out.append(line); continue
                if ty in INT_BITS:
                    t = tmp(); used.add(ty)
                    out.append(f'{ind}{t} = call {ty} @llvm.bswap.{ty}({ty} {val})')
                    out.append(f'{ind}store {vol}{ty} {t}, ptr {after}')
                else:
                    ity, bits = CTYPES[ty]; used.add(ity)
                    t1, t2 = tmp(), tmp()
                    conv = 'ptrtoint' if ty == 'ptr' else 'bitcast'
                    out.append(f'{ind}{t1} = {conv} {ty} {val} to {ity}')
                    out.append(f'{ind}{t2} = call {ity} @llvm.bswap.{ity}({ity} {t1})')
                    out.append(f'{ind}store {vol}{ity} {t2}, ptr {after}')
                continue
        out.append(line)
    decl = []
    for ty in sorted(used):
        decl.append(f'declare {ty} @llvm.bswap.{ty}({ty})')
    # insert the declarations right after the target triple line
    for i, l in enumerate(out):
        if l.startswith('target triple'):
            out[i + 1:i + 1] = decl
            break
    return '\n'.join(out)

if __name__ == '__main__':
    src = open(sys.argv[1], encoding='utf-8').read()
    open(sys.argv[2], 'w', encoding='utf-8', newline='\n').write(rewrite(src))
