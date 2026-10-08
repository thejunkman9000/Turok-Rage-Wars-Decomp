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

ALIGN1_RAW = False      # native helper modules (RNC decoder ...) compose little-endian words from bytes: unaligned loads stay raw
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

LOAD = re.compile(r'^(\s*)(%[\w.\-$]+) = load (volatile )?(i8|i16|i32|i64|float|double|ptr), ptr (.*?), align (\d+)(.*)$')
STORE = re.compile(r'^(\s*)store (volatile )?(i8|i16|i32|i64|float|double|ptr) (.*)$')
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

GUEST_LO, GUEST_SIZE, GUEST_DELTA = 0x200000, 0x1E00000, 0x30000000   # low guest space [0x200000,0x2000000) lives at +0x30000000 on the host
ALLOCA = re.compile(r'^\s*(%[\w.\-$]+) = alloca\b')
LIBC_PTR_CALLS = {'memcpy', 'memmove', 'memset', 'memcmp', 'memchr', 'strlen', 'strcpy', 'strncpy', 'strcmp', 'strncmp', 'strchr', 'strrchr',
                  'strcat', 'strncat', 'strstr', 'bcopy', 'bzero'}
CALL = re.compile(r'^(\s*)((?:%[\w.\-$]+ = )?(?:tail |musttail |notail )?call [^@]*@([\w.]+)\()(.*)\)((?:\s*#\d+)?(?:,.*)?)$')

def xlat(ptr, ind, out):
    """emit instructions translating a guest pointer into the host address (only the low guest space moves)"""
    a, d, c, o, h, p = (tmp() for _ in range(6))
    out.append(f'{ind}{a} = ptrtoint ptr {ptr} to i32')
    out.append(f'{ind}{d} = sub i32 {a}, {GUEST_LO}')
    out.append(f'{ind}{c} = icmp ult i32 {d}, {GUEST_SIZE}')
    out.append(f'{ind}{o} = select i1 {c}, i32 {GUEST_DELTA}, i32 0')
    out.append(f'{ind}{h} = add i32 {a}, {o}')
    out.append(f'{ind}{p} = inttoptr i32 {h} to ptr')
    return p

def split_args(s):
    parts = []; depth = 0; cur = ''
    for ch in s:
        if ch in '([{': depth += 1
        elif ch in ')]}': depth -= 1
        if ch == ',' and depth == 0: parts.append(cur); cur = ''
        else: cur += ch
    if cur.strip(): parts.append(cur)
    return parts

def native_pointer(ptr, tainted, defined):
    """True if the pointer operand is (derived from) the address of a global defined in this module: such objects (private
    switch/lookup tables, static data) are only touched by this module's own code and stay in native byte order."""
    if ptr in tainted: return True
    return any(g in ptr for g in defined)

def rewrite(text):
    # MSVC-compatible clang turns volatile accesses into atomic acquire/release ones: plain volatile accesses are what the swapping below understands
    text = re.sub(r'(load|store) atomic volatile', r'\1 volatile', text)
    text = re.sub(r' (?:acquire|release|seq_cst|monotonic|unordered|acq_rel)(?=, align)', '', text)
    text = re.sub(r'(load|store) atomic ', r'\1 ', text)
    out = []
    used = set()
    lines = text.split('\n')
    defined = {m.group(1) for m in (DEF_GLOBAL.match(l) for l in lines) if m}
    BSW = re.compile(r'(%[\w.\-$]+) = (?:tail )?call i(?:16|32|64) @llvm\.bswap\.i(?:16|32|64)\(i(?:16|32|64) (%[\w.\-$]+)\)')
    bswap_res, bswap_arg = set(), set()
    for l in lines:
        mb = BSW.search(l)
        if mb: bswap_res.add(mb.group(1)); bswap_arg.add(mb.group(2))
    use_count = {}
    for l in lines:
        for nm in set(re.findall(r'%[\w.\-$]+', l)): use_count[nm] = use_count.get(nm, 0) + 1
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
    stack = set()
    changed = True
    while changed:                      # addresses of stack objects never need translating
        changed = False
        for l in lines:
            ma = ALLOCA.match(l)
            if ma and ma.group(1) not in stack: stack.add(ma.group(1)); changed = True; continue
            m = DEF_RE.match(l)
            if not m or m.group(1) in stack: continue
            rhs = m.group(2)
            if re.match(r'(getelementptr|bitcast)\b', rhs) and any(re.search(re.escape(t) + r'(?![\w.\-$])', rhs) for t in stack):
                stack.add(m.group(1)); changed = True
    for line in lines:
        mc = CALL.match(line)
        if mc:
            ind0, head, callee, argtxt, tail0 = mc.groups()
            if callee.startswith('llvm.mem') or callee in LIBC_PTR_CALLS:
                args = split_args(argtxt); newargs = []
                for a in args:
                    ma = re.match(r'^(\s*ptr(?:\s+[a-z_]+(?:\s+\d+|\([a-z0-9]+\))?)*\s+)(%[\w.\-$]+|@[\w.\-$"]+|null)\s*$', a)
                    if ma and ma.group(2) not in stack and ma.group(2) != 'null' and not native_pointer(ma.group(2), tainted, defined):
                        np_ = xlat(ma.group(2), ind0, out); a = ma.group(1) + np_
                    newargs.append(a)
                out.append(f'{ind0}{head}{",".join(newargs)}){tail0}')
                continue
        m = LOAD.match(line)
        if m:
            ind, dst, vol, ty, ptr, al, rest = m.groups()
            vol = vol or ''
            if native_pointer(ptr, tainted, defined):
                out.append(line); continue
            rest = re.sub(r',\s*!(nonnull|align|dereferenceable|dereferenceable_or_null|noundef|range)\s+!\d+', '', rest)
            if ptr not in stack: ptr = xlat(ptr, ind, out)
            if ty == 'i8':                           # bytes need no swapping, only the pointer translation
                out.append(f'{ind}{dst} = load {vol}{ty}, ptr {ptr}, align {al}{rest}'); continue
            if ty in INT_BITS and al == '1' and (ALIGN1_RAW or (dst in bswap_arg and use_count.get(dst, 0) <= 2)):          # a load LLVM synthesised from byte loads (host little-endian idiom): its bytes already mean what the code wants
                out.append(f'{ind}{dst} = load {vol}{ty}, ptr {ptr}, align {al}{rest}'); continue
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
                pend = after.index(', align') if ', align' in after else len(after)
                if after[:pend] not in stack:
                    after = xlat(after[:pend], ind, out) + after[pend:]
                if ty == 'i8':
                    out.append(f'{ind}store {vol}{ty} {val}, ptr {after}')
                elif ty in INT_BITS and re.search(r'align 1\b', after) and val.strip() in bswap_res:
                    out.append(f'{ind}store {vol}{ty} {val}, ptr {after}')
                elif ty in INT_BITS:
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
        if re.search(r'^declare [^@]*@llvm\.bswap\.' + re.escape(ty) + r'\(', text, re.M): continue      # the source already uses __builtin_bswap
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
