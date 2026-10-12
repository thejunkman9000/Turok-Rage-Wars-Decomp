#!/usr/bin/env python3
"""Struct-by-value arguments: one convention whatever the field types (run by be_ir.rewrite before the byte-order rewrite).

On 32-bit x86 (x86-windows-msvc) clang passes a struct whose fields are all 32-bit (s32, f32, pointers) as separate scalar arguments,
and any other struct (one with a s16 / u8 field) as a `byval` copy in memory.  The scalars are native values, the byval copy is big-endian
memory (be_ir swaps every store).  The game's sources often declare the same 8-byte argument differently on the two sides of a call -
`{ s32 a; s32 b; }` in the caller, `{ s16 a; s16 b; s32 c; }` in the callee - which on the N64 is the same bytes in the same registers / stack
words, but in the port the callee then reads the halves of a native word from a byte-swapped place: func_002476B8 sent the weapon-fire
event key 0x00000655 and the sound handler func_00267324 read sound id 0 (silent weapons).

Rewrite: every `ptr byval(%T) align A %p` argument (size a multiple of 4) becomes one i32 per word of the struct, at call sites (loaded from
the copy - be_ir turns the loads into big-endian reads, i.e. the word's value) and in definitions (stored into a fresh stack copy that the
body uses instead of the pointer - big-endian stores).  Both conventions now pass the same native word values in the same stack slots."""
import re, os

SCALAR = {'i1': (1, 1), 'i8': (1, 1), 'i16': (2, 2), 'i32': (4, 4), 'i64': (8, 8), 'float': (4, 4), 'double': (8, 8), 'ptr': (4, 4)}
TYPEDEF = re.compile(r'^(%[\w.\-$"]+) = type (<?\{.*\}>?|opaque)\s*$')
ID_END = r'(?![\w.\-$])'


def _split_top(s):
    out, depth, cur = [], 0, ''
    for ch in s:
        if ch in '{[<(': depth += 1
        elif ch in '}]>)': depth -= 1
        if ch == ',' and depth == 0: out.append(cur); cur = ''
        else: cur += ch
    if cur.strip(): out.append(cur)
    return [x.strip() for x in out]


class Types:
    def __init__(self, text):
        self.defs = {}
        for l in text.split('\n'):
            m = TYPEDEF.match(l)
            if m: self.defs[m.group(1)] = m.group(2)
        self.cache = {}

    def layout(self, t):
        """(size, align) of an LLVM type with the x86-32 MSVC data layout (i64 / double aligned to 8), None if unknown"""
        t = t.strip()
        if t in SCALAR: return SCALAR[t]
        if t in self.cache: return self.cache[t]
        if t.startswith('%'):
            body = self.defs.get(t)
            if body is None or body == 'opaque': return None
            r = self.layout(body)
            self.cache[t] = r
            return r
        m = re.match(r'^\[(\d+) x (.*)\]$', t)
        if m:
            e = self.layout(m.group(2))
            return None if e is None else (int(m.group(1)) * e[0], e[1])
        packed = t.startswith('<{')
        if t.startswith('{') or packed:
            inner = t[2:-2] if packed else t[1:-1]
            off, al = 0, 1
            for f in _split_top(inner):
                e = self.layout(f)
                if e is None: return None
                fa = 1 if packed else e[1]
                off = (off + fa - 1) // fa * fa + e[0]
                al = max(al, fa)
            return ((off + al - 1) // al * al, al)
        return None


BYVAL = re.compile(r'^ptr\b(.*?)\bbyval\((%[\w.\-$"]+|<?\{.*?\}>?|\[.*?\])\)(.*?)(%[\w.\-$]+)?\s*$')


def _words(types, ty):
    lay = types.layout(ty)
    if lay is None or lay[0] == 0 or lay[0] % 4: return None
    return lay[0] // 4


def _align(attrs):
    m = re.search(r'\balign (\d+)', attrs)
    return min(int(m.group(1)), 4) if m else 4


def _arglist_span(line, start):
    """index of the ')' closing the '(' at line[start]"""
    depth = 0
    for i in range(start, len(line)):
        c = line[i]
        if c in '([{<': depth += 1
        elif c in ')]}>': depth -= 1
        if depth == 0: return i
    return -1


# Functions whose 40-byte UI context argument keeps the old big-endian image: the recompiler byte-swaps the struct words when a twin calls
# them (port/mips2c.py STRUCTARGS, port/recomp_structargs.txt), so their byval copies must stay memory images.  Same for calls through a
# pointer that carry a struct of that size (the UI callbacks).  Converting them broke the Controller Pak hot-swap screen (paktest hotswap).
_STRUCTARGS = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'recomp_structargs.txt')
KEEP = set(open(_STRUCTARGS).read().split()) if os.path.exists(_STRUCTARGS) else set()
KEEP_INDIRECT_SIZE = 40


