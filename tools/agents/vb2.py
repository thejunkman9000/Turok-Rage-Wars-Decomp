#!/usr/bin/env python3
"""vb.py - parallel variant evaluator for the @SN toolchain (run inside WSL from the workspace root).

usage: vb.py <fn> <rom hex> [--flags "@SN -fno-builtin"] [--top N] [--jobs N] [--keep] (--dir D | --file variants.txt | files...)
   variants.txt: full-file variants separated by lines starting with //====   (written to wip/vb/vN.c)
For each candidate file prints  structural operand exact  (aligned diff vs ROM; structural = inserted/deleted/changed-mnemonic insns,
operand = same mnemonic but different register/immediate; relocations masked).  exact=1 when chk-level EXACT.
The best candidate is copied to wip/vb_best.c.   Files are looked up relative to ~/trw_s905 (they are copied there first)."""
import sys, os, re, shutil, subprocess, difflib, struct, multiprocessing as mp

ROOT = '/mnt/d/Projects/ws/s905'
HOME_WS = os.path.expanduser('~/trw_s905')
_G = {}

def _init():
    sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
    os.chdir(ROOT)
    code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
    code = code.replace("for lo, hi, n in REGIONS: ROMW[n] = (lo, words(rom[lo:hi - ((hi - lo) % 4)]))", "pass")
    exec(compile(code, 'lu_match', 'exec'), _G)

def _dis(b, tag):
    p = f'/tmp/_vb_{os.getpid()}_{tag}.bin'
    open(p, 'wb').write(b)
    o = subprocess.run(['mips-linux-gnu-objdump', '-D', '-b', 'binary', '-mmips:4000', '-EB', '--no-show-raw-insn', '-M', 'no-aliases', p],
                       capture_output=True, text=True).stdout
    return [l.split(':\t', 1)[1].replace('\t', ' ').strip() for l in o.splitlines() if ':\t' in l]

def evaluate(job):
    path, fn, rom_hex, flags = job
    if not _G: _init()
    g = _G
    g['extra'][:] = flags
    try:
        res, err = g['compile_funcs'](path)
    except Exception as e:
        return (path, 99999, 99999, 0, 'EXC ' + str(e)[:80])
    if res is None:
        return (path, 99999, 99999, 0, 'COMPILE FAIL ' + ' '.join(map(str, err))[:100])
    text, syms, relocs, relnames = res
    c = [s for s in syms if s[0] == fn]
    if not c: return (path, 99999, 99999, 0, 'not found')
    name, off, size = c[0]
    ours = text[off:off + size]
    romb = g['rom'][rom_hex:rom_hex + size]
    fw = struct.unpack('>%dI' % (size // 4), ours); rw = struct.unpack('>%dI' % (size // 4), romb)
    exact = all(((a ^ b) & (0xFFFFFFFF ^ relocs.get(off + 4 * i, 0))) == 0 for i, (a, b) in enumerate(zip(fw, rw)))
    A = _dis(ours, 'a'); B = _dis(romb, 'b')
    relw = set((o - off) // 4 for o in relocs if off <= o < off + size)
    mn = lambda s: s.split()[0]
    sm = difflib.SequenceMatcher(None, [mn(x) for x in A], [mn(x) for x in B], autojunk=False)
    ns = no = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            for k in range(i2 - i1):
                a = A[i1 + k]; b = B[j1 + k]
                if (i1 + k) in relw:
                    a = re.sub(r'(-?0x[0-9a-f]+|-?\d+)(\(|$)', r'R\2', a); b = re.sub(r'(-?0x[0-9a-f]+|-?\d+)(\(|$)', r'R\2', b)
                if re.match(r'(b|j)', mn(a)) and mn(a) not in ('break',):
                    a = re.sub(r',[^,]*$', ',T', a) if ',' in a else mn(a) + ' T'
                    b = re.sub(r',[^,]*$', ',T', b) if ',' in b else mn(b) + ' T'
                    if mn(a) in ('j', 'jal'): a = mn(a); b = mn(b)
                if a != b: no += 1
        else:
            ns += max(i2 - i1, j2 - j1)
    movs = sum(1 for x in A[:70] if x.startswith('mov.s'))
    return (path, ns, no, 1 if exact else 0, f'movs={movs} n={len(A)}')

def main():
    a = sys.argv[1:]
    fn = a[0]; rom_hex = int(a[1], 16); a = a[2:]
    flags = ['@SN']; top = 15; jobs = 12
    files = []; i = 0; src = None
    while i < len(a):
        if a[i] == '--flags': flags = a[i + 1].split(); i += 2
        elif a[i] == '--top': top = int(a[i + 1]); i += 2
        elif a[i] == '--jobs': jobs = int(a[i + 1]); i += 2
        elif a[i] == '--dir': src = ('dir', a[i + 1]); i += 2
        elif a[i] == '--file': src = ('file', a[i + 1]); i += 2
        else: files.append(a[i]); i += 1
    os.chdir(ROOT)
    os.makedirs('wip/vb', exist_ok=True)
    if src and src[0] == 'file':
        txt = open(src[1], encoding='utf-8').read()
        parts = re.split(r'^//====.*$', txt, flags=re.M)
        for f in os.listdir('wip/vb'):
            if f.startswith('v') and f.endswith('.c'): os.remove('wip/vb/' + f)
        for k, p in enumerate(parts):
            if p.strip(): open(f'wip/vb/v{k}.c', 'w', encoding='utf-8', newline='\n').write(p.strip('\n') + '\n'); files.append(f'wip/vb/v{k}.c')
    elif src and src[0] == 'dir':
        files += sorted(os.path.join(src[1], f) for f in os.listdir(src[1]) if f.endswith('.c'))
    # copy to build tree
    jl = []
    for f in files:
        dst = os.path.join(HOME_WS, f)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy(f, dst)
        jl.append((dst, fn, rom_hex, flags))
    shutil.copytree(ROOT + '/include', HOME_WS + '/include', dirs_exist_ok=True)
    with mp.Pool(jobs) as pool:
        res = pool.map(evaluate, jl, chunksize=1)
    res = [(r[0].replace(HOME_WS + '/', ''), *r[1:]) for r in res]
    res.sort(key=lambda r: (not r[3], r[1] * 3 + r[2]))
    for p, ns, no, ex, err in res[:top]:
        print(f'{p}: structural={ns} operand={no} exact={ex} {err}')
    if res and res[0][1] < 99999:
        shutil.copy(res[0][0], 'wip/vb_best.c')
    print('variants:', len(res), 'exact:', sum(r[3] for r in res))

if __name__ == '__main__':
    main()
