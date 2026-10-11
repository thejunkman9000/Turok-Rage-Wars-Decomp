#!/usr/bin/env python3
"""Second opinion on a chk result through the REAL build path (tools/cc.sh sn + as.sh), as the lead's make does:
  ccchk.py <src.c> <rom hex of the object's first function> [ro=0xROM:size]
compiles the file with tools/cc.sh (mode sn; other build modes via env MODE, e.g. MODE=sn+nb for -fno-builtin), compares the whole .text of the object with the ROM
(relocated words masked, and each relocation's symbol+addend checked against the ROM word the same way chk does), the .rodata with the ROM piece (ro=...), and
reports an unexpected .rodata.  Unlike chk it also verifies the `j` targets inside the function (R_MIPS_26 against .text, which chk masks and skips).
The object may hold several consecutive functions (group file): the ROM offset is the first function's.
Run in WSL, cwd ~/trw_<ws> (after fchk synced the files).  Exit status 0 = OK."""
import os, re, struct, subprocess, sys, tempfile
P = 'mips-linux-gnu'
rom = open(os.environ.get('ROM', 'baserom.us.v11.z64'), 'rb').read()
src = sys.argv[1]; rom_off = int(sys.argv[2], 16)
ro = next((a for a in sys.argv[3:] if a.startswith('ro=')), None)
mode = os.environ.get('MODE', 'sn')
env = dict(os.environ)
if ro:
    o, s = ro[3:].split(':'); env['CC_RO_OFF'] = str(int(o, 16)); env['CC_RO_SIZE'] = s
obj = tempfile.mktemp(suffix='.o')
r = subprocess.run(['bash', 'tools/cc.sh', mode, src, obj], capture_output=True, text=True, env=env)
if r.returncode or not os.path.exists(obj):
    print('COMPILE FAILED', r.stderr[-600:]); sys.exit(2)
def run(*a): return subprocess.run(a, capture_output=True, text=True).stdout
subprocess.run([P + '-objcopy', '-O', 'binary', '-j', '.text', obj, obj + '.bin'])
text = open(obj + '.bin', 'rb').read()
n = len(text) // 4
fw = struct.unpack('>%dI' % n, text)
rw = struct.unpack('>%dI' % n, rom[rom_off:rom_off + 4 * n])
# relocations in .text
rel = {}
cur = False
for l in run(P + '-readelf', '-rW', obj).splitlines():
    if l.startswith('Relocation section'): cur = "'.rel.text'" in l or "'.rela.text'" in l; continue
    f = l.split()
    if cur and len(f) >= 5 and re.fullmatch(r'[0-9a-f]+', f[0]) and f[2] in ('R_MIPS_26', 'R_MIPS_HI16', 'R_MIPS_LO16'):
        rel[int(f[0], 16)] = (f[2], f[4])
syms = {}
for l in run(P + '-readelf', '-sW', obj).splitlines():
    f = l.split()
    if len(f) >= 8 and f[3] in ('FUNC', 'NOTYPE') and f[4] == 'GLOBAL' and f[6].isdigit(): syms[f[7]] = int(f[1], 16)
mask = {'R_MIPS_26': 0x03FFFFFF, 'R_MIPS_HI16': 0xFFFF, 'R_MIPS_LO16': 0xFFFF}
bad = []
for i in range(n):
    m = 0xFFFFFFFF ^ mask.get(rel.get(4 * i, ('',))[0], 0)
    if (fw[i] & m) != (rw[i] & m): bad.append(i)
print('%s: text %d insns, functions %s' % (os.path.basename(src), n, ' '.join('%s@+0x%X' % kv for kv in sorted(syms.items(), key=lambda kv: kv[1]))))
print('  code words differing (relocs masked): %d %s' % (len(bad), bad[:8]))
# relocation targets: every reloc symbol must resolve to what the ROM encodes (jal targets, lui/addiu pairs)
SY = {}
for fn in ('symbol_addrs.txt', 'undefined_syms_auto.txt', 'undefined_funcs_auto.txt', 'hardware_regs.ld', 'extra_syms.ld', 'c_syms.ld', 'their_syms.ld'):
    if os.path.exists(fn):
        for l in open(fn, errors='replace'):
            m = re.match(r'\s*(?:PROVIDE\()?(\w+)\s*=\s*(0x[0-9A-Fa-f]+)', l)
            if m: SY.setdefault(m.group(1), int(m.group(2), 16))
def addr_of(sym):
    m = re.fullmatch(r'(?:D|func|jtbl)_([0-9A-Fa-f]{8})', sym)
    if m: return int(m.group(1), 16)
    return SY.get(sym)
sx = lambda v: v - 0x10000 if v & 0x8000 else v
nreloc = 0; rbad = []; hi = {}
for i in range(n):
    t = rel.get(4 * i)
    if not t: continue
    typ, sym = t
    a = addr_of(sym)
    if sym == '.text':                                   # jump inside the object: absolute target = VRAM of the object's first word + offset
        a = (0x400000 + rom_off - 0x16E000) if rom_off >= 0x16E000 else (rom_off + 0x1FF400)
    if a is None: rbad.append((i, sym, 'unknown symbol')); continue
    nreloc += 1
    if typ == 'R_MIPS_26':
        want = ((a + ((fw[i] & 0x3FFFFFF) << 2)) >> 2) & 0x3FFFFFF
        if want != (rw[i] & 0x3FFFFFF): rbad.append((i, sym, 'jal 0x%X vs rom 0x%X' % (want << 2, (rw[i] & 0x3FFFFFF) << 2)))
    elif typ == 'R_MIPS_HI16':
        hi[sym] = (fw[i] & 0xFFFF, rw[i] & 0xFFFF)
    elif typ == 'R_MIPS_LO16' and sym in hi:
        fh, rh = hi[sym]
        rom_addr = ((rh << 16) + sx(rw[i] & 0xFFFF)) & 0xFFFFFFFF
        want = (a + (fh << 16) + sx(fw[i] & 0xFFFF)) & 0xFFFFFFFF
        if rom_addr != want: rbad.append((i, sym, 'addr 0x%08X vs rom 0x%08X' % (want, rom_addr)))
print('  relocations checked: %d, mismatches: %d %s' % (nreloc, len(rbad), rbad[:6]))
status = 0 if not bad and not rbad else 1
# rodata
subprocess.run([P + '-objcopy', '-O', 'binary', '-j', '.rodata', obj, obj + '.ro'])
blob = open(obj + '.ro', 'rb').read() if os.path.exists(obj + '.ro') else b''
if ro:
    o, s = int(ro[3:].split(':')[0], 16), int(ro[3:].split(':')[1])
    print('  rodata: object %d bytes, ro piece %d bytes at 0x%X: %s' % (len(blob), s, o, 'IDENTICAL' if blob[:s] == rom[o:o + s] and len(blob) == s else 'DIFFERS ' + blob.hex() + ' vs ' + rom[o:o + s].hex()))
    if not (blob[:s] == rom[o:o + s] and len(blob) == s): status = 1
else:
    print('  rodata: object %d bytes %s' % (len(blob), '(none expected)' if not blob else '<-- unexpected rodata ' + blob.hex()))
    if blob: status = 1
print('  =>', 'OK' if status == 0 else 'MISMATCH')
sys.exit(status)
