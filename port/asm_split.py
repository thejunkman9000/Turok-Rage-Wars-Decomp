#!/usr/bin/env python3
"""splat only puts glabels on jal targets it found; functions that are called through function pointers (or whose start it
mis-detected) are glued into their neighbours.  Insert extra glabels in every asm/*.s at:
   - all jal targets in the ROM's code
   - lui/addiu(ori) constants that look like code addresses
   - aligned ROM words that look like code pointers (function tables)
   - stack-frame prologues (addiu sp,sp,-N) that directly follow a jr ra + delay slot
Output: port/build/asm_extra/<same name>.s"""
import glob, os, re, struct

LINE = re.compile(r'/\* ([0-9A-F]+) ([0-9A-F]{8}) ([0-9A-F]{8}) \*/')
RANGES = ((0x200000, 0x2C0000), (0x400000, 0x44EDA0))      # main program and overlay A code (virtual addresses)

def in_code(v):
    return v % 4 == 0 and any(lo <= v < hi for lo, hi in RANGES)

def run():
    rom = open('baserom.us.v11.z64', 'rb').read()
    nw = len(rom) // 4
    ws = struct.unpack('>%dI' % nw, rom[:nw * 4])
    cands = set(); weak = set()
    for v in ws:
        if in_code(v): weak.add(v)                                     # code pointers in data (jump tables point into functions: need a prologue too)
    for i, w in enumerate(ws[:0x1C0000 // 4]):
        op = w >> 26
        if op == 3:                                                    # jal
            t = (w & 0x3FFFFFF) << 2
            if in_code(t): cands.add(t)
        elif op == 0x0F and (w & 0xFFFF) in (0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45):
            rt = (w >> 16) & 31
            for k in range(1, 5):
                if i + k >= nw: break
                x = ws[i + k]; xop = x >> 26
                if xop in (0x09, 0x0D) and ((x >> 21) & 31) == rt:     # addiu / ori
                    imm = x & 0xFFFF
                    if xop == 0x09 and imm & 0x8000: imm -= 0x10000
                    v = ((w & 0xFFFF) << 16) + imm
                    if in_code(v): cands.add(v)
                    break
    os.makedirs('port/build/asm_extra', exist_ok=True)
    total = 0
    for p in glob.glob('asm/*.s'):
        lines = open(p, encoding='utf-8').read().split('\n')
        labeled = set()
        for i, l in enumerate(lines):
            m = re.match(r'glabel func_([0-9A-F]{8})', l)
            if m: labeled.add(int(m.group(1), 16))
        out = []; st = 0; n = 0
        for l in lines:
            m = LINE.search(l)
            if m:
                a = int(m.group(2), 16); w = int(m.group(3), 16)
                prologue = (w >> 16) == 0x27BD and (w & 0x8000) and (w & 0xFFFF) < 0xFFF8
                if a not in labeled and (a in cands or (prologue and (st == 2 or a in weak))):
                    out.append('glabel func_%08X' % a); labeled.add(a); n += 1
                if w == 0x03E00008: st = 1
                elif st == 1: st = 2
                else: st = 0
            out.append(l)
        total += n
        open('port/build/asm_extra/' + os.path.basename(p), 'w', encoding='utf-8', newline='\n').write('\n'.join(out))
    print('inserted', total, 'extra labels')

if __name__ == '__main__':
    run()
