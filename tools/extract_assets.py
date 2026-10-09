#!/usr/bin/env python3
"""Dump the RNC-compressed assets of the ROM and decode the texture banks.

usage: python tools/extract_assets.py [rom] [outdir]      (defaults: baserom.us.v11.z64, assets/)
  assets/raw/<ROMOFF>.bin                 every RNC chunk, unpacked (CRC verified)
  assets/textures/<ROMOFF>/NN.png         texture banks (type-3 chunk whose section 0 is the 8-byte format header)
  assets/index.txt                        one line per chunk: offset size kind
Texture bank layout (type-3 container: word0=3, then 4 section offsets):
  sec0 (8 bytes): fmt, flags, log2(width), log2(height), 0xFF, 0, 0, 0
  sec1: count, count x offset (relative to sec1), pixel data    fmt 0 = CI8, 1 = CI4, 3 = I4 (no palette)
  sec2: count, count x offset (relative to sec2), RGBA5551 palettes (CI formats)
"""
import os, struct, sys
sys.path.insert(0, os.path.dirname(__file__))
import rnc
from PIL import Image

def rgba16(w):
    return (((w >> 11) & 31) * 255 // 31, ((w >> 6) & 31) * 255 // 31, ((w >> 1) & 31) * 255 // 31, 255 if w & 1 else 0)

def u32(b, o): return struct.unpack('>I', b[o:o + 4])[0]

def texture_bank(b):
    """list of PIL images, or None when the chunk is not a texture bank"""
    if len(b) < 0x30 or u32(b, 0) != 3: return None
    o = struct.unpack('>4I', b[4:20])
    if o[1] - o[0] != 8 or b[o[0] + 4] != 0xFF: return None
    fmt, _, wl, hl = b[o[0]:o[0] + 4]
    w, h = 1 << wl, 1 << hl
    n = u32(b, o[1])
    if not 1 <= n <= 1000 or fmt not in (0, 1, 3): return None
    toff = struct.unpack('>%dI' % n, b[o[1] + 4:o[1] + 4 + 4 * n])
    pal_n = {0: 256, 1: 16}.get(fmt, 0)
    poff = None
    if pal_n:
        if u32(b, o[2]) != n: return None
        poff = struct.unpack('>%dI' % n, b[o[2] + 4:o[2] + 4 + 4 * n])
    bpp = 8 if fmt == 0 else 4
    size = w * h * bpp // 8
    imgs = []
    for i in range(n):
        d = b[o[1] + toff[i]:o[1] + toff[i] + size]
        if len(d) < size: return None
        if bpp == 4:
            px = []
            for by in d: px += [by >> 4, by & 15]
        else:
            px = list(d)
        if pal_n:
            pb = o[2] + poff[i]
            raw = b[pb:pb + 2 * pal_n].ljust(2 * pal_n, b'\0')
            pal = [rgba16(x) for x in struct.unpack('>%dH' % pal_n, raw)]
            data = [pal[p] for p in px]
        else:                                               # I4 (assumed): grey ramp
            data = [(p * 17, p * 17, p * 17, 255) for p in px]
        im = Image.new('RGBA', (w, h)); im.putdata(data)
        imgs.append(im)
    return imgs

def main():
    rom = open(sys.argv[1] if len(sys.argv) > 1 else 'baserom.us.v11.z64', 'rb').read()
    out = sys.argv[2] if len(sys.argv) > 2 else 'assets'
    os.makedirs(f'{out}/raw', exist_ok=True)
    index = []; ntex = nbank = 0
    i = 0
    while True:
        i = rom.find(b'RNC\x01', i)
        if i < 0: break
        data, ul, pl, uc, _ = rnc.unpack(rom, i)
        assert len(data) == ul and rnc.crc16(data) == uc, hex(i)
        name = f'{i:07X}'
        open(f'{out}/raw/{name}.bin', 'wb').write(data)
        kind = 'data'
        imgs = texture_bank(data)
        if imgs:
            os.makedirs(f'{out}/textures/{name}', exist_ok=True)
            for k, im in enumerate(imgs): im.save(f'{out}/textures/{name}/{k:02d}.png')
            kind = f'textures x{len(imgs)} {imgs[0].width}x{imgs[0].height}'
            ntex += len(imgs); nbank += 1
        index.append(f'{name} {ul} {kind}')
        i += 4
    open(f'{out}/index.txt', 'w').write('\n'.join(index) + '\n')
    print(f'{len(index)} chunks, {nbank} texture banks, {ntex} textures -> {out}/')

if __name__ == '__main__':
    main()
