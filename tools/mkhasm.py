#!/usr/bin/env python3
"""Turn ranges of the splat-generated asm into named hand-written-assembly sources under src/.

usage: python tools/mkhasm.py <spec-file> [--subdir libultra]
spec line:  <file name> <rom_start_hex> <rom_end_hex> [<primary glabel>] [pad=<trailing garbage words>]      ('#' starts a comment)

For each line a file src/<subdir>/<file name>.s is written containing the instructions of ROM [start, end).
 - splat's own `glabel`/`endlabel`/`nonmatching` markers at the start/end are replaced by `glabel <primary>`
   (default: the file name) / `endlabel <primary>`; nested glabel/alabel lines are kept.
 - words after the last unconditional exit of the range (the linker padded every object to 16 bytes with stray
   words from elsewhere) are emitted as `.word` so they never turn into dangling references.
 - an instruction that references a `.L` label which is not defined in the range is emitted as `.word`.
Run after `tools/cycle.ps1` (needs asm/*.s) and add `<file name> <start> <insns> <subdir>` to funcs.txt.
"""
import re, glob, sys, os

subdir = 'libultra'
args = [a for a in sys.argv[1:]]
if '--subdir' in args:
    i = args.index('--subdir'); subdir = args[i + 1]; del args[i:i + 2]
spec_path = args[0]

INSN = re.compile(r'^\s*/\*\s*([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})\s*\*/\s*(\S.*)$')
LABEL_DEF = re.compile(r'^\s*(\.L[0-9A-Fa-f]+):')
LABEL_USE = re.compile(r'\.L[0-9A-Fa-f]+')

files = {}
where = {}                      # rom -> (path, line index)
for p in sorted(glob.glob('asm/*.s')):
    lines = open(p, encoding='utf-8').read().split('\n')
    files[p] = lines
    for i, l in enumerate(lines):
        m = INSN.match(l)
        if m:
            where[int(m.group(1), 16)] = (p, i)


def mnemonic(text):
    t = text.split('/*')[0].strip()
    return t.split()[0] if t else ''


def build(name, start, end, primary, force_pad=0):
    if start not in where or (end - 4) not in where:
        sys.exit(f'{name}: ROM 0x{start:X}-0x{end:X} not found in asm/ (run tools/cycle.ps1 first)')
    p, i0 = where[start]
    p2, i1 = where[end - 4]
    if p != p2:
        sys.exit(f'{name}: range spans two asm files ({p}, {p2})')
    lines = files[p]
    # labels directly in front of the first instruction (alabel / .L); glabels are replaced by our own
    j = i0
    pre = []
    while j > 0 and re.match(r'^\s*(glabel|alabel|\.L[0-9A-Fa-f]+:)', lines[j - 1]):
        j -= 1
        pre.insert(0, lines[j])
    pre = [l for l in pre if not re.match(r'^\s*glabel', l)]
    body = lines[i0:i1 + 1]
    body = [l for l in body if not re.match(r'^\s*(endlabel|nonmatching)\b', l) and 'Handwritten function' not in l]
    out = pre + body
    # padding after the last unconditional exit
    insn_idx = [k for k, l in enumerate(out) if INSN.match(l)]
    defined = {m.group(1) for l in out if (m := LABEL_DEF.match(l))}
    last_exit = None
    for k in insn_idx:
        mn = mnemonic(INSN.match(out[k]).group(4))
        if mn in ('jr', 'j', 'eret'):
            last_exit = k
    pad_from = None
    if last_exit is not None:
        pos = insn_idx.index(last_exit)
        keep = pos + (1 if mnemonic(INSN.match(out[last_exit]).group(4)) == 'eret' else 2)
        if keep < len(insn_idx):
            first_pad = insn_idx[keep]
            # no label may point into the padding (labels between the last exit and the first padding word count)
            tail_labels = [l for l in out[insn_idx[keep - 1] + 1:] if LABEL_DEF.match(l) or re.match(r'^\s*alabel', l)]
            if not tail_labels:
                pad_from = first_pad
    if force_pad:
        pad_from = insn_idx[len(insn_idx) - force_pad]
    if pad_from is not None:
        while pad_from > 0 and re.match(r'^\s*(glabel|endlabel|$)', out[pad_from - 1]):
            pad_from -= 1
    if os.environ.get('HASM_DEBUG') and pad_from is not None:
        print(name, pad_from, [out[x] for x in range(max(0, pad_from - 2), min(len(out), pad_from + 2))])
    res = []
    fixed = 0
    for k, l in enumerate(out):
        if pad_from is not None and k >= pad_from and re.match(r'^\s*(glabel|endlabel)', l):
            continue                      # symbol of a garbage fragment inside the padding
        m = INSN.match(l)
        if m:
            word = m.group(3).upper()
            rom_s = m.group(1).upper()
            vram = m.group(2).upper()
            is_pad = pad_from is not None and k >= pad_from
            uses = LABEL_USE.findall(m.group(4))
            if is_pad:
                res.append(f'    /* {rom_s} {vram} {word} */  .word      0x{word} /* linker padding */')
                continue
            if uses and any(u not in defined for u in uses):
                txt = m.group(4)          # a line fix_asm already turned into a .word carries its original text after `was: ` (a comment inside the comment would end it early)
                was = (txt.rsplit('was: ', 1)[-1].split('*/')[0] if 'was: ' in txt else txt.split('/*')[0]).strip()
                res.append(f'    /* {rom_s} {vram} {word} */  .word      0x{word} /* was: {was} */')
                fixed += 1
                continue
        res.append(l)
    n_insn = (end - start) // 4
    text = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '.set gp=64', '',
            '.section .text, "ax"', '',
            f'/* hand-written assembly, ROM 0x{start:X}-0x{end:X} (VRAM 0x{int(INSN.match(lines[i0]).group(2), 16):08X}) */',
            f'glabel {primary}'] + res + [f'endlabel {primary}', '']
    os.makedirs(f'src/{subdir}', exist_ok=True)
    with open(f'src/{subdir}/{name}.s', 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(text))
    pad_words = 0 if pad_from is None else sum(1 for l in out[pad_from:] if INSN.match(l))
    return n_insn, pad_words, fixed


for raw in open(spec_path):
    line = raw.split('#')[0].strip()
    if not line:
        continue
    f = line.split()
    name, start, end = f[0], int(f[1], 16), int(f[2], 16)
    primary = name
    force_pad = 0
    for extra in f[3:]:
        if extra.startswith('pad='):
            force_pad = int(extra[4:])
        else:
            primary = extra
    n, pad, fixed = build(name, start, end, primary, force_pad)
    print(f'{name:28s} 0x{start:X} {n:4d} insns  (padding words: {pad}, dangling branches -> .word: {fixed})')
    print(f'    funcs.txt:  {name} 0x{start:X} {n} {subdir}')
