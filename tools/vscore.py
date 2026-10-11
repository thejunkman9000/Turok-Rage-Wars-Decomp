#!/usr/bin/env python3
"""Score many source variants of one function against the ROM (run in WSL, cwd ~/trw): the number of ROM instruction words that have no counterpart in our
compiled function after an alignment (difflib on instruction words).  The comparison key is loose where a linker would have patched the word: jal/j keep only
the opcode, lui keeps opcode+registers, and loads/stores/addiu/ori through a base register other than $sp keep opcode+registers but not the immediate
(struct field offsets are therefore not scored; run tools/chk.py for the real verdict).

usage: python3 tools/vscore.py <cc mode> <function> <rom hex> <n insns> <file.c> [<file.c> ...]
prints `score ours_insns file` sorted by score (0 = every word matches)."""
import difflib, os, re, subprocess, sys, tempfile
args = sys.argv[1:]
mode, fn, rom_hex, n = args[0], args[1], int(args[2], 16), int(args[3])
files = args[4:]
rom = open(os.environ.get('ROM', 'baserom.us.v11.z64'), 'rb').read()[rom_hex:rom_hex + 4 * n]
tmpb = tempfile.mktemp(suffix='.bin'); open(tmpb, 'wb').write(rom)
def words(path, flag='-d', extra=()):
    cmd = ['mips-linux-gnu-objdump', flag] + (['-j', '.text'] if flag == '-d' else []) + ['-M', 'no-aliases,reg-names=numeric'] + list(extra) + [path]
    out = subprocess.run(cmd, capture_output=True, text=True).stdout
    res = []
    for l in out.split('\n'):
        m = re.match(r'\s*[0-9a-f]+:\s+([0-9a-f]{8})\s+', l)
        if m: res.append(int(m.group(1), 16))
    return res
LOOSE_IMM = (9, 13, 32, 33, 35, 36, 37, 40, 41, 43, 49, 57, 53, 61)      # addiu ori lb lh lw lbu lhu sb sh sw lwc1 swc1 ldc1 sdc1
def key(w):
    op = w >> 26
    if op in (2, 3): return op
    if op == 15: return w >> 16
    if op in LOOSE_IMM and ((w >> 21) & 31) != 29: return w >> 16
    return w
B = [key(w) for w in words(tmpb, '-D', ['-b', 'binary', '-EB', '-mmips:4000'])[:n]]
res = []
for f in files:
    obj = tempfile.mktemp(suffix='.o')
    r = subprocess.run(['bash', 'tools/cc.sh', mode, f, obj], capture_output=True, text=True)
    if r.returncode: res.append((10 ** 6, 0, f, r.stderr[-200:].replace('\n', ' '))); continue
    A = [key(w) for w in words(obj)]
    sm = difflib.SequenceMatcher(None, A, B, autojunk=False)
    bad = sum(max(i2 - i1, j2 - j1) for tag, i1, i2, j1, j2 in sm.get_opcodes() if tag != 'equal')
    res.append((bad, len(A), f, ''))
res.sort()
for bad, k, f, err in res: print('%5d %5d %s %s' % (bad, k, f, err))
