#!/usr/bin/env python3
"""usage: xrange.py LO HI [ROM_LO ROM_HI] : every code location (lui + load/addiu pairs; default ROM range = overlay A 0x16E000..0x1BCDA0) that forms a 32-bit address in [LO,HI) - used to tell TU-private pool words from shared data"""
import struct, sys
rom = open('baserom.us.v11.z64','rb').read()
lo_t = int(sys.argv[1],16); hi_t = int(sys.argv[2],16)
def sx(v): return v-0x10000 if v & 0x8000 else v
LO, HI = (int(sys.argv[3],16), int(sys.argv[4],16)) if len(sys.argv) > 4 else (0x16E000, 0x1BCDA0)
w = struct.unpack('>%dI' % ((HI-LO)//4), rom[LO:HI])
res = []
for i, x in enumerate(w):
    if x >> 26 == 0x0F:
        rt = (x >> 16) & 31; hival = (x & 0xFFFF) << 16
        for j in range(i+1, min(i+40, len(w))):
            y = w[j]; op = y >> 26; rs = (y >> 21) & 31
            if op in (0x09, 0x23, 0x21, 0x25, 0x20, 0x24, 0x2B, 0x29, 0x28, 0x31, 0x39, 0x35, 0x3D) and rs == rt:
                a = (hival + sx(y & 0xFFFF)) & 0xFFFFFFFF
                if lo_t <= a < hi_t: res.append((LO + 4*j, a, op))
            if op == 0x0F and ((y >> 16) & 31) == rt: break
res.sort()
last = None
for r, a, op in res:
    va = 0x400000 + r - 0x16E000 if LO == 0x16E000 else 0x1FF400 + r
    print('code rom 0x%X (vram 0x%08X)  -> 0x%08X (rom 0x%X) op%02X' % (r, va, a, a - 0x80000000 + 0xC00, op))
