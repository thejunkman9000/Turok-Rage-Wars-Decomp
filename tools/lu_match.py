#!/usr/bin/env python3
"""Compile libultra C sources with an old GCC and search the Rage Wars ROM for each function.

usage: lu_match.py <gcc-version> [extra gcc flags ...] -- <src.c> [<src.c> ...]
Words the linker would patch (reloc'd jal / lui / lo16) are masked on both sides before comparing.
Run inside WSL from the project root.
"""
import re, subprocess, sys, os, struct, collections, tempfile

args = sys.argv[1:]
ver = args[0]
sep = args.index('--')
extra, srcs = args[1:sep], args[sep + 1:]

ROOT = os.getcwd()
G = f"{ROOT}/tools/gcc/{ver}"
LU = os.path.expanduser('~/libreultra')
P = 'mips-linux-gnu'
rom = open(f'{ROOT}/baserom.us.v11.z64', 'rb').read()
# code regions (ROM offsets): main, overlay A
REGIONS = [(0x1000, 0xC7010, 'main'), (0x16E000, 0x1BCDA0, 'ovl_a')]

def sh(cmd, **kw):
    return subprocess.run(cmd, shell=True, capture_output=True, text=True, **kw)

sys.path.insert(0, os.path.join(ROOT, 'tools'))
import gas_compat

def fix_asm(s):
    gas_compat.NOFILL = '-DNOFILL' in extra
    s = gas_compat.fix(s, 'lu')
    return s
    s = re.sub(r'^([ \t]*)move[ \t]+(\$[a-z0-9]+),[ \t]*(\$[a-z0-9]+)', r'\1addu\t\2,\3,$0', s, flags=re.M)
    # NOTE: libultra's returns have the sp adjust in the jr delay slot (modern gas behaviour), so unlike
    # Acclaim's own code (tools/cc_try.sh) there is no `j $31` -> nop rewrite here.
    return s

MASK = {4: 0x03FFFFFF, 5: 0xFFFF, 6: 0xFFFF}   # R_MIPS_26, HI16, LO16
LAST = {}   # side results of the last compile_funcs call (rodata bytes)

