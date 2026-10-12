"""Recompiled twins (port/build/ll/ar_*.c) call other functions as `extern u32 f(); ... f(...)` unless the recompiler's float-signature
table (port/fpsig.py) says f returns a float - then the call is cast, `((float (*)(...))f)(...)`.  An uncast call to a function that really
returns float / double leaves st(0) on the x87 stack (see wip/scan_fpret.py).  Lists such calls."""
import glob, re, os, sys, collections
sys.path.insert(0, 'port')
import fpsig
fdefs = {}
for f in glob.glob('port/build/ll/*.c'):
    if os.path.basename(f).startswith(('ar_', 'zd_')): continue
    s = open(f, encoding='utf-8', errors='ignore').read()
    s = re.sub(r'/\*.*?\*/', ' ', s, flags=re.S)
    for m in fpsig._DEF.finditer(s):
        r = m.group(1).strip()
        if '*' in r or '*' in s[m.start(1):m.start(2)]: continue
        k = fpsig.rtype(r)
        if k in ('f', 'd'): fdefs[m.group(2)] = (k, os.path.basename(f))
bad = collections.Counter(); where = collections.defaultdict(set)
for f in glob.glob('port/build/ll/ar_*.c'):
    s = open(f, encoding='utf-8', errors='ignore').read()
    for m in re.finditer(r'(?<![\w)])(\w+)\(', s):
        name = m.group(1)
        if name not in fdefs: continue
        pre = s[max(0, m.start() - 40):m.start()]
        if re.search(r'\(\s*(?:float|double|f32|f64)\s*\(\*\)\([^()]*\)\)\s*$', pre): continue     # cast call
        line = s[s.rfind('\n', 0, m.start()) + 1:s.find('\n', m.start())]
        if re.match(r'\s*(extern|static)?\s*\w+\s+\**' + name + r'\(', line): continue            # declaration
        bad[name] += 1; where[name].add(os.path.basename(f))
for n, c in bad.most_common():
    print('%-16s %s (%s) uncast calls: %d in %s' % (n, fdefs[n][0], fdefs[n][1], c, ' '.join(sorted(where[n]))[:150]))
print(len(bad), 'functions', file=sys.stderr)
