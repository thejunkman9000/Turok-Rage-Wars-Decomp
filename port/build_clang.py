#!/usr/bin/env python3
"""Compile the game C for the Windows port through clang (zig cc) with big-endian memory access:
   C --clang--> LLVM IR --port/be_ir.py--> IR with byte-swapped loads/stores --clang--> COFF object (32-bit x86, MSVC ABI)

usage: python port/build_clang.py [--all] [--only name,name]
Sources: src/game, src/ovl_a, portable parts of src/libultra, port/nonmatching (drafts; a draft that does not compile against
include/ is retried with the headers of the workspace that produced it).  Objects go to port/build/obj_c/ (one per source)."""
import glob, os, re, subprocess, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from concurrent.futures import ThreadPoolExecutor
import threading
BE_LOCK = threading.Lock()
sys.path.insert(0, os.path.dirname(__file__))
import be_ir
if os.environ.get('PORT_OLD_BE'): import be_ir_old      # experiment switch: the pre-2026-10-10 byte-order rewriter (module-wide bookkeeping) for everything but src/libultra

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
OUT = 'port/build/obj_c'; LL = 'port/build/ll'
os.makedirs(OUT, exist_ok=True); os.makedirs(LL, exist_ok=True)
COMMON = ['python', '-m', 'ziglang', 'cc', '-target', 'x86-windows-msvc', '-O1', '-g0', '-fno-vectorize', '-fno-slp-vectorize',
          '-fno-strict-aliasing', '-fno-jump-tables', '-fno-math-errno', '-finstrument-functions', '-std=gnu89', '-w', '-Wno-error=int-conversion', '-Wno-error=incompatible-pointer-types', '-Wno-error=incompatible-function-pointer-types', '-Wno-error=incompatible-pointer-types-discards-qualifiers', '-Wno-error=implicit-function-declaration', '-D_LANGUAGE_C'] + ([] if os.environ.get('PORT_NO_DEFS') else ['-DF3DEX_GBI_2', '-DVERSION_US_REV1']) + ['-DTARGET_PC', '-DM2CTX', '-include', 'port/compat_clang.h']
ws_inc = sorted(glob.glob('D:/Projects/ws/*/include'), key=os.path.getmtime, reverse=True)
overrides = {os.path.basename(p)[:-2] for p in glob.glob('port/overrides/*.c')}


_COVER = []; _NAMES = set()
def _cskip(): return set(open('port/c_skip.txt').read().split()) if os.path.exists('port/c_skip.txt') else set()
def draft_superseded(p):
    """a behaviour-level draft (port/nonmatching/func_XXXXXXXX__N.c, __m2c.c) is only the fallback for a function that has neither matching C nor a recompiled
    twin: a stale draft would otherwise shadow the real C (the linker keeps the first definition, objects sort nm_ < ov_) or the C's alias.  __ovr files are the
    hand-written overrides of the port (their src file is skipped through port/overrides) and always stay."""
    m = re.match(r'func_([0-9A-F]{8})__(?!ovr)', os.path.basename(p))
    if not m: return False
    if not _COVER:
        for fn in ('funcs.txt', 'funcs_a.txt'):
            for l in open(fn):
                f = l.split('#')[0].split()
                if len(f) >= 4 and not f[0].startswith('pad_') and f[3] in ('game', 'ovl_a'):
                    rom = int(f[1], 16); va = rom - 0x16E000 + 0x400000 if rom >= 0x16E000 else rom - 0x1000 + 0x200400
                    if f[0] not in overrides and f[0] not in _cskip(): _COVER.append((va, va + 4 * int(f[2]))); _NAMES.add(f[0])      # an entry may start after its (stray head words) name; a source the port does not compile (c_skip.txt) covers nothing
        _COVER.sort()
        _COVER.append(set(open('port/recomp.txt').read().split()) if os.path.exists('port/recomp.txt') else set())
    rc = _COVER[-1]; va = int(m.group(1), 16)
    if 'func_' + m.group(1) in rc or 'func_' + m.group(1) in _NAMES: return True
    return any(a <= va < b for a, b in _COVER[:-1])


