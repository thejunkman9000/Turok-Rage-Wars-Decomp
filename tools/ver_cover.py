#!/usr/bin/env python3
"""How much of our US v1.1 work carries over to the other releases?  python tools/ver_cover.py [--json out.json]

For every game-code function of the US v1.1 build (docs/game_funcs.txt) the same function is looked up in another release through the
other public decompilation's symbol tables (melalawi/ragewars-decomp versions/<ver>/symbol_addrs.txt: the same names in every
release, with that release's addresses) and its code is compared with ours: `exact` (identical bytes), `reloc` (same instructions,
other j/jal targets / symbol addresses, i.e. our C reproduces it when built with the release's addresses), `diff` (other code),
`none` (no counterpart).  Everything is weighted by instructions.  Needs the ROMs in the project root (never committed):
baserom.us.v11.z64 / baserom.us.v10.z64 / baserom.eu.z64 / baserom.de.z64."""
import json, os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ver_diff

THEIRS = 'D:/Projects/ext/ragewars-decomp/versions'
ROMS = {'us-rev1': 'baserom.us.v11.z64', 'us': 'baserom.us.v10.z64', 'eu': 'baserom.eu.z64', 'de': 'baserom.de.z64'}
LABEL = {'us-rev1': 'US v1.1 (rev 1)', 'us': 'US v1.0', 'eu': 'Europe', 'de': 'Germany'}

def func_syms(v):
    """name -> VMA of every function symbol of release v"""
    d = {}
    for l in open(f'{THEIRS}/{v}/symbol_addrs.txt'):
        m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+);\s*//\s*type:func', l)
        if m: d[m.group(1)] = int(m.group(2), 16)
    return d

def vma_map(v):
    """[(vma, rom, size)] from the MAP line of slices.mk"""
    for l in open(f'{THEIRS}/{v}/slices.mk'):
        if l.startswith(f'{v}.MAP :='):
            out = []
            for t in l.split(':=', 1)[1].split():
                a = t.split(':')
                if len(a) == 3: out.append(tuple(int(x, 16) for x in a))
            return out
    return []

def to_rom(maps, vma):
    for a, r, s in maps:
        if a >= 0x80000000 and a <= vma < a + s: return r + vma - a
    return None

def our_functions():
    fs = []
    for l in open('docs/game_funcs.txt'):
        f = l.split()
        if len(f) >= 3 and f[1].startswith('func_'): fs.append((f[1], int(f[0], 16), int(f[2])))
    return fs

def matched_names():
    done = {}
    for fn in ('funcs.txt', 'funcs_a.txt'):
        for l in open(fn):
            f = l.split('#')[0].split()
            if len(f) >= 4 and not f[0].startswith('pad_') and f[3] in ('game', 'ovl_a'): done[f[0]] = int(f[2])
    return done

def compute(vers=('us', 'eu', 'de'), done_names=None):
    fs = our_functions(); done = done_names if done_names is not None else matched_names()      # done_names: matched functions by ROM range (tools/progress_chart.py)
    base = open(ROMS['us-rev1'], 'rb').read()
    inv = {}
    for n, a in func_syms('us-rev1').items():
        if n.startswith('func_') or n not in inv.values(): inv.setdefault(a, n)
    res = {}
    tot = sum(i for _, _, i in fs)
    m_insn = sum(i for n, _, i in fs if n in done)
    res['us-rev1'] = {'label': LABEL['us-rev1'], 'total': tot, 'matched': m_insn, 'functions': len(fs)}
    for v in vers:
        rom = open(ROMS[v], 'rb').read() if os.path.exists(ROMS[v]) else None
        if rom is None: continue
        syms = func_syms(v); maps = vma_map(v)
        cnt = {'exact': [0, 0], 'reloc': [0, 0], 'diff': [0, 0], 'none': [0, 0]}      # [matched insns, unmatched insns]
        for name, r1, insns in fs:
            vma1 = 0x80000000 | int(name[5:], 16)
            their = inv.get(vma1)
            c = 'none'
            if their in syms:
                r2 = to_rom(maps, syms[their])
                if r2 is not None and r2 + insns * 4 <= len(rom):
                    c = ver_diff.cls(base[r1:r1 + insns * 4], rom[r2:r2 + insns * 4])
            cnt[c][0 if name in done else 1] += insns
        sl = ver_diff.slices(v); s1 = ver_diff.slices('us-rev1')
        only = sum(sz // 4 for n, (vma, r, sz) in sl.items() if sz % 4 == 0 and vma >= 0x80200000 and n not in s1)
        res[v] = {'label': LABEL[v], 'total': tot, 'classes': cnt, 'own_only_insns': only}
    return res

if __name__ == '__main__':
    r = compute()
    for v, d in r.items():
        if v == 'us-rev1':
            print(v, d); continue
        c = d['classes']
        reuse = sum(c[k][0] for k in ('exact', 'reloc')); same = sum(c[k][0] + c[k][1] for k in ('exact', 'reloc'))
        print(f"{v}: identical {same} insns ({100 * same / d['total']:.1f}%), reusable from our C now {reuse} ({100 * reuse / d['total']:.1f}%), "
              f"diff {sum(c['diff'])}, none {sum(c['none'])}, release-only units {d['own_only_insns']}")
    if '--json' in sys.argv:
        json.dump(r, open(sys.argv[sys.argv.index('--json') + 1], 'w'), indent=1)