def compile_funcs(src):
    tmp = tempfile.mkdtemp()
    base = os.path.basename(src)[:-2]
    cp = f'{tmp}/{base}.c'; open(cp, 'w').write(open(src).read())
    if '@SN' in extra or '@SN272' in extra:
        # melalawi/ragewars-decomp toolchain: preprocessor + pmret gcc 2.8.1 (or the KMC gcc 2.7.2 for the low region) + n64link asn64
        # (normalises the SN64 cc1 assembly) + GNU as.  tools/sn_setup.sh installs the three programs in ~/sn.
        SN = os.path.expanduser('~/sn')
        xf = ' '.join(t for t in extra if (t.startswith('-f') or t.startswith('-m') or t.startswith('-W')) and not t.startswith('-mcpu='))
        cpu = next((t[6:] for t in extra if t.startswith('-mcpu=')), 'VR4300')
        inc = os.environ.get('LU_INC', os.path.expanduser('~/trw/include'))
        cc = (f"{SN}/cc1_272 -quiet -G0 -mips3 -mgp32 -mfp32 -O2 {xf}" if '@SN272' in extra else
              f"{SN}/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu={cpu} -mhard-float -mgp32 -mfp64 -mno-fix4300 {xf}")
        r = sh(f"cd {tmp} && cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I{inc} -I{os.environ.get('SN_INC', inc + '/their')} -I{os.environ.get('SN_INC2', inc)} {base}.c > {base}.i && "
               f"{cc} {base}.i -o {base}.s && python3 {ROOT}/tools/sn_expand.py {base}.s && sed -i '/\.include .include\/\(labels\|macro\)\.inc/d' {base}.s && {SN}/n64link asn64 --as {P}-as -I{os.path.expanduser('~/trw')} -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3 {base}.s -o {base}.o && "
               f"{P}-objcopy --rename-section .rdata=.rodata,alloc,load,readonly,data,contents {base}.o && "
               f"{P}-objcopy -O binary -j .text {base}.o {base}.bin")
        if r.returncode:
            return None, (r.stderr.strip().splitlines() or ['sn pipeline failed'])[:3]
        asm = None
    else:
      flags = ' '.join(extra) or '-O2'
      isa = os.environ.get('LU_ISA', '-mips3 -mgp32')   # override e.g. LU_ISA="-mips2 -mgp32 -mfp32"
      r = sh(f"cd {tmp} && {G}/gcc -B{G}/ -meb {isa} -G 0 -mno-abicalls -fno-pic {flags} "
             f"-I{os.environ.get('LU_INC', os.path.expanduser('~/trw/include'))} -I{LU}/include -I{LU}/include/PR -I{LU}/lib/src -DINCLUDE_ASM_USE_MACRO_INC=1 -D_LANGUAGE_C -DTARGET_N64 -D_FINALROM -DNDEBUG -S -o {base}.s {base}.c")
      if r.returncode:
          return None, r.stderr.strip().splitlines()[:3]
      asm = fix_asm(open(f'{tmp}/{base}.s').read())
      open(f'{tmp}/{base}.s', 'w').write(asm)
      r = sh(f"cd {tmp} && {P}-as -EB -march=vr4300 -mabi=32 -mno-pdr -W -I {os.path.expanduser("~/trw")} -I {os.path.expanduser("~/trw/include")} -o {base}.o {base}.s && "
             f"{P}-objcopy -O binary -j .text {base}.o {base}.bin")
      if r.returncode:
          return None, r.stderr.strip().splitlines()[:3]
    text = open(f'{tmp}/{base}.bin', 'rb').read()
    sh(f"cd {tmp} && {P}-objcopy -O binary -j .rodata {base}.o {base}.ro")
    LAST['ro'] = open(f'{tmp}/{base}.ro', 'rb').read() if os.path.exists(f'{tmp}/{base}.ro') else b''
    # gcc 2.7.2 emits no .type/.size: take global symbols defined in .text, size = distance to next one
    starts = []
    for l in sh(f"{P}-readelf -sW {tmp}/{base}.o").stdout.splitlines():
        f = l.split()
        if len(f) >= 8 and f[4] == 'GLOBAL' and f[6].isdigit() and f[3] in ('NOTYPE', 'FUNC'):
            starts.append((int(f[1], 16), f[7]))
    starts.sort()
    syms = []
    for i, (a, n) in enumerate(starts):
        end = starts[i + 1][0] if i + 1 < len(starts) else len(text)
        if end > a:
            size = end - a
            size -= size % 4
            fw = struct.unpack('>%dI' % (size // 4), text[a:a + size])
            rets = [k for k, w in enumerate(fw) if w == 0x03E00008]
            if rets: size = 4 * (rets[-1] + 2)      # drop alignment padding after the last return
            syms.append((n, a, size))
    relocs = collections.defaultdict(int)
    relnames = {}                      # offset -> (reloc type, symbol name)
    in_text = False
    for l in sh(f"{P}-readelf -rW {tmp}/{base}.o").stdout.splitlines():
        if l.startswith('Relocation section'):
            in_text = "'.rel.text'" in l or "'.rela.text'" in l
            continue
        f = l.split()
        if in_text and len(f) >= 3 and re.fullmatch(r'[0-9a-f]+', f[0]):
            t = f[2]
            code = {'R_MIPS_26': 4, 'R_MIPS_HI16': 5, 'R_MIPS_LO16': 6}.get(t)
            if code:
                relocs[int(f[0], 16)] = MASK[code]
                if len(f) >= 5: relnames[int(f[0], 16)] = (t, f[4])
    return (text, syms, relocs, relnames), None

def words(b): return struct.unpack('>%dI' % (len(b) // 4), b)

ROMW = {}
for lo, hi, n in REGIONS: ROMW[n] = (lo, words(rom[lo:hi - ((hi - lo) % 4)]))

def search(name, text, off, size, relocs):
    fw = list(words(text[off:off + size]))
    msk = [0xFFFFFFFF ^ relocs.get(off + 4 * i, 0) for i in range(len(fw))]
    fwm = [w & m for w, m in zip(fw, msk)]
    # anchor on the rarest fully-unmasked word
    cand = [(rom.count(struct.pack('>I', fw[i])), i) for i in range(len(fw)) if msk[i] == 0xFFFFFFFF]
    best = (0, None, None)
    if not cand: return best
    cnt, ai = min(cand)
    anchor = struct.pack('>I', fw[ai])
    for rname, (lo, rw) in ROMW.items():
        start = lo
        while True:
            p = rom.find(anchor, start, lo + len(rw) * 4)
            if p < 0 or p % 4:
                if p < 0: break
                start = p + 1; continue
            start = p + 4
            s = (p - lo) // 4 - ai
            if s < 0 or s + len(fw) > len(rw): continue
            eq = sum(1 for i in range(len(fw)) if (rw[s + i] & msk[i]) == fwm[i])
            if eq > best[0]: best = (eq, lo + 4 * s, rname)
    return best

tot = ex = 0
for src in srcs:
    path = src if os.path.isabs(src) else f'{LU}/lib/src/{src}'
    res, err = compile_funcs(path)
    if res is None:
        print(f'{os.path.basename(path):26s} COMPILE FAIL: {err}'); continue
    text, syms, relocs, relnames = res
    for name, off, size in sorted(syms, key=lambda x: x[1]):
        n = size // 4
        eq, rom_off, reg = search(name, text, off, size, relocs)
        tot += 1
        status = 'EXACT' if eq == n else f'{eq}/{n}'
        if eq == n: ex += 1
        loc = f'ROM 0x{rom_off:X} ({reg})' if rom_off is not None else '-'
        print(f'{name:26s} {n:4d} insns  {status:9s} {loc}')
print(f'-- gcc {ver} {" ".join(extra) or "-O2"}: {ex}/{tot} functions found exactly')