_SN = []
def sn_stems():
    """sources of the real-toolchain integration (mode=sn): hacks written for the MIPS code generator (empty asm barriers, permuter shapes, undefined-behaviour
    spellings) are only safe unoptimised on the host - func_00427690 at -O1 reads a NULL object where the MIPS code does not.  Older matched C keeps -O1.
    PORT_O1_SN=1 compiles them optimised like the rest."""
    if os.environ.get('PORT_O1_SN'): return ()
    if not _SN:
        names = set()
        for fn in ('funcs.txt', 'funcs_a.txt'):
            for l in open(fn):
                f = l.split('#')[0].split()
                if len(f) >= 4 and 'mode=sn' in ' '.join(f[4:]): names.add(f[0])
        _SN.append(names)
    return _SN[0]

def sources():
    srcs = []
    cskip = set(open('port/c_skip.txt').read().split()) if os.path.exists('port/c_skip.txt') else set()      # sources the port does not compile (their functions are statically recompiled instead): bisecting behaviour differences
    for p in sorted(glob.glob('src/game/*.c') + glob.glob('src/ovl_a/*.c')):
        if os.path.basename(p)[:-2] not in overrides and os.path.basename(p)[:-2] not in cskip and os.path.basename(p)[:-2] not in ('memset', 'memcpy', 'memmove'): srcs.append(p)   # libc names: the host CRT provides them
    for p in sorted(glob.glob('src/libultra/*.c')):
        b = os.path.basename(p)[:-2]
        if b in overrides: continue                                                                  # replaced by port/overrides/<name>.c (compiled from port/nonmatching)
        if b == 'string': continue                                                                  # (the audio library is now compiled: port/audio_hle.c + the AI/SP shims provide the sound backend)
        if b == 'string': continue                                                                  # memcpy/strlen: host CRT
        if re.match(r'^(__os|os[A-Z]|dbg|__divdi3|__moddi3|__udivdi3|__umoddi3|__floatdi|__cmpdi|__ucmpdi)', b): continue          # hardware layer: port/os_shim.c
        srcs.append(p)
    srcs += [d for d in sorted(glob.glob('port/nonmatching/*.c')) if not draft_superseded(d)] + sorted(glob.glob('port/native/*.c')) + sorted(glob.glob('port/native/recomp/*.c')) + (sorted(glob.glob('port/native/difftest/*.c')) if os.environ.get('TUROK_BUILD_DIFFTEST') else [])
    return srcs


