#!/usr/bin/env python3
"""Compile the game C for the Windows port through clang (zig cc) with big-endian memory access:
   C --clang--> LLVM IR --port/be_ir.py--> IR with byte-swapped loads/stores --clang--> COFF object (32-bit x86, MSVC ABI)

usage: python port/build_clang.py [--all] [--only name,name]
Sources: src/game, src/ovl_a, portable parts of src/libultra, port/nonmatching (drafts; a draft that does not compile against
include/ is retried with the headers of the workspace that produced it).  Objects go to port/build/obj_c/ (one per source)."""
import glob, os, re, subprocess, sys, time
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
        if os.path.basename(p)[:-2] not in overrides: srcs.append(p)
    for p in sorted(glob.glob('src/libultra/*.c')):
        b = os.path.basename(p)[:-2]
        if re.match(r'^(__os|os[A-Z]|dbg|__divdi3|__moddi3|__udivdi3|__umoddi3|__floatdi|__cmpdi|__ucmpdi)', b): continue          # hardware layer: port/os_shim.c
        srcs.append(p)
    srcs += sorted(glob.glob('port/nonmatching/*.c'))
    return srcs

def compile_one(p, force):
    base = os.path.splitext(os.path.basename(p))[0]
    prefix = 'lu_' if p.startswith('src/libultra') else ('ov_' if p.startswith('src/ovl_a') else ('nm_' if p.startswith('port/nonmatching') else ''))
    obj = f'{OUT}/{prefix}{base}.obj'
    if not force and os.path.exists(obj) and os.path.getmtime(obj) >= os.path.getmtime(p): return (p, True, 'cached')
    ll1 = f'{LL}/{prefix}{base}.ll'; ll2 = f'{LL}/{prefix}{base}.be.ll'
    incs = [['-Iinclude']] + ([[f'-I{d}', '-Iinclude'] for d in ws_inc[:12]] if prefix == 'nm_' else [])
    err = ''
    for inc in incs:
        r = subprocess.run(COMMON + inc + ['-S', '-emit-llvm', p, '-o', ll1], capture_output=True, text=True)
        if r.returncode == 0: break
        err = r.stderr
    else:
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
    t0 = time.time(); bad = []
    with ThreadPoolExecutor(max_workers=max(2, (os.cpu_count() or 4))) as ex:
        for p, ok, msg in ex.map(lambda s: compile_one(s, force), srcs):
            if not ok: bad.append((p, msg))
    print(f'{len(srcs) - len(bad)} ok, {len(bad)} failed in {time.time() - t0:.0f}s')
    with open('port/build/clang_failed.txt', 'w') as f:
        for p, m in bad: f.write(f'{p}: {m}\n')
    for p, m in bad[:25]: print('  FAIL', p, m)
