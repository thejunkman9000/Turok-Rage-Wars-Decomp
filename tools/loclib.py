"""Shared helpers for the ROM locator tools (Windows side; needs rabbitizer). Run from the project root."""
import re, glob, struct, rabbitizer

rom = open('baserom.us.v11.z64', 'rb').read()
_imm = re.compile(r'-?0x[0-9A-Fa-f]+|\b\d+\b|\. \+ 4 \+ \(.*?\)|func_[0-9A-Fa-f]+|%\w+\(.*?\)')

def norm_word(w):
    """Instruction text with immediates/targets removed: mnemonic + registers only."""
    return _imm.sub('#', rabbitizer.Instruction(w).disassemble())

def function_starts(lo=0x1000, hi=0xC7010):
    """ROM offsets of every function splat found (asm/*.s and asm/nonmatchings glabels)."""
    out = set()
    for p in glob.glob('asm/*.s') + glob.glob('asm/nonmatchings/**/*.s', recursive=True):
        for m in re.finditer(r'glabel \S+\n\s+/\* ([0-9A-F]+) ', open(p, encoding='utf-8').read()):
            out.add(int(m.group(1), 16))
    return sorted(s for s in out if lo <= s < hi)

def rom_window(off, n):
    return [norm_word(struct.unpack_from('>I', rom, off + 4 * i)[0]) for i in range(n)]

def our_norm(words, masks):
    return [norm_word(int(w, 16) & ~m if m else int(w, 16)) for w, m in zip(words, masks)]
