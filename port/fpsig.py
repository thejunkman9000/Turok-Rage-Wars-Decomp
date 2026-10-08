#!/usr/bin/env python3
"""Signatures of functions that take or return floating point values, collected from the C prototypes in the tree
(headers, matching sources, drafts).  The statically recompiled code needs them for the MIPS o32 float calling convention:
  fpsig[name] = (ret, [param types])   with types 'i' (integer / pointer), 'f' (float), 'd' (double), '?' (struct by value etc.)"""
import glob, re, os

_DEF = re.compile(r'^((?:static\s+)?(?:const\s+)?[A-Za-z_]\w*(?:\s*\*+)?)\s+\**\s*([A-Za-z_]\w*)\s*\(([^;{}()]*(?:\([^;{}()]*\)[^;{}()]*)*)\)\s*\{', re.M)
_PAT = re.compile(r'^[ \t]*((?:extern\s+|static\s+)?(?:const\s+)?[A-Za-z_]\w*(?:\s*\*+)?)\s+\**\s*([A-Za-z_]\w*)\s*\(([^;{}()]*(?:\([^;{}()]*\)[^;{}()]*)*)\)\s*;', re.M)

def ptype(p):
    p = p.strip()
    if not p or p == 'void': return None
    if '...' in p: return '?'
    if '*' in p or '[' in p or '(' in p: return 'i'
    words = re.findall(r'\w+', p)
    if len(words) >= 2: words = words[:-1]           # drop the parameter name
    t = ' '.join(w for w in words if w not in ('const', 'volatile', 'register', 'struct', 'unsigned', 'signed'))
    if t in ('f32', 'float'): return 'f'
    if t in ('f64', 'double'): return 'd'
    if t in ('s8', 'u8', 's16', 'u16', 's32', 'u32', 'int', 'short', 'char', 'long', 'size_t', 'OSId', 'OSPri', 'OSIntMask', 'bool'): return 'i'
    if t in ('s64', 'u64', 'OSTime', 'long long'): return '?'
    if re.match(r'^(Vec3f|Vec3|Mtx|MtxF|[A-Z]\w+)$', t) and t not in ('OSId', 'OSPri'): return '?'   # struct/typedef by value (unknown): unsupported
    return 'i'

def rtype(r):
    r = r.replace('extern', '').replace('static', '').replace('const', '').strip()
    if '*' in r: return 'i'
    if r in ('f32', 'float'): return 'f'
    if r in ('f64', 'double'): return 'd'
    if r == 'void': return 'v'
    if r in ('s64', 'u64', 'OSTime'): return 'l'
    if re.match(r'^(struct\s+)?(Vec\w*|\w*Vec\d\w*)$', r): return 's'                  # struct returned by value: a hidden result pointer comes first
    return 'i'

def load():
    sig = {}
    files = glob.glob('src/**/*.c', recursive=True) + glob.glob('include/*.h') + glob.glob('port/nonmatching/*.c') + glob.glob('port/*.h')
    for d in glob.glob('D:/Projects/ws/*/include'):
        files += glob.glob(d + '/*.h')
    for p in files:
        try: t = open(p, errors='replace').read()
        except OSError: continue
        for m in list(_PAT.finditer(t)) + list(_DEF.finditer(t)):
            rt, name, params = m.group(1), m.group(2), m.group(3)
            if '*' in m.group(0)[:m.start(2) - m.start(0)]: rt = 'void *'          # the pointer star can sit between the type and the name: pointer return
            if not re.search(r'\b(f32|f64|float|double)\b', rt + ' ' + params): continue
            if name in sig: continue
            ps = []
            depth = 0; cur = ''
            for ch in params:
                if ch == '(': depth += 1
                if ch == ')': depth -= 1
                if ch == ',' and depth == 0: ps.append(cur); cur = ''
                else: cur += ch
            if cur.strip(): ps.append(cur)
            types = [ptype(x) for x in ps]
            types = [t for t in types if t is not None]
            rr = rtype(rt)
            if rr == 's': rr = 'v'; types = ['i'] + types
            sig[name] = (rr, types)
    return sig

if __name__ == '__main__':
    s = load()
    print(len(s), 'floating point signatures')
    for k in list(s)[:8]: print(k, s[k])
