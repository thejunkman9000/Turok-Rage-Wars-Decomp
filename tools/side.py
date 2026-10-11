#!/usr/bin/env python3
"""Side-by-side disassembly of our compiled function and the ROM function, by instruction index (run in WSL, cwd ~/trw).

usage: python3 tools/side.py <src.c> <cc mode e.g. sn+sa+r4k+epi> <function> <rom hex> <n insns> [lo hi]
Differing lines are marked with `*` (relocated fields - jal targets, %hi/%lo - are masked like chk does); the first column is the instruction index.
The object is compiled like the real build (tools/cc.sh)."""
import os, re, struct, subprocess, sys, tempfile
src, mode, fn, rom_hex, n = sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4], 16), int(sys.argv[5])
lo, hi = (int(sys.argv[6]), int(sys.argv[7])) if len(sys.argv) > 7 else (0, 10 ** 9)
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
theirs = dis(['-b', 'binary', '-EB', '-mmips:4000', tmp], '-D')
print('ours %d insns, rom %d (shown)' % (len(ours), n))
bad = 0
for i in range(max(len(ours), n)):
    a = ours[i] if i < len(ours) else (0, '')
    b = theirs[i] if i < len(theirs) else (0, '')
    m = masks.get(i, 0xFFFFFFFF)
    d = (a[0] & m) != (b[0] & m)
    if d: bad += 1
    if lo <= i <= hi: print('%3d %s %08x %-34s | %08x %s' % (i, '*' if d else ' ', a[0], a[1][:34], b[0], b[1][:40]))
print('differing words:', bad)
