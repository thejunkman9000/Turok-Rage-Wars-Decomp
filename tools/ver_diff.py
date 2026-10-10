#!/usr/bin/env python3
"""Which functions of our US v1.1 (us-rev1) build are identical in another version of the game?

usage: python tools/ver_diff.py [us|eu|de] [--list]
Data: melalawi/ragewars-decomp (CC0) versions/<ver>/slices.mk gives, per unit name, VMA:ROM:size in every version; unit names are shared across
versions (named after the first version they appear in).  For every unit that exists in both us-rev1 and <ver> with the same size the code
bytes are compared: `exact` (byte-identical), `reloc` (same instructions, only j/jal targets and lui/addiu/load/store immediates differ:
the same C source reproduces it once the version's symbol addresses are used), `diff` (real code difference).
`missing`/`size` = no counterpart / different length (version-specific code).
ROMs: baserom.us.v11.z64 (us-rev1), baserom.us.v10.z64 (us), baserom.eu.z64, baserom.de.z64 (project root, never committed)."""
import re, struct, collections, sys
base = 'D:/Projects/ext/ragewars-decomp/versions'
def slices(v):
    d = {}
    for l in open(f'{base}/{v}/slices.mk'):
        m = re.match(r'\S+\.U\.(\S+) := (0x[0-9A-Fa-f]+):(0x[0-9A-Fa-f]+):(0x[0-9A-Fa-f]+)', l)
        if m: d[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16), int(m.group(4), 16))
    return d
roms = {'us-rev1': 'baserom.us.v11.z64', 'us': 'baserom.us.v10.z64', 'eu': 'baserom.eu.z64', 'de': 'baserom.de.z64'}
def cls(a, b):
    if a == b: return 'exact'
    for x, y in zip(struct.unpack('>%dI' % (len(a) // 4), a), struct.unpack('>%dI' % (len(b) // 4), b)):
        if x == y: continue
        op = x >> 26
        if op != y >> 26: return 'diff'
        if op in (2, 3): continue
        if op in (0x0F, 0x09, 0x23, 0x2B, 0x21, 0x25, 0x20, 0x24, 0x29, 0x28, 0x31, 0x39, 0x35, 0x3D, 0x0D, 0x0C, 0x08):
            if (x >> 16) != (y >> 16): return 'diff'
            continue
        return 'diff'
    return 'reloc'
if __name__ == '__main__':
    vers = [a for a in sys.argv[1:] if not a.startswith('--')] or ['us', 'eu', 'de']
    S = {v: slices(v) for v in ['us-rev1'] + vers}
    R = {v: open(roms[v], 'rb').read() for v in ['us-rev1'] + vers}
    for v in vers:
        cnt = collections.Counter(); insn = collections.Counter(); out = []
        for n, (vma, rom, sz) in S['us-rev1'].items():
            if sz % 4 or sz == 0 or vma < 0x80200000: continue
            if n not in S[v]: c = 'missing'
            else:
                vma2, rom2, sz2 = S[v][n]
                c = 'size' if sz2 != sz else cls(R['us-rev1'][rom:rom + sz], R[v][rom2:rom2 + sz])
            cnt[c] += 1; insn[c] += sz // 4; out.append((n, c, vma, rom, S[v].get(n)))
        print(v, dict(cnt), dict(insn))
        if '--list' in sys.argv:
            for r in out: print(*r)
