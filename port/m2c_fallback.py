#!/usr/bin/env python3
"""For functions that have no matching C and no worker draft, fall back to the m2c decompiler (run with --valid-syntax so the
output uses macros for unknown struct accesses): behaviour-level C that mostly compiles.
Called by collect_nonmatching.py; writes port/nonmatching/<fn>__m2c.c.  Results are cached in port/build/m2c_valid/."""
import glob, os, re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor

ROOT = os.getcwd().replace(chr(92), '/')
PRELUDE = '#include "common.h"\n#include "%s/port/m2c_macros.h"\ntypedef s32 M2C_UNKTYPE;\n' % ROOT
CACHE = 'port/build/m2c_valid'

def asm_index():
    """name -> asm file, exact per-function files generated from the ROM (port/asm_all.py)"""
    if not os.environ.get('PORT_NO_ASM_REGEN'):            # PORT_NO_ASM_REGEN=1: reuse port/build/asm_func (slow to rebuild, depends only on the ROM)
        subprocess.run([sys.executable, 'port/asm_tail.py'] + open('port/extra_starts.txt').read().split(), capture_output=True)
        subprocess.run([sys.executable, 'port/asm_all.py'], capture_output=True)
    funcs = {}
    for p in glob.glob('port/build/asm_func/*.s'):
        funcs[os.path.basename(p)[:-2]] = p
    for p in glob.glob('src/**/*.s', recursive=True):                      # hand-written libultra assembly keeps its own names
        t = open(p, encoding='utf-8').read()
        for m in re.finditer(r'glabel (\S+)', t):
            funcs.setdefault(m.group(1), p)
    return funcs

KNOWN = set()
def known_functions(idx):
    for p in glob.glob('src/**/func_*.c', recursive=True) + glob.glob('port/nonmatching/func_*.c'):
        m = re.search(r'(func_[0-9A-F]{8})', os.path.basename(p))
        if m: KNOWN.add(m.group(1))
    KNOWN.update(n for n in idx if re.match(r'func_[0-9A-F]{8}$', n))

def convert(txt):
    txt = re.sub(r'(?<![\w])func_([0-9A-F]{6})(?![\w])', r'func_00\1', txt)             # overlay functions are named func_0044E910 here
    txt = re.sub(r'(?<![\w"\'])\?(?![\w"\'=])', 'M2C_UNKTYPE', txt)
    # untyped stores/loads and memset with a lost first argument
    txt = re.sub(r'\*\(void \*\)(\w+) = \((f32|f64|s8|u8|s16|u16|s32|u32)\)', r'*(\2 *)\1 = (\2)', txt)
    txt = txt.replace('*(void *)', '*(s32 *)')
    txt = re.sub(r'\bmemset\(0, (0x[0-9A-Fa-f]+|\d+)\)', r'memset(arg0, 0, \1)', txt)
    # code addresses passed as integer constants (callbacks): use the function itself so that it is a real host pointer
    used = set()
    def fnaddr(m):
        name = 'func_%08X' % int(m.group(1), 16)
        if name in KNOWN:
            used.add(name)
            return name
        return m.group(0)
    txt = re.sub(r'(?<![\w.])0x([0-9A-Fa-f]{6})(?![\w])', fnaddr, txt)
    if used:
        txt = ''.join('void %s();\n' % n for n in sorted(used)) + txt
    txt = re.sub(r'\bvoid(\s*\*)', r'u8\1', txt)                  # unknown pointees: byte arithmetic, like the M2C_UNK typedef
    # m2c's guessed prototypes clash with the real ones (memcpy, osViSetMode ...): drop them unless the return type is floating point
    txt = re.sub(r'^(?!f32|f64|float|double)[^\n(=]*\([^\n]*\);[ \t]*/\* (?:extern|static) \*/[ \t]*\n', '', txt, flags=re.M)
    txt = re.sub(r'^(?:f32|f64|float|double)\s+(?:sqrtf|sinf|cosf|tanf|atan2f|fabsf|floorf|ceilf|powf|expf|logf|fmodf|sqrt|sin|cos|fabs|floor|ceil)\([^\n]*\);[^\n]*\n', '', txt, flags=re.M)
    return txt

def run(missing_without_draft):
    os.makedirs(CACHE, exist_ok=True)
    idx = asm_index()
    known_functions(idx)
    deny = set(open('port/m2c_deny.txt').read().split()) if os.path.exists('port/m2c_deny.txt') else set()
    jobs = [fn for fn in missing_without_draft if fn not in deny and (fn in idx or fn.replace('func_00', 'func_') in idx)]
    def work(fn):
        name = fn if fn in idx else fn.replace('func_00', 'func_')
        cached = f'{CACHE}/{fn}.c'
        if not os.path.exists(cached):
            try:
                r = subprocess.run([sys.executable, 'tools/m2c/m2c.py', '--target', 'mips-gcc-c', '--valid-syntax', '-f', name, idx[name]],
                                   capture_output=True, text=True, timeout=180)
                out = r.stdout if r.stdout.strip() else r.stderr
            except subprocess.TimeoutExpired:
                out = '/* timeout */'
            open(cached, 'w', encoding='utf-8').write(out)
        return fn
    with ThreadPoolExecutor(max_workers=os.cpu_count() or 4) as ex:
        done = list(ex.map(work, jobs))
    for fn in done:
        open(f'port/nonmatching/{fn}__m2c.c', 'w', newline='\n').write(PRELUDE + convert(open(f'{CACHE}/{fn}.c', encoding='utf-8').read()))
    print('m2c fallback files:', len(done))
