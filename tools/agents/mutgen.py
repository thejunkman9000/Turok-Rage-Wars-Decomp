#!/usr/bin/env python3
"""mutgen.py <base.c> <fn> <rom> <kind> [flags...]
kind = wrap   (do { stmt } while (0);)
       swap   (swap a statement with the next simple statement)
       retype (change the type of a local declaration)
       asm    (insert an empty `__asm__("" : "+r"(x))` after an assignment to x)
Writes the variants (full file texts) to $DUPSPEC (default wip/vx/dup_spec.py) for tools/rvfull.py."""
import sys, re, os
base, fn, rom, kind = sys.argv[1:5]
flags = ' '.join(sys.argv[5:]) or '@SN'
src = open(base).read()
i = re.search(r'^[A-Za-z_][\w \*]*\b' + fn + r'\s*\(', src, re.M).start()
lines = src[i:].split('\n')

def simple(st):
    if not st.endswith(';'):
        return False
    if st.startswith(('return', 'break', 'goto', 'case', 'default', 'else', 'do', 'while', 'for', 'if', '}', '{', '#', 'register', '__asm', 'asm')):
        return False
    return '=' in st or re.match(r'^\w+\(.*\);$', st) is not None

decl = re.compile(r'^\s*(u8|u16|u32|s8|s16|s32|f32|f64|void|static|extern|register|struct|typedef|char|short|int|unsigned|SndMgr|M04\w*|B\d+\w*|S7\w*)\b[^=(]*;\s*$')
V = []
names = {}
idxs = [k for k, l in enumerate(lines) if simple(l.strip()) and not decl.match(l) and ':' not in l.split('=')[0]]
if kind == 'wrap':
    for k in idxs:
        new = list(lines)
        l = lines[k]
        ind = l[:len(l) - len(l.lstrip())]
        new[k] = ind + 'do { ' + l.strip() + ' } while (0);'
        V.append(src[:i] + '\n'.join(new))
        names[len(V) - 1] = 'wrap@%d: %s' % (k, l.strip()[:40])
elif kind == 'swap':
    for a, b in zip(idxs, idxs[1:]):
        if b != a + 1:
            continue
        new = list(lines)
        new[a], new[b] = lines[b], lines[a]
        V.append(src[:i] + '\n'.join(new))
        names[len(V) - 1] = 'swap@%d: %s | %s' % (a, lines[a].strip()[:30], lines[b].strip()[:30])
elif kind == 'retype':
    types = ['s32', 'u32', 's16', 'u16', 'u8', 's8', 'short', 'int']
    dl = re.compile(r'^(\s*)(s32|u32|s16|u16|u8|s8|short|int|unsigned int|unsigned|char)\s+([A-Za-z_]\w*)\s*;\s*$')
    for k, l in enumerate(lines):
        m = dl.match(l)
        if not m:
            continue
        for ty in types:
            if ty == m.group(2):
                continue
            new = list(lines)
            new[k] = '%s%s %s;' % (m.group(1), ty, m.group(3))
            V.append(src[:i] + '\n'.join(new))
            names[len(V) - 1] = 'retype %s %s->%s' % (m.group(3), m.group(2), ty)
elif kind == 'asm':
    asg = re.compile(r'^(\s*)([A-Za-z_]\w*)\s*=[^=].*;\s*$')
    for k in idxs:
        m = asg.match(lines[k])
        if not m:
            continue
        new = list(lines)
        new.insert(k + 1, '%s__asm__("" : "+r"(%s));' % (m.group(1), m.group(2)))
        V.append(src[:i] + '\n'.join(new))
        names[len(V) - 1] = 'asm after %s' % lines[k].strip()[:40]
print(len(V), 'variants')
out = os.environ.get('DUPSPEC', 'wip/vx/dup_spec.py')
open(out, 'w').write('BASE=%r\nFN=%r\nROM=%r\nFLAGS=%r\nNAMES=%r\nVARIANTS=[]\nFULL=%r\n' % (base, fn, rom, flags, names, V))