# ---- implicit register arguments: the MIPS code calls f() and the callee reads the caller's own $a0..$a3 unchanged; pass them explicitly ----
FUNC_DEF = re.compile(r'^[\w][\w\s\*]*?\b(func_[0-9A-Fa-f]{8})\s*\(([^)]*)\)\s*\{', re.M)
THEIR_DEF = re.compile(r'^[\w][\w\s\*]*?\b(func_[0-9A-Fa-f]{8}_\w+)\s*\(([^)]*)\)\s*\{', re.M)
ZERO_CALL =re.compile(r'(?<![\w])(func_[0-9A-Fa-f]{8})\s*\(\s*\)\s*;')
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
    their = {}                                  # sources ported from the other decompilation define func_8027ED6C_de: the callers (our matching C) spell it func_0027ED40
    try:
        for m in re.finditer(r'^PROVIDE\((func_[0-9A-F]{8}_\w+) = 0x(00[0-9A-Fa-f]{6})\);', open('their_syms.ld').read(), re.M): their[m.group(1)] = 'func_' + m.group(2).upper()
    except OSError: pass
    for p in glob.glob('src/game/*.c') + glob.glob('src/ovl_a/*.c') + glob.glob('port/nonmatching/*.c') + glob.glob('port/overrides/*.c'):
        txt = open(p, errors='replace').read()
        for m in FUNC_DEF.finditer(txt):
            ps = _params(m.group(2))
            if ps and not any(re.search(r'\b(f32|f64|float|double)\b', a) and '*' not in a for a, _ in ps): _ALLDEFS[m.group(1)] = len(ps)
        for m in THEIR_DEF.finditer(txt):
            our = their.get(m.group(1)); ps = _params(m.group(2))
            if our and ps and not any(re.search(r'\b(f32|f64|float|double)\b', a) and '*' not in a for a, _ in ps): _ALLDEFS.setdefault(our, len(ps))
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
        if not n: return m.group(0)
        line_start = text.rfind('\n', 0, m.start()) + 1
        before = text[line_start:m.start()].rstrip()
        if before and not (before[-1] in '{};:(,=' or before.endswith(('return', 'else', '&&', '||', '!', '?'))): return m.group(0)
        args = [a for a in argtxt.split(',')] if argtxt.strip() else []
        if len(args) >= n: return m.group(0)
        caller = [d for d in defs if d[0] < m.start()]
        if not caller: return m.group(0)
        cp = [nm for _, nm in caller[-1][1]]
        extra = [cp[i] if i < len(cp) and cp[i] else '0' for i in range(len(args), n)]
        return f'{name}({argtxt.strip() + ", " if argtxt.strip() else ""}{", ".join(extra)})'
    return PARTIAL_CALL.sub(sub2, text)

def stage1_flags(base, prefix=''):
    """clang flags of the first stage (C -> LLVM IR, before the big-endian rewrite).  Optimising here is unsafe for byte-order sensitive code: the passes fold
    memory accesses with the host's little-endian layout (a halfword of a union read becomes `lshr word, 16`, adjacent accesses merge into wider ones), and the
    rewrite of loads/stores to guest byte order then yields wrong values (func_0042A994: `D_800E4F64[i].a.h.h1` read 0 instead of 0x316 at -O1, the widget lookup
    returned NULL).  Sources the port compiles unoptimised (-O0: mode=sn sources, PORT_O0=name,name) are safe; PORT_NOPASS=name,name or PORT_NOPASS_ALL=1 emit the IR of
    -O1 without running any LLVM pass (the second stage, on the rewritten IR, optimises).  Default now: no pass for all guest code."""
    if base in os.environ.get('PORT_O0', '').split(',') or base in sn_stems(): return ['-O0' if a == '-O1' else a for a in COMMON]
    if prefix not in ('nt_', 'zd_') and not os.environ.get('PORT_O1_STAGE1') or base in os.environ.get('PORT_NOPASS', '').split(','): return COMMON + ['-Xclang', '-disable-llvm-passes']      # guest code: never fold memory accesses before the byte-order rewrite (native helpers such as the RNC decoder keep -O1; PORT_O1_STAGE1=1 restores -O1 for everything)
    return COMMON


