#!/usr/bin/env python3
"""Compile the game C for the Windows port through clang (zig cc) with big-endian memory access:
   C --clang--> LLVM IR --port/be_ir.py--> IR with byte-swapped loads/stores --clang--> COFF object (32-bit x86, MSVC ABI)

usage: python port/build_clang.py [--all] [--only name,name]
Sources: src/game, src/ovl_a, portable parts of src/libultra, port/nonmatching (drafts; a draft that does not compile against
include/ is retried with the headers of the workspace that produced it).  Objects go to port/build/obj_c/ (one per source)."""
import glob, os, re, subprocess, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from concurrent.futures import ThreadPoolExecutor
sys.path.insert(0, os.path.dirname(__file__))
import be_ir

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
OUT = 'port/build/obj_c'; LL = 'port/build/ll'
os.makedirs(OUT, exist_ok=True); os.makedirs(LL, exist_ok=True)
COMMON = ['python', '-m', 'ziglang', 'cc', '-target', 'x86-windows-msvc', '-O1', '-g0', '-fno-vectorize', '-fno-slp-vectorize',
          '-fno-strict-aliasing', '-fno-jump-tables', '-fno-math-errno', '-finstrument-functions', '-std=gnu89', '-w', '-Wno-error=int-conversion', '-Wno-error=incompatible-pointer-types', '-Wno-error=incompatible-function-pointer-types', '-Wno-error=incompatible-pointer-types-discards-qualifiers', '-Wno-error=implicit-function-declaration', '-D_LANGUAGE_C', '-DTARGET_PC', '-DM2CTX', '-include', 'port/compat_clang.h']
ws_inc = sorted(glob.glob('D:/Projects/ws/*/include'), key=os.path.getmtime, reverse=True)
overrides = {os.path.basename(p)[:-2] for p in glob.glob('port/overrides/func_*.c')}

def sources():
    srcs = []
    for p in sorted(glob.glob('src/game/*.c') + glob.glob('src/ovl_a/*.c')):
        if os.path.basename(p)[:-2] not in overrides and os.path.basename(p)[:-2] not in ('memset', 'memcpy', 'memmove'): srcs.append(p)   # libc names: the host CRT provides them
    for p in sorted(glob.glob('src/libultra/*.c')):
        b = os.path.basename(p)[:-2]
        if b == 'string' or (re.match(r'^_?al[A-Z]', b) and not re.match(r'^al(Heap|Link|Unlink|Evtq|Copy|Cents)', b)): continue           # audio library: no-op stubs until a sound backend exists
        if b == 'string': continue                                                                  # memcpy/strlen: host CRT
        if re.match(r'^(__os|os[A-Z]|dbg|__divdi3|__moddi3|__udivdi3|__umoddi3|__floatdi|__cmpdi|__ucmpdi)', b): continue          # hardware layer: port/os_shim.c
        srcs.append(p)
    srcs += sorted(glob.glob('port/nonmatching/*.c')) + sorted(glob.glob('port/native/*.c')) + sorted(glob.glob('port/native/recomp/*.c')) + (sorted(glob.glob('port/native/difftest/*.c')) if os.environ.get('TUROK_BUILD_DIFFTEST') else [])
    return srcs


# ---- implicit register arguments: the MIPS code calls f() and the callee reads the caller's own $a0..$a3 unchanged; pass them explicitly ----
FUNC_DEF = re.compile(r'^[\w][\w\s\*]*?\b(func_[0-9A-Fa-f]{8})\s*\(([^)]*)\)\s*\{', re.M)
ZERO_CALL = re.compile(r'(?<![\w])(func_[0-9A-Fa-f]{8})\s*\(\s*\)\s*;')
PARTIAL_CALL = re.compile(r'(?<![\w.])(func_[0-9A-Fa-f]{8})\s*\(([^()]*)\)')
def _params(txt):
    txt = txt.strip()
    if not txt or txt == 'void' or '...' in txt: return []
    out = []
    for a in txt.split(','):
        a = a.strip(); m = re.search(r'(\w+)\s*(\[\s*\d*\s*\])?$', a)
        out.append((a, m.group(1) if m else ''))
    return out