def _skip(name):
    """PORT_BYVAL_SKIP=re1,re2,...: also leave matching definitions / direct calls (INDIRECT = calls through pointers) alone (bisecting aid)"""
    if name in KEEP: return True
    if re.match(r'func_(004|804)[0-9A-Fa-f]{5}(_de)?$', name): return True     # overlay A (the menus): the recompiled twins that call it pass the
                                                                                # struct words in the old convention; converting it lost the main-menu text
    pats = os.environ.get('PORT_BYVAL_SKIP')
    return bool(pats) and any(re.match(p_, name) for p_ in pats.split(','))


def rewrite(text):
    if 'byval(' not in text: return text
    types = Types(text)
    lines = text.split('\n')
    out = []
    n = [0]
    touched = set()
    fn_renames = None           # inside a converted definition: {old pointer name: new name}
    pending_entry = None        # lines to insert after the define's '{'

    def conv_params(params, is_define):
        new, entry, renames = [], [], {}
        for p in params:
            m = BYVAL.match(p)
            w = _words(types, m.group(2)) if m else None
            if not m or w is None:
                new.append(p); continue
            if not is_define:
                new.extend(['i32'] * w); continue
            name = m.group(4)
            if not name:
                new.append(p); continue
            base = 'byv' + name[1:].replace('"', '').replace('.', '_')
            # the first word keeps the parameter's own name (numbered names must stay in sequence), the pointer gets a new one
            wnames = [name] + ['%%%s.w%d' % (base, k) for k in range(1, w)]
            new.extend('i32 ' + x for x in wnames)
            ptr = '%' + base + '.p'
            al = _align(m.group(1) + m.group(3))
            entry.append('  %s = alloca [%d x i8], align 4' % (ptr, 4 * w))
            for k, x in enumerate(wnames):
                if k == 0: dst = ptr
                else:
                    dst = '%%%s.g%d' % (base, k)
                    entry.append('  %s = getelementptr inbounds i8, ptr %s, i32 %d' % (dst, ptr, 4 * k))
                entry.append('  store i32 %s, ptr %s, align %d' % (x, dst, al))
            renames[name] = ptr
        return new, entry, renames

    for line in lines:
        if line.startswith('define ') or line.startswith('declare '):
            is_def = line.startswith('define ')
            at = line.find('@')
            lp = line.find('(', at)
            rp = _arglist_span(line, lp) if lp >= 0 else -1
            if lp >= 0 and rp > lp and 'byval(' in line[lp:rp]:
                params = _split_top(line[lp + 1:rp])
                if '...' not in params and not _skip(line[at + 1:lp]):
                    new, entry, renames = conv_params(params, is_def)
                    line = line[:lp + 1] + ', '.join(new) + line[rp:]
                    if is_def:
                        fn_renames, pending_entry = renames, entry
                        if renames: touched.add('def:' + line[at + 1:lp])
            out.append(line)
            if is_def and pending_entry is not None and line.rstrip().endswith('{'):
                out.extend(pending_entry); pending_entry = None
            continue
        if fn_renames:
            if line == '}':
                fn_renames = None
            else:
                for old, new in fn_renames.items():
                    line = re.sub(re.escape(old) + ID_END, new, line)
        if 'byval(' in line and re.search(r'\bcall\b', line):
            mcall = re.search(r'\bcall\b', line)
            # the argument list is the last top-level '(...)' before the attribute group / metadata
            lp = None
            depth = 0
            i = mcall.end()
            # find the callee: '@name(' or '%ptr('
            mcallee = re.compile(r'(@[\w.\-$"]+|%[\w.\-$]+)\(').search(line, i)
            if mcallee:
                lp = mcallee.end() - 1
                rp = _arglist_span(line, lp)
                args = _split_top(line[lp + 1:rp])
                callee = mcallee.group(1)
                if '...' not in line[i:lp] and not _skip(callee[1:] if callee.startswith('@') else 'INDIRECT'):
                    ind = re.match(r'^(\s*)', line).group(1)
                    newargs, pre = [], []
                    for a in args:
                        m = BYVAL.match(a)
                        w = _words(types, m.group(2)) if m else None
                        if m and w is not None and callee.startswith('%') and 4 * w == KEEP_INDIRECT_SIZE: w = None
                        if not m or w is None or not m.group(4):
                            newargs.append(a); continue
                        p = m.group(4); al = _align(m.group(1) + m.group(3))
                        n[0] += 1
                        for k in range(w):
                            src = p
                            if k:
                                src = '%%byvc%d.g%d' % (n[0], k)
                                pre.append('%s%s = getelementptr inbounds i8, ptr %s, i32 %d' % (ind, src, p, 4 * k))
                            v = '%%byvc%d.w%d' % (n[0], k)
                            pre.append('%s%s = load i32, ptr %s, align %d' % (ind, v, src, al))
                            newargs.append('i32 ' + v)
                    if pre:
                        touched.add('call:' + line[mcallee.start() + 1:mcallee.end() - 1])
                        out.extend(pre)
                        line = line[:lp + 1] + ', '.join(newargs) + line[rp:]
        out.append(line)
    log = os.environ.get('PORT_BYVAL_LOG')          # debugging aid: which definitions / calls were converted
    if log and touched:
        with open(log, 'a') as f: f.write(' '.join(sorted(touched)) + '\n')
    return '\n'.join(out)
