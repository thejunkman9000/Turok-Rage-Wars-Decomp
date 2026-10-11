#!/usr/bin/env python3
"""End-to-end check of one deliverable file through the REAL build path (tools/cc.sh sn, the same one the lead's cycle uses) instead of chk's lu_match path.

usage (WSL, cwd = ~/trw after rsync, or the /mnt tree):  unitchk.py <src.c> <rom hex of the first function> [<ro offset hex> <ro size>]
 - compiles with `bash tools/cc.sh sn <src> <obj>` (CC_RO_OFF / CC_RO_SIZE from the arguments, as tools/rodoc.py does)
 - the object's .text must be exactly the unit's size, every word equal to the ROM word except relocated words
   (R_MIPS_26 / HI16 / LO16 words are compared after masking, and the relocation target must resolve to the ROM's address: symbol address via the name)
 - lists the function symbols (name, offset, size) in text order and the relocation symbol names (hygiene: no DE-addressed names)
 - rodata: the object's .rodata must equal the ROM bytes at the ro piece (jump-table words are relocated words and are masked)"""
import os, re, struct, subprocess, sys, tempfile
ROM = open(os.environ.get('ROM', 'baserom.us.v11.z64'), 'rb').read()
src = sys.argv[1]; rom0 = int(sys.argv[2], 16)
ro_off = int(sys.argv[3], 16) if len(sys.argv) > 3 else None
ro_size = int(sys.argv[4]) if len(sys.argv) > 4 else None
P = 'mips-linux-gnu-'
def run(*a, **k): return subprocess.run(a, capture_output=True, text=True, **k)
SYMS = {}
for f in ('symbol_addrs.txt', 'undefined_syms_auto.txt', 'undefined_funcs_auto.txt', 'hardware_regs.ld', 'extra_syms.ld', 'c_syms.ld', 'their_syms.ld', 'their_alias.ld'):
    try:
        for l in open(f, encoding='utf-8', errors='replace'):
            m = re.match(r'\s*(?:PROVIDE\()?(\w+)\s*=\s*(0x[0-9A-Fa-f]+)', l)
            if m: SYMS.setdefault(m.group(1), int(m.group(2), 16))
    except OSError: pass
def symaddr(n):
    m = re.fullmatch(r'(?:D|func|jtbl)_([0-9A-Fa-f]{8})', n)
    if m: return int(m.group(1), 16)          # OUR naming: the address is in the name
    if n in SYMS: return SYMS[n]               # named symbols (libultra: osSendMesg = 0x002C0510 ...)
    return None
obj = tempfile.mktemp(suffix='.o')
env = dict(os.environ)
if ro_off: env['CC_RO_OFF'] = str(ro_off)
if ro_size: env['CC_RO_SIZE'] = str(ro_size)
r = subprocess.run(['bash', 'tools/cc.sh', 'sn', src, obj], capture_output=True, text=True, env=env)
if r.returncode or not os.path.exists(obj):
    print('COMPILE FAILED', r.stderr[-600:]); sys.exit(2)
binp = tempfile.mktemp(suffix='.bin')
run(P + 'objcopy', '-O', 'binary', '-j', '.text', obj, binp)
text = open(binp, 'rb').read(); os.remove(binp)
n = len(text) // 4
print('object text: %d insns (%d bytes)' % (n, len(text)))
# function symbols
syms = []
for l in run(P + 'readelf', '-sW', obj).stdout.splitlines():
    f = l.split()
    if len(f) >= 8 and f[3] in ('FUNC', 'NOTYPE') and f[6] != 'UND' and f[4] == 'GLOBAL': syms.append((int(f[1], 16), int(f[2]), f[7]))
syms.sort()
print('symbols:', ' '.join('%s@+0x%X(size %d)' % (s[2], s[0], s[1]) for s in syms))
# relocations in .text
rel = {}
cur = False
for l in run(P + 'readelf', '-rW', obj).stdout.splitlines():
    if l.startswith('Relocation section'): cur = ".rel.text'" in l or ".rela.text'" in l; continue
    f = l.split()
    if cur and len(f) >= 5 and re.fullmatch(r'[0-9a-f]+', f[0]): rel[int(f[0], 16)] = (f[2], f[4])
