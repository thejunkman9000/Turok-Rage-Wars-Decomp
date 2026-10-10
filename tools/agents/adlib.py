import sys, os, subprocess, re, difflib
_loaded = False
def _load():
    global _loaded
    if _loaded: return
    sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
    os.chdir('/mnt/d/Projects/ws/s702')
    code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
    g = globals()
    exec(compile(code, 'lu_match', 'exec'), g)
    _loaded = True
def _dis(b):
    open('/tmp/_ad.bin','wb').write(b)
    o = subprocess.run(['mips-linux-gnu-objdump','-D','-b','binary','-mmips:4000','-EB','--no-show-raw-insn','-M','no-aliases','/tmp/_ad.bin'],capture_output=True,text=True).stdout
    return [l.split(':\t',1)[1].replace('\t',' ').strip() for l in o.splitlines() if ':\t' in l]
def adiff(path, func, rom_hex, flags):
    _load()
    g = globals()
    g['extra'][:] = flags
    res, err = g['compile_funcs'](os.path.expanduser('~/trw_s702/') + path)
    if res is None: return None, None, ['COMPILE FAIL ' + str(err)]
    text, syms, relocs, relnames = res
    c = [s for s in syms if s[0] == func]
    if not c: return None, None, ['not found']
    name, off, size = c[0]
    ours = text[off:off+size]; romb = g['rom'][rom_hex:rom_hex+size]
    A = _dis(ours); B = _dis(romb)
    relw = set((o - off)//4 for o in relocs if off <= o < off+size)
    mn = lambda s: s.split()[0]
    def full(s, i, isours):
        m = mn(s)
        if m in ('j','jal'): return m
        if re.match(r'b', m): return re.sub(r',[^,]*$', ',T', s) if ',' in s else m + ' T'
        if isours and i in relw: return re.sub(r'(-?0x[0-9a-f]+|-?\d+)(\(|$)', r'R\2', s)
        return s
    sm = difflib.SequenceMatcher(None, [mn(x) for x in A], [mn(x) for x in B], autojunk=False)
    ns = no = 0; out = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            for k in range(i2-i1):
                fa = full(A[i1+k], i1+k, True); fb = full(B[j1+k], j1+k, False)
                if fa != fb:
                    if (i1+k) in relw and fa == re.sub(r'(-?0x[0-9a-f]+|-?\d+)(\(|$)', r'R\2', B[j1+k]): continue
                    no += 1; out.append(f'!! {i1+k:3d} {A[i1+k]:34s}| {j1+k:3d} {B[j1+k]}')
        else:
            ns += max(i2-i1, j2-j1)
            for k in range(max(i2-i1, j2-j1)):
                x = f'{i1+k:3d} {A[i1+k]}' if i1+k < i2 else ''
                y = f'{j1+k:3d} {B[j1+k]}' if j1+k < j2 else ''
                out.append(f'## {x:38s}| {y}')
    return ns, no, out