_ALLDEFS = {}
def load_defs():
    try:
        for l in open('port/build/rc_argc.txt'):
            f = l.split()
            if len(f) == 2: _ALLDEFS[f[0]] = int(f[1])         # statically recompiled functions: how many argument registers they read
    except OSError: pass
    for p in glob.glob('src/game/*.c') + glob.glob('src/ovl_a/*.c') + glob.glob('port/nonmatching/*.c') + glob.glob('port/overrides/*.c'):
        for m in FUNC_DEF.finditer(open(p, errors='replace').read()):
            ps = _params(m.group(2))
            if ps and not any(re.search(r'\b(f32|f64|float|double)\b', a) and '*' not in a for a, _ in ps): _ALLDEFS[m.group(1)] = len(ps)
TRAMPOLINE = re.compile(r'^((?:void|s32|u32|int)\s+func_[0-9A-F]{8})\(void\)\s*\{\s*(return\s+)?(\w+)\(\);\s*\}[ \t]*$', re.M)
def patch_trampolines(text):
    """`void f(void) { target(); }` is a tail-call trampoline in the original (all argument registers pass through): forward them"""
    return TRAMPOLINE.sub(lambda m: '%s(s32 a0, s32 a1, s32 a2, s32 a3) { %s((s32 (*)(s32, s32, s32, s32))%s)(a0, a1, a2, a3); }' % (m.group(1), m.group(2) or '', m.group(3)), text)

def patch_implicit_args(text):
    text = patch_trampolines(text)
    if not _ALLDEFS: load_defs()
    defs = [(m.start(), _params(m.group(2))) for m in FUNC_DEF.finditer(text)]
    def sub(m):
        n = _ALLDEFS.get(m.group(1))
        if not n: return m.group(0)
        caller = [d for d in defs if d[0] < m.start()]
        if not caller: return m.group(0)
        cp = [nm for _, nm in caller[-1][1]]
        args = [cp[i] if i < len(cp) and cp[i] else '0' for i in range(n)]
        return f'{m.group(1)}({", ".join(args)});'
    text = ZERO_CALL.sub(sub, text)
    # a prototype with (void) would reject the arguments we are about to pass: make it unprototyped (K&R) like the original
    def relax(m):
        n = _ALLDEFS.get(m.group(2))
        if not n: return m.group(0)
        ps = _params(m.group(3))
        if len(ps) >= n or any(re.search(r'\b(f32|f64|float|double)\b', a) and '*' not in a for a, _ in ps): return m.group(0)
        return m.group(1) + m.group(2) + '();'
    text = re.sub(r'(?m)^([A-Za-z_][\w \t\*]*?\b)(func_[0-9A-Fa-f]{8})\s*\(([^()]*)\)\s*;', relax, text)

    # calls that pass fewer arguments than the callee takes: the original code leaves the remaining argument registers as they were
    # on entry to the caller (a1 = the caller's own a1 ...), so pass the caller's parameters at those positions
    def sub2(m):
        name, argtxt = m.group(1), m.group(2)
        n = _ALLDEFS.get(name)
        if not n or not argtxt.strip(): return m.group(0)
        line_start = text.rfind('\n', 0, m.start()) + 1
        before = text[line_start:m.start()].rstrip()
        if before and not (before[-1] in '{};:(,=' or before.endswith(('return', 'else', '&&', '||', '!', '?'))): return m.group(0)
        args = [a for a in argtxt.split(',')]
        if len(args) >= n: return m.group(0)
        caller = [d for d in defs if d[0] < m.start()]
        if not caller: return m.group(0)
        cp = [nm for _, nm in caller[-1][1]]
        extra = [cp[i] if i < len(cp) and cp[i] else '0' for i in range(len(args), n)]
        return f'{name}({argtxt.strip()}, {", ".join(extra)})'
    return PARTIAL_CALL.sub(sub2, text)