names = sorted({v[1] for v in rel.values()})
named = set(re.findall(r'^(\w+)\s*=\s*0x', open('symbol_addrs.txt', errors='replace').read(), re.M))      # real names of our symbol table (libultra)
bad_names = [x for x in names if not re.fullmatch(r'(?:D|func|jtbl)_[0-9A-Fa-f]{8}|\.rodata|\.rdata|\.text|\.data|\.bss', x) and x not in named]
print('relocation symbols:', ' '.join(names))
if bad_names: print('  !! unexpected symbol names (not US-address names):', bad_names)
# compare text
sx = lambda v: v - 0x10000 if v & 0x8000 else v
mism = []
hi = {}
for i in range(n):
    o = 4 * i
    w = struct.unpack('>I', text[o:o + 4])[0]; rw = struct.unpack('>I', ROM[rom0 + o:rom0 + o + 4])[0]
    if o in rel:
        t, s = rel[o]
        if t == 'R_MIPS_26':
            a = symaddr(s) if s != '.text' else (0x400000 + rom0 - 0x16E000)      # local jump: section-relative, the object starts at the unit's VRAM
            exp = ((a + ((w & 0x3FFFFFF) << 2)) >> 2) & 0x3FFFFFF if a is not None else None
            if w >> 26 != rw >> 26 or (exp is not None and exp != (rw & 0x3FFFFFF)) or exp is None: mism.append((i, w, rw, 'reloc26 ' + s))
        elif t in ('R_MIPS_HI16', 'R_MIPS_LO16'):
            if (w >> 16) != (rw >> 16): mism.append((i, w, rw, 'hi/lo opcode ' + s))
            elif t == 'R_MIPS_HI16': hi[s] = (w & 0xFFFF, rw & 0xFFFF)
            else:
                a = symaddr(s)
                if a is not None and s in hi:
                    hw, rhw = hi[s]
                    rom_addr = ((rhw << 16) + sx(rw & 0xFFFF)) & 0xFFFFFFFF
                    exp = (a + (hw << 16) + sx(w & 0xFFFF)) & 0xFFFFFFFF
                    if rom_addr != exp: mism.append((i, w, rw, 'lo16 addr %s: ours %08X rom %08X' % (s, exp, rom_addr)))
                elif a is None: mism.append((i, w, rw, 'lo16 unresolved ' + s))
        else: mism.append((i, w, rw, 'other reloc ' + t))
    elif w != rw: mism.append((i, w, rw, 'plain word'))
print('TEXT: %s (%d mismatches)' % ('IDENTICAL' if not mism else 'DIFFERS', len(mism)))
for m in mism[:8]: print('   [%d] ours %08X rom %08X  %s' % m)
# rodata
if ro_off is not None:
    rp = tempfile.mktemp(suffix='.bin')
    run(P + 'objcopy', '-O', 'binary', '-j', '.rodata', obj, rp)
    ro = open(rp, 'rb').read() if os.path.exists(rp) else b''
    rr = set()
    cur = False
    for l in run(P + 'objdump', '-r', '-j', '.rodata', obj).stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]{8})\s+R_MIPS', l)
        if m: rr.add(int(m.group(1), 16))
    diff = [i for i in range(0, len(ro), 4) if i not in rr and ro[i:i + 4] != ROM[ro_off + i:ro_off + i + 4]]
    print('RODATA: object %d bytes, expected %s, %d relocated words, %s' % (len(ro), ro_size, len(rr), 'IDENTICAL to ROM' if not diff and len(ro) == (ro_size or len(ro)) else 'DIFFERS at %s' % [hex(d) for d in diff[:6]]))
else:
    rp = tempfile.mktemp(suffix='.bin')
    run(P + 'objcopy', '-O', 'binary', '-j', '.rodata', obj, rp)
    ro = open(rp, 'rb').read() if os.path.exists(rp) else b''
    print('RODATA: object has %d bytes of .rodata%s' % (len(ro), '  !! (pass the ro offset/size)' if ro else ' (none, as expected)'))
os.remove(obj)
