"""x87 stack-leak scan: on 32-bit x86 a float/double return travels in st(0).  A caller whose prototype says the callee returns
non-float never pops it (leak); a caller that expects a float from a non-float callee pops an empty register (underflow).
After 8 leaks every x87 load gives the 'indefinite' NaN FFC00000.  Compares each definition's return kind with every
prototype of the same name in the build inputs (port/build/ll/*.c and the native port/*.c)."""
import glob, re, os, sys, collections
sys.path.insert(0, 'port')
import fpsig
files = glob.glob('port/build/ll/*.c') + glob.glob('port/*.c') + glob.glob('port/native/*.c')
defs = collections.defaultdict(set); decls = collections.defaultdict(set)
def kind(r):
    k = fpsig.rtype(r)
    return 'f' if k in ('f', 'd') else ('?' if k == '?' else 'n')
for f in files:
    try: s = open(f, encoding='utf-8', errors='ignore').read()
    except Exception: continue
    s = re.sub(r'/\*.*?\*/', ' ', s, flags=re.S); s = re.sub(r'//[^\n]*', ' ', s)
    for m in fpsig._DEF.finditer(s):
        if m.group(1).strip() in ('return', 'else', 'if'): continue
        defs[m.group(2)].add((kind(m.group(1)), os.path.basename(f)))
    for m in re.finditer(r'(?:^|[;{}\n])\s*((?:extern\s+|static\s+)?(?:const\s+)?[A-Za-z_]\w*(?:\s*\*+)?)\s+\**\s*([A-Za-z_]\w*)\s*\(([^;{}()]*(?:\([^;{}()]*\)[^;{}()]*)*)\)\s*;', s):
        r = m.group(1).strip()
        if r in ('return', 'else', 'goto', 'case', 'do'): continue
        decls[m.group(2)].add((kind(r), os.path.basename(f)))
# alias names (func_802A18CC_de = func_002A28CC ...) resolve through the linker's /ALTERNATENAME table
alias = {}
for l in open('port/gen/alias.rsp'):
    m = re.match(r'/ALTERNATENAME:_(\w+)=_(\w+)', l.strip())
    if m: alias[m.group(1)] = m.group(2)
for a, real in alias.items():
    if a in decls: decls[real] |= {(k, f + ' (as ' + a + ')') for k, f in decls[a]}
bad = 0
for name, ds in sorted(defs.items()):
    dk = {k for k, _ in ds if k != '?'}
    if len(dk) != 1: continue
    dk = dk.pop()
    for k, f in sorted(decls.get(name, ())):
        if k != '?' and k != dk:
            bad += 1
            print('%-28s def=%s (%s)  decl=%s in %s' % (name, dk, ','.join(sorted(x for _, x in ds))[:60], k, f))
print('mismatches:', bad, file=sys.stderr)