def compile_one(p, force):
    if not os.path.exists(p): return (p, True, 'gone')                       # dropped / renamed while the build was running
    base = os.path.splitext(os.path.basename(p))[0]
    prefix = 'lu_' if p.startswith('src/libultra') else ('ov_' if p.startswith('src/ovl_a') else ('nm_' if p.startswith('port/nonmatching') else ('ar_' if p.startswith('port/native/recomp') else 'zd_' if p.startswith('port/native/difftest') else 'nt_' if p.startswith('port/native') else '')))
    obj = f'{OUT}/{prefix}{base}.obj'
    if not force and os.path.exists(obj) and os.path.getmtime(obj) >= os.path.getmtime(p): return (p, True, 'cached')
    ll1 = f'{LL}/{prefix}{base}.ll'; ll2 = f'{LL}/{prefix}{base}.be.ll'
    incs = [['-Iinclude'] + ([] if os.environ.get('PORT_NO_THEIR_INC') else ['-Iinclude/their'])] + ([[f'-I{d}', '-Iinclude'] for d in ws_inc[:12]] if prefix == 'nm_' else [])
    err = ''
    src_text = open(p, errors='replace').read()
    src_text = re.sub(r'\s*(?:__asm__|__asm|asm)\s*\(\s*"\$?(?:\d{1,2}|zero|at|v[01]|a[0-3]|t\d|s\d|k[01]|gp|sp|fp|ra|f\d{1,2})"\s*\)', '', src_text)     # MIPS register pins from the matching drafts mean nothing to clang/x86 ("$4", "s1", "a0", "f23"); asm labels (asm("memcpy"), asm("D_80121990")) stay
    src_text = re.sub(r'(?:__asm__|__asm|asm)\s*(?:volatile\s*)?\(\s*"break[^"]*"\s*(?::[^;]*)?\)\s*;', ';', src_text)   # MIPS `break` traps: not x86 code
    src_text = re.sub(r'(?:__asm__|__asm|asm)\s*(?:volatile\s*)?\(\s*""\s*:\s*"[+=]f"\s*\([^)]*\)\s*\)\s*;', ';', src_text)   # float register barrier: the x87 'f' constraint is not usable; other empty asm statements (barriers, "=r"(k) : "0"(const) value definitions) are valid x86 and keep their meaning
    src_text = re.sub(r'(\bextern\s+[\w \t\*]+?\b\w+\s*)\(\s*[a-z_]\w*(?:\s*,\s*[a-z_]\w*)*\s*\)\s*;', lambda m: m.group(0) if re.search(r'\b(?:void|int|char|short|long|float|double|unsigned|signed|struct|union|enum|const|[su]\d+|f32|f64|u8|u16|u32|s8|s16|s32)\b', m.group(0)[m.group(0).index('('):]) else m.group(1) + '();', src_text)     # K&R `extern void f(arg0);` (name list without types) of the original toolchain: unprototyped for clang
    src_text = re.sub(r'^[ \t]*(?:extern[ \t]+)?[A-Za-z_][\w \t\*]*?\b(?:strlen|strcpy|strncpy|strcmp|strncmp|strcat|strchr|strstr|memcmp|memchr)[ \t]*\([^;{}]*\)[ \t]*;[ \t]*$', '', src_text, flags=re.M)     # the sources' own libc prototypes (s32 strlen(u8 *)) clash with the compiler's builtins
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
            r = subprocess.run(stage1_flags(base, prefix) + inc + ['-S', '-emit-llvm', pp, '-o', ll1], capture_output=True, text=True)
            if r.returncode == 0: done = True; break
            err = r.stderr
        if done: break
    else:
        return (p, False, 'clang: ' + err.strip().split('\n')[0][:160])
    if not done:
        return (p, False, 'clang: ' + err.strip().split('\n')[0][:160])
    try:
        with BE_LOCK:      # be_ir keeps its temp counter and ALIGN1_RAW in module globals: one rewrite at a time
            bm = be_ir_old if (os.environ.get('PORT_OLD_BE') and base not in os.environ.get('PORT_NEW_BE_ONLY', 'cseq,csplayer,seqplayer').split(',')) else be_ir
            bm.n_tmp[0] = 0; bm.ALIGN1_RAW = prefix in ('nt_', 'ar_', 'zd_')
            be_text = bm.rewrite(open(ll1, encoding='utf-8').read())
        open(ll2, 'w', encoding='utf-8', newline='\n').write(be_text)
    except Exception as e:
        return (p, False, f'rewrite: {e}')
    r = subprocess.run(['python', '-m', 'ziglang', 'cc', '-target', 'x86-windows-msvc', '-O1', '-c', ll2, '-o', obj], capture_output=True, text=True)
    if r.returncode != 0:
        return (p, False, 'llc: ' + r.stderr.strip().split('\n')[0][:160])
    if not os.environ.get('PORT_KEEP_LL'): os.remove(ll1); os.remove(ll2)      # PORT_KEEP_LL=1 keeps the IR (before / after the byte-order rewrite) for inspection
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
