#!/usr/bin/env python3
"""Set up a decomp-permuter dir for an @SN function (run in WSL).  usage: permsn_setup.py <src.c> <fn> <rom hex> [flags like -fno-builtin | @SN272]
creates ~/perm/s706_<fn>/{base.c,compile.sh,target.o,settings.toml}; run: cd ~/permuter && python3 permuter.py ~/perm/s706_<fn> -j N"""
import sys, os, re, subprocess, struct, difflib
src, fn, rom_hex = sys.argv[1], sys.argv[2], int(sys.argv[3], 16)
flags = sys.argv[4:]
R = os.path.expanduser('~/trw_s706'); SN = os.path.expanduser('~/sn')
D = os.path.expanduser(f'~/perm/s706_{fn}')
subprocess.run(f'rm -rf {D}; mkdir -p {D}', shell=True)
sh = lambda c: subprocess.run(c, shell=True, capture_output=True, text=True)
xf = ' '.join(t for t in flags if t.startswith('-f'))
is272 = '@SN272' in flags
cc = (f"{SN}/cc1_272 -quiet -G0 -mips3 -mgp32 -mfp32 -O2 {xf}" if is272 else
      f"{SN}/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 {xf}")
cpp = f"cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I{R}/include -I{R}/include/their"
r = sh(f"{cpp} {R}/{src} > {D}/pre.c")
open(f'{D}/compile.sh', 'w').write(f'''#!/usr/bin/env bash
set -e
in=$1; out=$3
t=$(mktemp -d); trap 'rm -rf $t' EXIT
{cc} $in -o $t/o.s
sed -i '/\.include .include\/\(labels\|macro\)\.inc/d' $t/o.s
{SN}/n64link asn64 --as mips-linux-gnu-as -I{R} -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3 $t/o.s -o $out
''')
os.chmod(f'{D}/compile.sh', 0o755)
r = sh(f"python3 {R}/tools/perm_strip.py {D}/pre.c {fn}")
open(f'{D}/base.c', 'w').write(r.stdout)
r = sh(f"{D}/compile.sh {D}/base.c -o {D}/base.o")
if r.returncode: print(r.stderr); sys.exit(1)
# relocs of base.o
rel = sh(f"mips-linux-gnu-objdump -r -j .text {D}/base.o").stdout
relocs = {}
for l in rel.splitlines():
    m = re.match(r'([0-9a-f]+) (R_MIPS_\w+)\s+(\S+)', l)
    if m: relocs[int(m.group(1), 16)] = (m.group(2), m.group(3))
# symbol offset/size
off = size = None
for l in sh(f"mips-linux-gnu-readelf -sW {D}/base.o").stdout.splitlines():
    f = l.split()
    if len(f) >= 8 and f[7] == fn: off = int(f[1], 16); size = int(f[2])
text = subprocess.run(f"mips-linux-gnu-objcopy -O binary -j .text {D}/base.o /dev/stdout", shell=True, capture_output=True).stdout
if size == 0 or size is None: size = len(text) - off
n = size // 4
ours = struct.unpack('>%dI' % n, text[off:off+size])
rom = open(f'{R}/baserom.us.v11.z64', 'rb').read()
# determine rom size: use ours size as guess unless TARGET_INSNS env
nrom = int(os.environ.get('TARGET_INSNS', n))
rw = struct.unpack('>%dI' % nrom, rom[rom_hex:rom_hex+4*nrom])
def mn(w):
    op = w >> 26
    if op == 0: return ('s', w & 0x3F)
    if op == 1: return ('r', (w >> 16) & 0x1F)
    if op == 0x11:
        rs = (w >> 21) & 0x1F
        return ('c', rs, w & 0x3F) if rs in (16, 17) else ('c', rs, (w >> 16) & 3)
    return op
sm = difflib.SequenceMatcher(None, [mn(w) for w in ours], [mn(w) for w in rw], autojunk=False)
amap = {}
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal':
        for k in range(i2 - i1): amap[j1 + k] = i1 + k
lines = ['.set noreorder', '.set noat', '.section .text', f'.globl {fn}', f'.type {fn}, @function', f'{fn}:']
for j, w in enumerate(rw):
    i = amap.get(j)
    ro = off + 4 * i if i is not None else None
    if ro is not None and ro in relocs:
        t, sym = relocs[ro]
        m = {'R_MIPS_26': 0x03FFFFFF, 'R_MIPS_HI16': 0xFFFF, 'R_MIPS_LO16': 0xFFFF}.get(t, 0)
        w = (w & ~m) | (ours[i] & m)
        lines.append(f'.reloc ., {t}, {sym}')
    lines.append(f'.word 0x{w:08X}')
lines.append(f'.size {fn}, . - {fn}')
open(f'{D}/target.s', 'w').write('\n'.join(lines) + '\n')
r = sh(f"mips-linux-gnu-as -EB -march=vr4300 -mabi=32 {D}/target.s -o {D}/target.o")
if r.returncode: print(r.stderr); sys.exit(1)
open(f'{D}/settings.toml', 'w').write(f'compiler_type = "gcc"\nfunc_name = "{fn}"\n')
print('created', D)
