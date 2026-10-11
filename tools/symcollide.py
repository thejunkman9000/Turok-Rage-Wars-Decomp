"""symbol-name hygiene of the deliverables: every D_XXXXXXXX / func_XXXXXXXX name used in wip/out/func_*.c must not be defined with another value in any symbol/ld file
(their_syms.ld, their_alias.ld, c_syms.ld, extra_syms.ld, symbol_addrs.txt, undefined_*_auto.txt ...); run from the workspace root: python3 tools/symcollide.py"""
import re, glob
defs = {}
files = ['turok_ragewars.ld','hardware_regs.ld','extra_syms.ld','undefined_syms_auto.txt','undefined_funcs_auto.txt','c_syms.ld','their_syms.ld','their_alias.ld','symbol_addrs.txt']
for f in files:
    try:
        for l in open(f, errors='replace'):
            m = re.match(r'\s*(?:PROVIDE\()?([\w.]+)\s*=\s*(0x[0-9A-Fa-f]+)', l)
            if m: defs.setdefault(m.group(1), []).append((f, int(m.group(2), 16)))
    except OSError: pass
names = set()
for src in sorted(glob.glob('wip/out/func_*.c')):
    for n in re.findall(r'\b((?:func|D)_[0-9A-Fa-f]{8})\b', open(src).read()): names.add(n)
names |= {'osCreateMesgQueue','osContInit','osSetEventMesg','osGetThreadId','osSendMesg'}
bad = 0
for n in sorted(names):
    a = int(n[-8:], 16) if re.fullmatch(r'(?:func|D)_[0-9A-Fa-f]{8}', n) else None
    for f, v in defs.get(n, []):
        if a is not None and v != a and not (n.startswith('func_') and v == (a & 0xFFFFFF)):
            print('CONFLICT %s: %s says 0x%X, name says 0x%X' % (n, f, v, a)); bad += 1
print('checked', len(names), 'names against', len(files), 'symbol files:', bad, 'conflicts')
for n in ('osCreateMesgQueue','osContInit','osSetEventMesg','osGetThreadId','osSendMesg'):
    print(n, [(f, hex(v)) for f, v in defs.get(n, [])])
