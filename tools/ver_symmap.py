#!/usr/bin/env python3
"""Address map US v1.1 -> another release, recovered from the code itself (analysis only, no build).

usage: python tools/ver_symmap.py [us|eu|de] [--out wip/symmap_<ver>.txt]
For every unit that exists in both releases with the same size (melalawi/ragewars-decomp versions/<ver>/slices.mk gives VMA:ROM:size per unit name) the
instruction words are compared pairwise.  j/jal targets give function address pairs; `lui rt,hi` followed (within 8 instructions, same base register, no
redefinition) by an addiu/ori/load/store with the base rt gives data address pairs.  Every address of US v1.1 is expected to map to exactly one address of the
other release: conflicts are reported, and the (addr_other - addr_11) deltas are grouped into runs so the piecewise-constant data layout shift is visible.
Output file: `<addr 1.1> <addr other> <count>` per mapping."""
import collections, os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ver_diff
roms = ver_diff.roms
LOAD_STORE = (0x23, 0x2B, 0x21, 0x25, 0x20, 0x24, 0x29, 0x28, 0x31, 0x39, 0x35, 0x3D, 0x0D, 0x09, 0x0C, 0x08)      # lw sw lh lhu lb lbu sh sb lwc1 swc1 ldc1 sdc1 ori addiu andi addi

def sx(v): return v - 0x10000 if v & 0x8000 else v

def pairs(w1, w2, base1, base2):
    """yield (addr_a, addr_b) pairs found in two same-length instruction lists"""
    out = []
    n = len(w1)
    pending = {}      # reg -> (i, hi_a, hi_b)
    for i in range(n):
        a, b = w1[i], w2[i]
        op = a >> 26
        if op != b >> 26: continue
        if op in (2, 3):
            ta = ((a & 0x3FFFFFF) << 2) | (0x80000000 if True else 0); tb = ((b & 0x3FFFFFF) << 2) | 0x80000000
            if ta != tb: out.append((ta, tb))
            continue
        if op == 0x0F:                                   # lui
            rt = (a >> 16) & 31
            pending[rt] = (i, (a & 0xFFFF) << 16, (b & 0xFFFF) << 16)
            continue
        if op in LOAD_STORE:
            rs = (a >> 21) & 31; rt = (a >> 16) & 31
            if rs == ((b >> 21) & 31) and rs in pending and i - pending[rs][0] <= 8:
                _, ha, hb = pending[rs]
                if op in (0x0D, 0x0C):                    # ori / andi: unsigned immediate
                    la, lb = a & 0xFFFF, b & 0xFFFF
                else:
                    la, lb = sx(a & 0xFFFF), sx(b & 0xFFFF)
                aa, bb = (ha + la) & 0xFFFFFFFF, (hb + lb) & 0xFFFFFFFF
                if aa != bb or True: out.append((aa, bb))
        # a write to a pending register that is not part of the %lo use ends the window (loads overwrite their base too, handled above)
        if op != 0x2B and op != 0x28 and op != 0x29 and op != 0x31 and op != 0x39 and op != 0x35 and op != 0x3D and op >= 8:
            rt = (a >> 16) & 31
            if op in LOAD_STORE or op in (0x0F,): pending.pop(rt, None) if op != 0x0F else None
    return out

def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    ver = args[0] if args else 'us'
    outp = sys.argv[sys.argv.index('--out') + 1] if '--out' in sys.argv else f'wip/symmap_{ver}.txt'
    S = {v: ver_diff.slices(v) for v in ('us-rev1', ver)}
    R = {v: open(roms[v], 'rb').read() for v in ('us-rev1', ver)}
    m = collections.defaultdict(collections.Counter)
    nunits = 0
    for n, (vma, rom, sz) in S['us-rev1'].items():
        if sz % 4 or sz == 0 or vma < 0x80200000 or n not in S[ver]: continue
        vma2, rom2, sz2 = S[ver][n]
        if sz2 != sz: continue
        a = struct.unpack('>%dI' % (sz // 4), R['us-rev1'][rom:rom + sz]); b = struct.unpack('>%dI' % (sz // 4), R[ver][rom2:rom2 + sz])
        if ver_diff.cls(R['us-rev1'][rom:rom + sz], R[ver][rom2:rom2 + sz]) == 'diff': continue
        nunits += 1
        m[vma][vma2] += 1                                  # the unit itself
        for pa, pb in pairs(a, b, vma, vma2):
            m[pa][pb] += 1
    conflicts = [(k, c) for k, c in m.items() if len(c) > 1]
    os.makedirs(os.path.dirname(outp) or '.', exist_ok=True)
    with open(outp, 'w') as f:
        for k in sorted(m):
            for kb, cnt in m[k].most_common(): f.write(f'{k:08X} {kb:08X} {cnt}\n')
    print(f'{ver}: {nunits} units compared, {len(m)} distinct v1.1 addresses, {len(conflicts)} with more than one counterpart; written {outp}')
    # runs of constant delta (over the single-counterpart addresses, sorted)
    runs = []
    for k in sorted(m):
        d = m[k].most_common(1)[0][0] - k
        if runs and runs[-1][2] == d: runs[-1][1] = k
        else: runs.append([k, k, d])
    big = [r for r in runs if True]
    print(f'{len(runs)} runs of constant delta; first ones:')
    for r in runs[:12]: print(f'  {r[0]:08X}..{r[1]:08X} delta {r[2]:+d}')
    if conflicts:
        print('examples of conflicts:')
        for k, c in conflicts[:8]: print(f'  {k:08X} ->', ', '.join(f'{b:08X}x{n}' for b, n in c.most_common(4)))

if __name__ == '__main__': main()
