#!/usr/bin/env python3
"""wvb.py - parallel variant evaluator with WINDOWED aligned-diff metric (for huge functions).

usage (inside WSL, from the workspace root):
  python3 tools/wvb.py <fn> <rom hex> <nrom insns> [--flags "@SN"] [--win lo,hi] [--top N] [--jobs N] (--dir D | --file variants.txt | files...)
For every candidate: total structural / operand counts of the aligned diff (difflib on mnemonics) against the first <nrom insns> ROM words,
`first` = ROM insn index of the first difference (structural or operand), and the counts inside the ROM window [lo,hi].
Ranking: window (struct*3+operand) first when --win is given, else total.  Best -> wip/wvb_best.c.
(structural = inserted/deleted/changed-mnemonic insns; operand = same mnemonic, other register/immediate; relocations masked)"""
import sys, os, re, shutil, subprocess, difflib, struct, multiprocessing as mp

ROOT = '/mnt/d/Projects/ws/s901'
HOME_WS = os.path.expanduser('~/trw_s901')
_G = {}

def _init():
    sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
    os.chdir(ROOT)
    code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
    code = code.replace("for lo, hi, n in REGIONS: ROMW[n] = (lo, words(rom[lo:hi - ((hi - lo) % 4)]))", "pass")
    exec(compile(code, 'lu_match', 'exec'), _G)

def _dis(b, tag):
    p = f'/tmp/_wvb_{os.getpid()}_{tag}.bin'
    open(p, 'wb').write(b)
    o = subprocess.run(['mips-linux-gnu-objdump', '-D', '-z', '-b', 'binary', '-mmips:4000', '-EB', '--no-show-raw-insn', '-M', 'no-aliases', p],
                       capture_output=True, text=True).stdout
    return [l.split(':\t', 1)[1].replace('\t', ' ').strip() for l in o.splitlines() if ':\t' in l]

def evaluate(job):
    path, fn, rom_hex, nrom, flags, win = job
    if not _G: _init()
    g = _G
    g['extra'][:] = flags
    try:
        res, err = g['compile_funcs'](path)
    except Exception as e:
        return (path, 99999, 99999, 99999, 0, 0, 'EXC ' + str(e)[:80], 0)
    if res is None:
        return (path, 99999, 99999, 99999, 0, 0, 'COMPILE FAIL ' + ' '.join(map(str, err))[:100], 0)
    text, syms, relocs, relnames = res
    c = [s for s in syms if s[0] == fn]
    if not c: return (path, 99999, 99999, 99999, 0, 0, 'not found', 0)
    name, off, size = c[0]
    ours = text[off:off + size]
    romb = g['rom'][rom_hex:rom_hex + 4 * nrom]
    A = _dis(ours, 'a'); B = _dis(romb, 'b')
    relw = set((o - off) // 4 for o in relocs if off <= o < off + size)
    mn = lambda s: s.split()[0]
    sm = difflib.SequenceMatcher(None, [mn(x) for x in A], [mn(x) for x in B], autojunk=False)
    ns = no = 0; first = 10**9; ws = wo = 0
    lo, hi = win
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
                if a != b:
                    no += 1; first = min(first, j1 + k)
                    if lo <= j1 + k <= hi: wo += 1
        else:
            n = max(i2 - i1, j2 - j1)
            ns += n; first = min(first, j1)
            ws += sum(1 for q in range(j1, j1 + n) if lo <= q <= hi)
    exact = 1 if (ns == 0 and no == 0 and len(A) == nrom) else 0
    return (path, ns, no, first, ws, wo, '', exact)

def main():
    a = sys.argv[1:]
    fn = a[0]; rom_hex = int(a[1], 16); nrom = int(a[2]); a = a[3:]
    flags = ['@SN']; top = 15; jobs = 3; win = (0, 10**9)
    files = []; i = 0; src = None; haswin = False
    while i < len(a):
        if a[i] == '--flags': flags = a[i + 1].split(); i += 2
        elif a[i] == '--top': top = int(a[i + 1]); i += 2
        elif a[i] == '--jobs': jobs = int(a[i + 1]); i += 2
        elif a[i] == '--win': win = tuple(int(x) for x in a[i + 1].split(',')); haswin = True; i += 2
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
    jl = []
    for f in files:
        dst = os.path.join(HOME_WS, f)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy(f, dst)
        jl.append((dst, fn, rom_hex, nrom, flags, win))
    shutil.copytree(ROOT + '/include', HOME_WS + '/include', dirs_exist_ok=True)
    with mp.Pool(jobs) as pool:
        res = pool.map(evaluate, jl, chunksize=1)
    res = [(r[0].replace(HOME_WS + '/', ''), *r[1:]) for r in res]
    if haswin: res.sort(key=lambda r: (not r[7], r[4] * 3 + r[5], r[1] * 3 + r[2]))
    else: res.sort(key=lambda r: (not r[7], r[1] * 3 + r[2]))
    for p, ns, no, first, ws, wo, err, ex in res[:top]:
        print(f'{p}: structural={ns} operand={no} first={first} win=({ws},{wo}) exact={ex} {err}')
    if res and res[0][1] < 99999:
        shutil.copy(res[0][0], 'wip/wvb_best.c')
    print('variants:', len(res), 'exact:', sum(r[7] for r in res))

if __name__ == '__main__':
    main()
