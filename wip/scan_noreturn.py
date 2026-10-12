#!/usr/bin/env python3
"""Scan the port's compiled game sources (the exact text build_clang.py compiles, port/build/ll/*.c) for non-void functions that can end
without a return value (clang -Wreturn-type).  On MIPS such a function hands its caller whatever $v0 holds; on x86 the caller gets garbage.
Writes wip/noreturn.txt: <source> <line> <function> <message>."""
import concurrent.futures, glob, os, re, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
FLAGS = ['python', '-m', 'ziglang', 'cc', '-target', 'x86-windows-msvc', '-fsyntax-only', '-std=gnu89', '-Wno-everything', '-Wreturn-type',
         '-Wno-error=int-conversion', '-Wno-error=incompatible-pointer-types', '-Wno-error=incompatible-function-pointer-types',
         '-Wno-error=implicit-function-declaration', '-D_LANGUAGE_C', '-DF3DEX_GBI_2', '-DVERSION_US_REV1', '-DTARGET_PC', '-DM2CTX',
         '-include', 'port/compat_clang.h', '-Iinclude']
files = [p for p in glob.glob('port/build/ll/*.c') if not re.match(r'(nm_|ar_|nt_|zd_)', os.path.basename(p)) and not p.endswith('.be.c')]

def run(p):
    head = open(p, errors='replace').read(400)
    their = 'include/their2' if 'their2' in head else 'include/their'
    r = subprocess.run(FLAGS + ['-I' + their, p], capture_output=True, text=True)
    out = []
    for l in r.stderr.split('\n'):
        m = re.match(r'(.*?):(\d+):\d+: warning: (.*(?:non-void function|does not return a value).*)\[-Wreturn-type\]', l)
        if m: out.append((os.path.basename(p), int(m.group(2)), m.group(3).strip()))
    return out

res = []
with concurrent.futures.ThreadPoolExecutor(12) as ex:
    for o in ex.map(run, files): res.extend(o)
with open('wip/noreturn.txt', 'w', newline='\n') as f:
    for src, line, msg in sorted(res): f.write(f'{src} {line} {msg}\n')
print(len(files), 'sources scanned,', len(res), 'warnings -> wip/noreturn.txt')
