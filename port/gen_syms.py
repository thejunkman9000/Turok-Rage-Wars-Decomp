#!/usr/bin/env python3
"""Generate port/gen/syms.asm (absolute data symbols at their guest addresses), port/gen/stubs.c (logging stubs for
functions that are not C yet) and port/gen/alias.rsp (linker aliases between the two naming schemes) from the linker's list of
unresolved externals.
usage: python port/gen_syms.py <link log> [--merge]

Two naming schemes meet in the game C: ours (func_00XXXXXX / D_XXXXXXXX, named by the US v1.1 address) and the one of the
other public decompilation (their_syms.ld: func_8028FDB4_de, D_800C1B98_de, osSetThreadPri ... -> US v1.1 address) used by the
sources ported from it.  A symbol that is unresolved but whose address is defined under another name gets an
/ALTERNATENAME alias to that definition; data is an absolute symbol at its address (their_syms.ld wins over the name)."""
import collections, os, re, struct, sys, glob
log = open(sys.argv[1], encoding='utf-8', errors='replace').read()
unres = set(re.findall(r'unresolved external symbol _(\w+)', log))
# data symbols referenced through C asm labels (undecorated names, e.g. extern u8 X[] asm("D_800D2F90"))
plain_alias = set(re.findall(r'unresolved external symbol (D_(?:auto_)?[0-9A-Fa-f]{3,8})\b', log))
unres |= plain_alias
if '--merge' in sys.argv and os.path.exists('port/gen/syms.asm'):
    unres |= set(re.findall(r'^PUBLIC _(\w+)', open('port/gen/syms.asm').read(), re.M))
    unres |= set(re.findall(r'^(?:int|char) (\w+)[\[(]', open('port/gen/stubs.c').read(), re.M))
unres = sorted(unres)
ASSIGN = re.compile(r'^\s*(?:PROVIDE\()?\s*([\w.]+)\s*=\s*(0x[0-9A-Fa-f]+)\s*\)?;', re.M)
addr = {}
for f in ('c_syms.ld', 'extra_syms.ld', 'undefined_syms_auto.txt', 'undefined_funcs_auto.txt', 'hardware_regs.ld'):
    if os.path.exists(f):
        for m in ASSIGN.finditer(open(f).read()):
            addr[m.group(1)] = int(m.group(2), 16)
their = {}                                  # the other decompilation's names -> US v1.1 address (the linker script of the ROM build)
if os.path.exists('their_syms.ld'):
    for m in ASSIGN.finditer(open('their_syms.ld').read()):
        their[m.group(1)] = int(m.group(2), 16)
for n, a_ in their.items():
    addr.setdefault(n, a_)                  # PROVIDE semantics like the ROM link (-T order): a name that our own lists define keeps OUR address.  Plain D_XXXXXXXX
                                            # names exist in both schemes with different meanings (their D_0022ECCC is our 0x0022ECBC): our code means the address in the name
for m in re.finditer(r'^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;', open('symbol_addrs.txt').read(), re.M):
    addr.setdefault(m.group(1), int(m.group(2), 16))

CODE = lambda a_: 0x200000 <= a_ < 0x500000            # function addresses are spelled 0x00XXXXXX (overlay A at 0x400000)
names_at = collections.defaultdict(list)    # code address -> every name of it
for n, a_ in addr.items():
    if CODE(a_) and not n.startswith('D_') and not n.startswith('.'): names_at[a_].append(n)
if os.path.exists('their_alias.ld'):                       # our func_ names of functions that the ROM build defines under their names
    for m in ASSIGN.finditer(open('their_alias.ld').read()):
        a_ = int(m.group(2), 16); addr.setdefault(m.group(1), a_)
        if m.group(1) not in names_at[a_]: names_at[a_].append(m.group(1))

# ---- what the objects define (COFF symbol tables) ----
def coff_defined(path):
    d = open(path, 'rb').read()
    out = set()
    if len(d) < 20: return out
    ptr, nsym = struct.unpack_from('<II', d, 8)                 # PointerToSymbolTable, NumberOfSymbols of the COFF file header
    if ptr == 0 or ptr + 18 * nsym > len(d): return out
    strtab = ptr + 18 * nsym
    i = 0
    while i < nsym:
        o = ptr + 18 * i
        name8 = d[o:o + 8]; val, sec, typ, cls, naux = struct.unpack_from('<IhHBB', d, o + 8)
        if name8[:4] == b'\0\0\0\0':
            off = struct.unpack_from('<I', name8, 4)[0]
            e = d.index(b'\0', strtab + off); name = d[strtab + off:e].decode('latin1')
        else:
            name = name8.split(b'\0')[0].decode('latin1')
        if cls == 2 and sec > 0: out.add(name)
        i += 1 + naux
    return out
defined = set()
for p in glob.glob('port/build/' + os.environ.get('PORT_OBJ', 'obj_c') + '/*.obj') + [q for q in glob.glob('port/build/*.obj') if os.path.basename(q) not in ('syms.obj', 'stubs.obj', 'fnptrs.obj')]:
    defined |= coff_defined(p)
defined = {n[1:] if n.startswith('_') else n for n in defined}     # cdecl decoration
defined |= {'sinf', 'cosf', 'sqrtf', 'tanf', 'atan2f', 'fabsf', 'floorf', 'ceilf', 'fmodf', 'powf', 'sqrt', 'sin', 'cos', 'floor', 'ceil', 'fabs',
            'memcpy', 'memset', 'memmove', 'strlen', 'strcmp', 'strcpy', 'strncpy', 'strcat'}      # the host's C runtime provides these (the game's own copies are not compiled)

