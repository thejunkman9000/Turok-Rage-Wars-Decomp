#!/usr/bin/env python3
"""Rob Northen Compression method 1 ('RNC\\x01') unpacker + chunk scanner.

usage: python tools/rnc.py scan [rom]            list every RNC chunk (rom offset, packed/unpacked size, crc ok)
"""
import struct, sys

def crc16(data):
    t = []
    for i in range(256):
        c = i
        for _ in range(8):
            c = (c >> 1) ^ 0xA001 if c & 1 else c >> 1
        t.append(c)
    crc = 0
    for b in data:
        crc = (crc >> 8) ^ t[(crc ^ b) & 0xFF]
    return crc

class Bits:
    """bit reader: LSB-first over little-endian 16-bit words; raw bytes are spliced in after the word holding the last bit read,
    and the unread bits of that word continue after them (rem/remc)"""
    def __init__(s, d, p):
        s.d, s.base, s.pos, s.rem, s.remc = d, p, 0, 0, 0
    def _stream(s, n):
        byte = s.base + (s.pos >> 3)
        v = 0
        for k in range(5):
            if byte + k < len(s.d): v |= s.d[byte + k] << (8 * k)
        return (v >> (s.pos & 7)) & ((1 << n) - 1)
    def peek(s, n):
        if s.remc >= n: return s.rem & ((1 << n) - 1)
        return s.rem | (s._stream(n - s.remc) << s.remc)
    def adv(s, n):
        if n <= s.remc: s.rem >>= n; s.remc -= n
        else: s.pos += n - s.remc; s.rem = 0; s.remc = 0
    def read(s, n):
        v = s.peek(n); s.adv(n); return v
    def rawpos(s): return s.base + 2 * ((s.pos + 15) >> 4)
    def splice(s, n):
        q = s.rawpos()
        if s.remc == 0 and s.pos & 15:
            w = s.d[q - 2] | (s.d[q - 1] << 8)
            s.rem, s.remc = w >> (s.pos & 15), 16 - (s.pos & 15)
        s.base, s.pos = q + n, 0
        return q

def rev(v, n):
    r = 0
    for _ in range(n):
        r = (r << 1) | (v & 1); v >>= 1
    return r

def read_table(b):
    n = b.read(5)
    lens = [b.read(4) for _ in range(n)]
    tab = []; code = 0; inc = 0x80000000
    for l in range(1, 17):
        for i, ll in enumerate(lens):
            if ll == l:
                tab.append((l, rev(code >> (32 - l), l), i)); code += inc
        inc >>= 1
    return tab

def huf(b, tab):
    for l, c, v in tab:
        if b.peek(l) == c:
            b.adv(l)
            if v >= 2:
                v = (1 << (v - 1)) | b.read(v - 1)
            return v
    raise ValueError('bad huffman code')

def unpack(d, off=0):
    assert d[off:off + 4] == b'RNC\x01'
    ulen, plen, ucrc, pcrc = struct.unpack('>IIHH', d[off + 4:off + 16])
    blocks = d[off + 17]
    src = off + 18
    out = bytearray()
    b = Bits(d, src); b.adv(2)
    for _ in range(blocks):
        raw = read_table(b); dist = read_table(b); ln = read_table(b)
        cnt = b.read(16)
        while cnt:
            cnt -= 1
            n = huf(b, raw)
            if n:
                q = b.splice(n); out += d[q:q + n]
            if cnt:
                pos = huf(b, dist) + 1
                n = huf(b, ln) + 2
                for _ in range(n):
                    out.append(out[-pos])
    return bytes(out[:ulen]), ulen, plen, ucrc, pcrc

if __name__ == '__main__':
    rom = open(sys.argv[2] if len(sys.argv) > 2 else 'baserom.us.v11.z64', 'rb').read()
    if sys.argv[1] == 'scan':
        i = 0; ok = bad = 0
        while True:
            i = rom.find(b'RNC\x01', i)
            if i < 0: break
            try:
                o, ul, pl, uc, pc = unpack(rom, i)
                good = len(o) == ul and crc16(o) == uc
            except Exception as e:
                good = False; ul = pl = 0
            ok += good; bad += not good
            print(f'{i:07X} packed={pl:7d} unpacked={ul:7d} {"OK" if good else "BAD"}')
            i += 4
        print('ok', ok, 'bad', bad, file=sys.stderr)
