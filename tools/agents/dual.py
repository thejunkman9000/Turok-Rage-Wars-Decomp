#!/usr/bin/env python3
"""dual.py <file.c> <fn> <rom hex> <nrom> [flags...] : writes /tmp/ours.lst and /tmp/rom.lst (numbered insns, branch targets as #index).  Run in WSL at the workspace root."""
import sys, os, re, subprocess
a = sys.argv[1:]
path, func, rom_hex, nrom = a[0], a[1], int(a[2], 16), int(a[3])
flags = a[4:] or ['@SN']
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
os.chdir('/mnt/d/Projects/ws/s901')
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
extra[:] = flags
ROOTD = os.path.expanduser('~/trw_s901')
import shutil
dst = f'{ROOTD}/{path}'
os.makedirs(os.path.dirname(dst), exist_ok=True)
shutil.copy(path, dst)
res, err = compile_funcs(dst)
if res is None: print('COMPILE FAIL', err); sys.exit(1)
text, syms, relocs, relnames = res
name, off, size = [s for s in syms if s[0] == func][0]
ours = text[off:off + size]
romb = rom[rom_hex:rom_hex + 4 * nrom]
VRAM = rom_hex + 0x1FF400 if rom_hex < 0x16E000 else rom_hex - 0x16E000 + 0x400000
def dis(b, tag, relw):
    p = f'/tmp/_dual_{tag}.bin'
    open(p, 'wb').write(b)
    o = subprocess.run(['mips-linux-gnu-objdump', '-D', '-z', '-b', 'binary', '-mmips:4000', '-EB', '--no-show-raw-insn', '-M', 'no-aliases', p],
                       capture_output=True, text=True).stdout
    L = []
    for l in o.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\t(.*)', l)
        if m: L.append((int(m.group(1), 16) // 4, m.group(2).replace('\t', ' ').strip()))
    out = []
    for i, t in L:
        mm = re.match(r'(b\w+|j) (.*?)(0x[0-9a-f]+)$', t)
        if mm and mm.group(1) not in ('break',):
            tgt = int(mm.group(3), 16)
            if mm.group(1) == 'j':
                t = 'j #%d' % ((tgt - VRAM) // 4 if tgt >= 0x200000 else tgt // 4)
            else:
                t = mm.group(1) + ' ' + mm.group(2) + '#%d' % (tgt // 4)
        if i in relw:
            t = re.sub(r'(-?0x[0-9a-f]+|-?\d+)(\(|$)', r'R\2', t) if not t.startswith(('j', 'b')) else t
        out.append('%4d %s' % (i, t))
    return out
relw = set((o - off) // 4 for o in relocs if off <= o < off + size)
open('/tmp/ours.lst', 'w').write('\n'.join(dis(ours, 'o', relw)) + '\n')
open('/tmp/rom.lst', 'w').write('\n'.join(dis(romb, 'r', set())) + '\n')
print('ours', size // 4, 'rom', nrom)