alias = {'D_80121990b': 'D_80121990'}
os.makedirs('port/gen', exist_ok=True)
data, funcs, other, thunks, links = [], [], [], [], {}
name_alias = {}
if os.path.exists('port/audio_alias.txt'):
    for l in open('port/audio_alias.txt'):
        f = l.split('#')[0].split()
        if len(f) == 2: name_alias[f[0]] = f[1]      # libultra .s-only functions: thunk to the recompiled function
name_alias = {n: t for n, t in name_alias.items() if n in unres and os.path.exists('port/native/recomp/%s.c' % t)}      # only what the linker actually misses
for n in unres:
    base = alias.get(n, n)
    if n in name_alias: continue
    a_ = addr.get(n)
    if (n.startswith('D_') or n.startswith('jtbl')) and a_ is not None:
        data.append((n, a_)); continue                              # a table address wins over the one spelled in the name
    if a_ is not None and CODE(a_):                                  # a function under some name: another name of it may be defined
        tgt = [t for t in names_at[a_] if t != n and t in defined]
        if tgt:
            links[n] = sorted(tgt, key=lambda t: (not re.fullmatch(r'func_[0-9A-F]{8}', t), t))[0]
        else:
            canon = 'func_%08X' % a_                                  # nobody defines it: one stub under the canonical name
            funcs.append(canon)
            if canon != n: links[n] = canon
        continue
    if re.fullmatch(r'D_[0-9A-Fa-f]{8}', base):
        data.append((n, int(base[2:], 16)))
    elif re.fullmatch(r'D_[0-9A-Fa-f]{3,6}', base):
        data.append((n, int(base[2:], 16)))
    elif re.fullmatch(r'func_[0-9A-Fa-f]{6}', n):
        thunks.append(n); funcs.append('func_00' + n[5:])      # overlay short spelling func_4058B0 = func_004058B0
    elif re.fullmatch(r'func_[0-9A-Fa-f]{8}', n):
        funcs.append(n)
    elif a_ is not None and a_ >= 0x80000000:
        data.append((n, a_))
    else:
        other.append(n)
known_funcs = defined | set(funcs)                           # data symbols that are really the address of a function: the C spells a code pointer D_XXXXXXXX
for n, a_ in list(data):
    if CODE(a_) and n.startswith('D_') and ('func_%08X' % a_) in known_funcs:
        links[n] = 'func_%08X' % a_; data.remove((n, a_))
hw = [(n, a_) for n, a_ in data if a_ >= 0xA0000000]       # hardware registers: plain zeroed variables in the port
data = [(n, a_) for n, a_ in data if a_ < 0xA0000000]
with open('port/gen/syms.asm', 'w') as f:
    f.write('.386\n.model flat\n')
    for n, a in data:
        f.write(f'PUBLIC _{n}\n_{n} EQU {a:08X}h\n')
        if n in plain_alias: f.write(f'PUBLIC {n}\n{n} EQU {a:08X}h\n')      # also reachable by its undecorated asm-label name
    f.write('.code\n')
    for n in thunks:                                   # overlay short spelling func_4058B0 -> func_004058B0
        f.write(f'EXTERN _func_00{n[5:]}:PROC\n')
    for n in thunks:
        f.write(f'PUBLIC _{n}\n_{n} PROC\n    jmp _func_00{n[5:]}\n_{n} ENDP\n')
    for n, t in name_alias.items():
        f.write('EXTERN _%s:PROC'%t + chr(10))
    for n, t in name_alias.items():
        f.write('PUBLIC _%s'%n + chr(10) + '_%s PROC'%n + chr(10) + '    jmp _%s'%t + chr(10) + '_%s ENDP'%n + chr(10))
    f.write('END\n')
funcs = sorted(set(funcs) - defined)
with open('port/gen/stubs.c', 'w') as f:
    f.write('/* generated by port/gen_syms.py: functions that are not C yet */\nextern void port_unimpl(const char *name);\n')
    for n, a_ in hw:
        f.write(f'char {n}[256];' + chr(10))
    for n in funcs + other:
        f.write(f'int {n}(void) {{ port_unimpl("{n}"); return 0; }}\n')
with open('port/gen/alias.rsp', 'w') as f:
    for n, t in sorted(links.items()):
        f.write(f'/ALTERNATENAME:_{n}=_{t}\n')
if os.path.isdir('port/build/asm_func'):      # a stub that is not the start of a recompilable function is an entry point INSIDE another function (the C calls func_004143E0 and the MIPS jal lands in the middle of func_004143D8)
    import bisect
    starts = sorted(int(m.group(1), 16) for f in os.listdir('port/build/asm_func') for m in [re.fullmatch(r'func_([0-9A-F]{8})\.s', f)] if m)
    forced = set(open('port/forced_entries.txt').read().split()) if os.path.exists('port/forced_entries.txt') else set()
    mid = []
    for n in funcs:
        a_ = int(n[5:], 16); i = bisect.bisect_right(starts, a_) - 1
        if i >= 0 and starts[i] != a_ and '%08X' % a_ not in forced: mid.append('%08X' % a_)
    if mid:
        with open('port/forced_entries.txt', 'a', newline=chr(10)) as ff: ff.write(chr(10).join(mid) + chr(10))
        print('new forced entries (inside other functions):', ' '.join(mid), ' -> run: python port/asm_all.py; python port/recomp_select.py; python port/gen_recomp.py (PORT_NO_ASM_REGEN=1 after the first)')
print(len(unres), 'unresolved:', len(data), 'data,', len(funcs), 'func stubs,', len(links), 'aliases,', len(other), 'other stubs')
if other: print('other:', other[:40])
if '--debug' in sys.argv:
    for n in funcs: print('stub', n, names_at.get(int(n[5:], 16), []))