def compile_one(p, force):
    base = os.path.splitext(os.path.basename(p))[0]
    prefix = 'lu_' if p.startswith('src/libultra') else ('ov_' if p.startswith('src/ovl_a') else ('nm_' if p.startswith('port/nonmatching') else ('ar_' if p.startswith('port/native/recomp') else 'zd_' if p.startswith('port/native/difftest') else 'nt_' if p.startswith('port/native') else '')))
    obj = f'{OUT}/{prefix}{base}.obj'
    if not force and os.path.exists(obj) and os.path.getmtime(obj) >= os.path.getmtime(p): return (p, True, 'cached')
    ll1 = f'{LL}/{prefix}{base}.ll'; ll2 = f'{LL}/{prefix}{base}.be.ll'
    incs = [['-Iinclude']] + ([[f'-I{d}', '-Iinclude'] for d in ws_inc[:12]] if prefix == 'nm_' else [])
    err = ''
    src_text = open(p, errors='replace').read()
    src_text = re.sub(r'\s*(?:__asm__|__asm|asm)\s*\(\s*"\$[0-9a-z]+"\s*\)', '', src_text)     # MIPS register pins from the matching drafts mean nothing to clang/x86
    src_text = re.sub(r'(?<![\w])func_([0-9A-F]{6})(?![\w])', lambda m: 'func_00' + m.group(1), src_text)                 # short names (func_44AFC0) of the matching tree: the real function, so the implicit-argument patches apply
    variants = [patch_implicit_args(src_text), src_text]
    if base.endswith('__m2c'):
        import m2c_autofix
        fixed, ok = m2c_autofix.fix(variants[0], COMMON + incs[0] + ['-S', '-emit-llvm', f'{LL}/{prefix}{base}.c', '-o', ll1], f'{LL}/{prefix}{base}.c')
        variants = [fixed]
    err = ''
    for vi, patched in enumerate(variants):
        if vi == 1 and patched == variants[0]: break
        pp = f'{LL}/{prefix}{base}.c'; open(pp, 'w', newline='\n').write(patched)
        done = False
        for inc in incs:
            r = subprocess.run(COMMON + inc + ['-S', '-emit-llvm', pp, '-o', ll1], capture_output=True, text=True)
            if r.returncode == 0: done = True; break
            err = r.stderr
        if done: break
    else:
        return (p, False, 'clang: ' + err.strip().split('\n')[0][:160])
    if not done:
        return (p, False, 'clang: ' + err.strip().split('\n')[0][:160])
    try:
        be_ir.n_tmp[0] = 0
        open(ll2, 'w', encoding='utf-8', newline='\n').write(be_ir.rewrite(open(ll1, encoding='utf-8').read()))
    except Exception as e:
        return (p, False, f'rewrite: {e}')
    r = subprocess.run(['python', '-m', 'ziglang', 'cc', '-target', 'x86-windows-msvc', '-O1', '-c', ll2, '-o', obj], capture_output=True, text=True)
    if r.returncode != 0:
        return (p, False, 'llc: ' + r.stderr.strip().split('\n')[0][:160])
    os.remove(ll1); os.remove(ll2)
    return (p, True, 'ok')

if __name__ == '__main__':
    force = '--all' in sys.argv
    only = None
    if '--only' in sys.argv: only = set(sys.argv[sys.argv.index('--only') + 1].split(','))
    srcs = [s for s in sources() if not only or os.path.basename(s)[:-2] in only or any(o in s for o in only)]
    if not only:       # drop objects of sources that no longer exist (renamed drafts, parked groups ...)
        def oname(p):
            b = os.path.splitext(os.path.basename(p))[0]
            return ('lu_' if p.startswith('src/libultra') else 'ov_' if p.startswith('src/ovl_a') else 'nm_' if p.startswith('port/nonmatching') else 'ar_' if p.startswith('port/native/recomp') else 'zd_' if p.startswith('port/native/difftest') else 'nt_' if p.startswith('port/native') else '') + b + '.obj'
        keep = {oname(x) for x in srcs}
        for f in os.listdir(OUT):
            if f not in keep: os.remove(os.path.join(OUT, f))
    t0 = time.time(); bad = []
    with ThreadPoolExecutor(max_workers=max(2, (os.cpu_count() or 4))) as ex:
        for p, ok, msg in ex.map(lambda s: compile_one(s, force), srcs):
            if not ok: bad.append((p, msg))
    print(f'{len(srcs) - len(bad)} ok, {len(bad)} failed in {time.time() - t0:.0f}s')
    with open('port/build/clang_failed.txt', 'w') as f:
        for p, m in bad: f.write(f'{p}: {m}\n')
    for p, m in bad[:25]: print('  FAIL', p, m)
