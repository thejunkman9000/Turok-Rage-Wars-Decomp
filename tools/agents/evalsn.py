#!/usr/bin/env python3
"""evalsn.py <fn> <rom hex> <nrom insns> <xflags|-> file[::extra flags] ...   (run in WSL)
Compiles each file with the @SN pipeline and prints a structural mismatch metric vs the ROM:
  M = number of (normalised) instruction lines that differ from the ROM after difflib alignment (numbers/branch targets ignored,
      registers and mnemonics compared). Lower is better, 0 = structurally identical (constants may still differ)."""
import sys, os, re, subprocess, tempfile, difflib, shutil
from multiprocessing import Pool

HOME = os.path.expanduser('~')
SN = HOME + '/sn'
R = HOME + '/trw_s704'
ROM = '/mnt/d/Projects/ws/s704/baserom.us.v11.z64'


def sh(c):
    return subprocess.run(c, shell=True, capture_output=True, text=True)


def norm(t):
    t = re.sub(r'<[^>]*>', '', t)
    t = re.sub(r'\s+', ' ', t).strip()
    if re.match(r'(b|j)', t) and not re.match(r'jr|jalr', t):
        t = re.sub(r'[ ,][0-9a-fx]+$', ' T', t)
    t = re.sub(r'(?<![A-Za-z$_])-?(0x[0-9a-f]+|\d+)', 'N', t)
    return t


def disasm_rom(rom, n):
    d = open(ROM, 'rb').read()
    tmp = tempfile.mkdtemp()
    open(tmp + '/r.bin', 'wb').write(d[rom:rom + n * 4])
    out = sh(f'mips-linux-gnu-objdump -D -EB -b binary -m mips:4300 -M no-aliases,reg-names=32 {tmp}/r.bin').stdout
    shutil.rmtree(tmp)
    res = []
    for l in out.split('\n'):
        m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)', l)
        if m:
            res.append((m.group(2), m.group(3).strip()))
    return res


def compile_ours(args):
    arg, fn, xf0 = args
    f, xf = (arg.split('::', 1) + [''])[:2] if '::' in arg else (arg, xf0)
    xf = xf.replace(',', ' ')
    tmp = tempfile.mkdtemp()
    try:
        r = sh(f'cd {R} && cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their {f} > {tmp}/s.i && '
               f'{SN}/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 {xf} {tmp}/s.i -o {tmp}/s.s && '
               f'{SN}/n64link asn64 {tmp}/s.s | grep -v "[.]include" > {tmp}/n.s && bash tools/as.sh {tmp}/n.s {tmp}/s.o')
        if r.returncode != 0:
            return arg, None
        out = sh(f'mips-linux-gnu-objdump -dr -M no-aliases,reg-names=32 {tmp}/s.o').stdout
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    on = False
    ours = []
    for l in out.split('\n'):
        if re.match(r'[0-9a-f]+ <' + fn + r'>:', l):
            on = True
            continue
        if on and re.match(r'[0-9a-f]+ <.*>:', l):
            break
        if on:
            m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)', l)
            if m:
                ours.append((m.group(2), m.group(3).strip()))
    return arg, ours


def metric(ours, rom):
    a = [norm(x[1]) for x in ours]
    b = [norm(x[1]) for x in rom]
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    m = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag != 'equal':
            m += max(i2 - i1, j2 - j1)
    return m


if __name__ == '__main__':
    fn, rom, n, xf = sys.argv[1:5]
    files = sys.argv[5:]
    xf = '' if xf == '-' else xf
    rom_i = disasm_rom(int(rom, 16), int(n))
    with Pool(4) as p:
        for arg, ours in p.imap(compile_ours, [(f, fn, xf) for f in files]):
            if ours is None:
                print(f'COMPILE-FAIL {arg}')
                continue
            m = metric(ours, rom_i)
            print(f'{m:4d} {0:4d} insns={len(ours)} {arg}')
