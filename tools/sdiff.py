#!/usr/bin/env python3
"""Alignment-aware diff of our compiled function against the ROM function (run in WSL, cwd ~/trw): only the differing instruction blocks are printed,
inserted or missing instructions do not shift the rest (difflib on the instruction words; relocated fields are masked like chk does).

usage: python3 tools/sdiff.py <src.c> <cc mode e.g. sn+sa+r4k+epi> <function> <rom hex> <n insns>"""
import difflib, os, re, subprocess, sys, tempfile
src, mode, fn, rom_hex, n = sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4], 16), int(sys.argv[5])
obj = tempfile.mktemp(suffix='.o')
r = subprocess.run(['bash', 'tools/cc.sh', mode, src, obj], capture_output=True, text=True)
if r.returncode: print(r.stderr[-800:]); sys.exit(1)
def dis(args, flag='-d'):
    cmd = ['mips-linux-gnu-objdump', flag] + (['-j', '.text'] if flag == '-d' else []) + ['-M', 'no-aliases,reg-names=numeric'] + args
    out = subprocess.run(cmd, capture_output=True, text=True).stdout
    res = []
    for l in out.split('\n'):
        m = re.match(r'\s*[0-9a-f]+:\s+([0-9a-f]{8})\s+(.*)', l)
        if m: res.append((int(m.group(1), 16), re.sub(r'\s+', ' ', m.group(2)).strip()))
    return res
ours = dis([obj])
masks = {}
rel = subprocess.run(['mips-linux-gnu-readelf', '-rW', obj], capture_output=True, text=True).stdout
intext = False
for l in rel.split('\n'):
    if l.startswith('Relocation section'): intext = "'.rel.text'" in l; continue
    m = re.match(r'([0-9a-f]{8})\s+[0-9a-f]+\s+(R_MIPS_\w+)', l.strip())
    if intext and m: masks[int(m.group(1), 16) // 4] = 0xFC000000 if m.group(2) == 'R_MIPS_26' else 0xFFFF0000
rom = open(os.environ.get('ROM', 'baserom.us.v11.z64'), 'rb').read()[rom_hex:rom_hex + 4 * n + 64]
tmp = tempfile.mktemp(suffix='.bin'); open(tmp, 'wb').write(rom)
theirs = dis(['-b', 'binary', '-EB', '-mmips:4000', tmp], '-D')[:n]
A = [w & masks.get(i, 0xFFFFFFFF) for i, (w, t) in enumerate(ours)]
B = [w for w, t in theirs]
# the ROM words keep their relocated fields: mask the same positions (the instruction indices are not aligned after an insertion, so mask by opcode class instead)
def norm(w):
    op = w >> 26
    if op in (2, 3): return w & 0xFC000000                      # j / jal target
    if op == 15: return w & 0xFFFF0000                          # lui (%hi)
    return w
A = [norm(w) if (w >> 26) in (2, 3) else (w & masks.get(i, 0xFFFFFFFF)) for i, (w, t) in enumerate(ours)]
B = [norm(w) if (w >> 26) in (2, 3) else w for w in B]
sm = difflib.SequenceMatcher(None, A, B, autojunk=False)
print('ours %d insns, rom %d' % (len(ours), len(theirs)))
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal': continue
    print('%s ours[%d:%d] rom[%d:%d]' % (tag, i1, i2, j1, j2))
    for k in range(i1, min(i2, i1 + 30)): print('   - %4d %s' % (k, ours[k][1][:60]))
    for k in range(j1, min(j2, j1 + 30)): print('   + %4d %s' % (k, theirs[k][1][:60]))
