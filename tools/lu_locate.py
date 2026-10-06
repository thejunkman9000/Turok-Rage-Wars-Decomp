"""Locate where a compiled function most likely lives in the ROM (structure match, immediates ignored).

usage: python tools/lu_locate.py <build_ud.json> [function ...]
Candidates are the function starts splat found (asm/*.s glabels, plus ones inside .L-split chunks).
Ranks by SequenceMatcher ratio over normalized instructions (mnemonic + registers).
"""
import sys, json, re, glob, struct, difflib, rabbitizer

rom = open('baserom.us.v11.z64', 'rb').read()
imm = re.compile(r'-?0x[0-9A-Fa-f]+|\b\d+\b|\. \+ 4 \+ \(.*?\)|func_[0-9A-Fa-f]+|%\w+\(.*?\)')

def norm_word(w):
    s = rabbitizer.Instruction(w).disassemble()
    return imm.sub('#', s)

# function starts (ROM offsets) from splat's output, in the main code range
starts = set()
for p in glob.glob('asm/*.s') + glob.glob('asm/nonmatchings/**/*.s', recursive=True):
    for m in re.finditer(r'glabel \S+\n\s+/\* ([0-9A-F]+) ', open(p, encoding='utf-8').read()):
        starts.add(int(m.group(1), 16))
starts = sorted(s for s in starts if 0x1000 <= s < 0xC7010)

def window(off, n):
    return [norm_word(struct.unpack_from('>I', rom, off + 4 * i)[0]) for i in range(n)]

data = json.load(open(sys.argv[1]))
want = set(sys.argv[2:])
for f in data:
    if want and f['name'] not in want: continue
    ours = []
    for w, m in zip(f['words'], f['mask']):
        ours.append(norm_word(int(w, 16) & ~m if m else int(w, 16)))
    n = len(ours)
    res = []
    for s in starts:
        sm = difflib.SequenceMatcher(None, ours, window(s, n + 2), autojunk=False)
        res.append((sm.ratio(), s))
    res.sort(reverse=True)
    print(f"## {f['name']} ({n} insns): " + ', '.join(f'0x{s:X}={r:.2f}' for r, s in res[:4]))
