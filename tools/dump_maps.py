#!/usr/bin/env python3
"""Raw dump of the ROM's resource directory: the 36 map records, the mesh library and the other root slots.

usage: python tools/dump_maps.py [rom] [outdir]        (defaults: baserom.us.v11.z64, assets/)

ROM layout of the resource area (found by tracing the game's own DMA reads; all offsets are ROM offsets):
  0x50F768  root table: u32 count (24), then 24 u32 offsets relative to 0x50F768.  Each slot is either
              - a lone RNC chunk (the offset points straight at 'RNC\\x01'),
              - a table: u32 count, count x u32 offsets relative to the table start (entries are RNC chunks or containers).
  A container is: u32 n, n x u32 part offsets relative to the container start; part i spans [off[i], off[i+1]) (the last part ends at the
  next entry).  A part that starts with 'RNC\\x01' is Rob Northen compressed (tools/rnc.py), anything else is raw data.
  slot 5 (0x734000): 37 containers of 13 parts = the maps (name string in part 8):
      0 raw 24 B (float 25.6 + colour bytes)     1 RNC settings block        2 RNC (8 B)           3 RNC nav/AI byte table
      4 RNC entry list (type,2,x,z floats)       5 raw sub-container (4 parts, first one RNC)   6 RNC 712 B (identical in every map)
      7 RNC 56..264 B                            8 raw name (16 B ASCII)     9 RNC object list: n, 0x29, then (x,y,z,.,id) records
      10 RNC link table                          11 RNC occupancy grid: u32 1, u32 N, N bytes 0/1 (N = 41*41)   12 raw 40 B
  slot 0 (0x50F7D0): 347 containers = the mesh library, slot 3 (0x5F90E8): 507 texture banks, slot 16: 69 sprite/UI images,
  slot 21: 36 records of 3382 B, the other slots are single chunks (object index 0x5F8720 etc.).
Output:
  assets/maps/NN_NAME/partKK.bin            (unpacked when the ROM part is RNC; partKK.rnc.txt marks which ones were)
  assets/maps/NN_NAME/manifest.txt          ROM offset, packed flag, size of every part
  assets/meshes/NNN/partK.bin               slot 0 containers
  assets/slots/slotNN/NNN.bin               every other slot, one file per table entry / lone chunk (unpacked)
"""
import os, re, struct, sys
sys.path.insert(0, os.path.dirname(__file__))
import rnc

ROOT = 0x50F768
def u32(b, o): return struct.unpack('>I', b[o:o + 4])[0]

def maybe_unpack(rom, a, end):
    if rom[a:a + 4] == b'RNC\x01':
        return rnc.unpack(rom, a)[0], True
    return rom[a:end], False

def container(rom, a, end, depth=0):
    """u32 n, then n+1 offsets (the last one is the end of the last part) relative to the container start"""
    n = u32(rom, a)
    offs = [a + u32(rom, a + 4 + 4 * i) for i in range(n + 1)]
    parts = []
    for i in range(n):
        p, e = offs[i], offs[i + 1]
        data, packed = maybe_unpack(rom, p, e)
        parts.append((p, data, packed, e - p))
    return parts

def nested(rom, base, raw, dst, tag, man):
    """raw parts can be sub-containers whose members are RNC chunks: dump every one found inside"""
    i = raw.find(b'RNC\x01')
    while i >= 0:
        try:
            data = rnc.unpack(rom, base + i)[0]
            open(f'{dst}/{tag}_rnc{i:X}.bin', 'wb').write(data)
            man.append(f'  {tag}_rnc{i:X} rom=0x{base + i:X} RNC size={len(data)}')
        except Exception as e:
            man.append(f'  {tag}: RNC tag at +0x{i:X} not unpackable ({e})')
        i = raw.find(b'RNC\x01', i + 4)

def table(rom, g):
    n = u32(rom, g)
    offs = [g + u32(rom, g + 4 + 4 * i) for i in range(n)]
    return offs

def main():
    rom = open(sys.argv[1] if len(sys.argv) > 1 else 'baserom.us.v11.z64', 'rb').read()
    out = sys.argv[2] if len(sys.argv) > 2 else 'assets'
    n = u32(rom, ROOT)
    slots = [ROOT + u32(rom, ROOT + 4 + 4 * i) for i in range(n)]
    slot_end = slots[1:] + [0x7A09B0 + 0x2000]
    # ---- maps (slot 5)
    ents = table(rom, slots[5])
    ends = ents[1:] + [slots[6]]
    for i, a in enumerate(ents):
        parts = container(rom, a, ends[i])
        name = parts[8][1].split(b'\0')[0].decode('latin1').strip()
        d = f'{out}/maps/{i:02d}_{re.sub(r"[^A-Za-z0-9]+", "_", name).strip("_")}'
        os.makedirs(d, exist_ok=True)
        man = [f'map {i}: {name}  container at ROM 0x{a:X}']
        for k, (p, data, packed, rawlen) in enumerate(parts):
            open(f'{d}/part{k:02d}.bin', 'wb').write(data)
            man.append(f'part{k:02d} rom=0x{p:X} {"RNC" if packed else "raw"} packed/raw_bytes={rawlen} size={len(data)}')
            if not packed:
                nested(rom, p, data, d, f'part{k:02d}', man)
        open(f'{d}/manifest.txt', 'w').write('\n'.join(man) + '\n')
    # ---- meshes (slot 0)
    ents = table(rom, slots[0])
    ends = ents[1:] + [slots[1]]
    for i, a in enumerate(ents):
        d = f'{out}/meshes/{i:03d}'
        os.makedirs(d, exist_ok=True)
        man = [f'mesh {i}: container at ROM 0x{a:X}']
        try:
            parts = container(rom, a, ends[i])
        except Exception as e:
            man.append(f'unparsable: {e}'); parts = []
        for k, (p, data, packed, rawlen) in enumerate(parts):
            open(f'{d}/part{k}.bin', 'wb').write(data)
            man.append(f'part{k} rom=0x{p:X} {"RNC" if packed else "raw"} raw_bytes={rawlen} size={len(data)}')
            if not packed:
                nested(rom, p, data, d, f'part{k}', man)
        open(f'{d}/manifest.txt', 'w').write('\n'.join(man) + '\n')
    # ---- the other slots
    for s in range(n):
        if s in (0, 5): continue
        a = slots[s]; end = slot_end[s]
        d = f'{out}/slots/slot{s:02d}'
        os.makedirs(d, exist_ok=True)
        if rom[a:a + 4] == b'RNC\x01':
            open(f'{d}/000.bin', 'wb').write(rnc.unpack(rom, a)[0])
            open(f'{d}/manifest.txt', 'w').write(f'slot {s}: lone RNC chunk at ROM 0x{a:X}\n')
            continue
        offs = table(rom, a)
        man = [f'slot {s}: table of {len(offs)} entries at ROM 0x{a:X}']
        for i, p in enumerate(offs):
            e = offs[i + 1] if i + 1 < len(offs) else end
            data, packed = maybe_unpack(rom, p, e)
            open(f'{d}/{i:03d}.bin', 'wb').write(data)
            man.append(f'{i:03d} rom=0x{p:X} {"RNC" if packed else "raw"} size={len(data)}')
        open(f'{d}/manifest.txt', 'w').write('\n'.join(man) + '\n')
    print('maps:', len(os.listdir(f'{out}/maps')), 'meshes:', len(os.listdir(f'{out}/meshes')), 'slots:', len(os.listdir(f'{out}/slots')))

if __name__ == '__main__':
    main()
