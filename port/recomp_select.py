#!/usr/bin/env python3
"""Choose which functions without matching C are statically recompiled: integer-only functions (no FPU use, which would need
float calling-convention handling) that the recompiler can translate.  Writes port/recomp.txt"""
import os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import mips2c, m2c_fallback

def main():
    idx = m2c_fallback.asm_index()
    man = set()
    for m in ('funcs.txt', 'funcs_a.txt'):
        for l in open(m):
            f = l.split('#')[0].split()
            if len(f) >= 4 and not f[0].startswith('pad_'): man.add(f[0])
    absorbed = set(open('wip/absorbed.txt').read().split())
    import glob
    defd = set()                                   # an 'absorbed' function is only really covered when some C file defines it
    for f in glob.glob('src/**/*.c', recursive=True) + glob.glob('port/nonmatching/*.c') + glob.glob('port/overrides/*.c'):
        defd.update(re.findall(r'^[A-Za-z_][\w 	\*]*?\b(func_[0-9A-F]{8})\s*\([^;{}]*\)\s*\{', open(f, errors='replace').read(), re.M))
    absorbed -= {n for n in absorbed if n not in defd}
    missing = sorted(n for n in idx if re.match(r'func_[0-9A-F]{8}$', n) and n not in man and n not in absorbed)
    fpm = re.compile(r'\b(lwc1|swc1|ldc1|sdc1|mtc1|mfc1|[a-z]+\.[sd]|cvt\.\S+|bc1[tf]l?|ctc1|cfc1|mtc0|mfc0|eret|tlb\w+|cache)\b')
    sel = []; fp = 0; fail = 0
    for n in missing:
        t = open(idx[n], encoding='utf-8').read()
        items = mips2c.parse(t, n)
        try: mips2c.recompile_function(t, n, set())
        except Exception: fail += 1; continue
        sel.append(n)
    open('port/recomp.txt', 'w').write('\n'.join(sel) + '\n')
    print('missing', len(missing), 'selected', len(sel), 'fpu', fp, 'unsupported', fail)

if __name__ == '__main__':
    main()
