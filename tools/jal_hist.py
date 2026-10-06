import struct, collections, sys
rom = open('baserom.us.v11.z64','rb').read()
def scan(lo, hi):
    h = collections.Counter(); ex = {}
    for off in range(lo, hi, 4):
        w = struct.unpack_from('>I', rom, off)[0]
        if w >> 26 == 3:                       # jal
            t = (w & 0x3FFFFFF) << 2
            b = t >> 20
            h[b] += 1; ex.setdefault(b, []).append(t)
    return h, ex
for lo, hi in [(0x1000,0x101000),(0x160000,0x1C0000)]:
    h, ex = scan(lo, hi)
    print(f"ROM {lo:X}-{hi:X}  jal target buckets (low 28 bits >>20, as 1MB):")
    for b, c in sorted(h.items()):
        t = sorted(ex[b]); print(f"  0x{b<<20:08X}+  count={c:5d}  min=0x{t[0]:07X} max=0x{t[-1]:07X}")
