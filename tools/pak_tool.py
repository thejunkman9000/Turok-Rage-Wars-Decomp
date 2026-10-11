#!/usr/bin/env python3
"""pak_tool.py - inspect, validate, create and edit N64 Controller Pak (memory card) images.

An independent implementation of the Controller Pak file system as libultra (osPfs*) uses it, written from the documented format
(n64brew "Controller Pak" pages, the libultra sources' structures) and checked against the game's own code.  It never uses game data:
every image it makes is synthetic.

Pak layout (32768 bytes = 128 pages of 256 bytes; one bank):
  page 0      ID sector: label area 0x00-0x1F; four copies of the 32-byte id block at 0x20, 0x60, 0x80, 0xC0
              id block: serial/random data 0x00-0x17, device id (u16) 0x18 (bit 0 = controller pak), banks 0x1A, version 0x1B,
              checksum 0x1C = sum of the first 14 big-endian words, inverted checksum 0x1E = 0xFFF2 - checksum
  page 1      index table (FAT): 128 big-endian u16 entries (entry n describes page n); entry 0 = [0, checksum]; checksum = byte sum of
              entries 5..127 (low 8 bits); entries 1-4 = 0 (reserved pages); 0x0003 = free page, 0x0001 = last page of a note,
              otherwise the number of the next page.  Page 2 is an exact backup copy.
  pages 3-4   note table: 16 entries of 32 bytes: game code (4 ASCII), publisher code (2 ASCII), start page (u16), status, reserved,
              data sum (u16), extension (4), name (16) - names use the N64 note character set (see NOTE_CHARS)
  pages 5-127 note data

Containers understood on input (and kept intact on output): raw 32 KiB (.mpk, .mem), DexDrive .n64 (0x1040-byte header "123-456-STD"),
4-in-1 .mpk (4 x 32 KiB, mupen64plus), N x 32 KiB, mupen64plus-next .srm (0x48800), raw + appended data (comment trailers).

usage:  pak_tool.py info FILE [--slice N] [--json]       validate and list notes (exit code 0 = ok, 1 = warnings, 2 = errors)
        pak_tool.py create FILE [--blank|--formatted|--fill HEX] [--seed N] [--container raw|dexdrive|4in1]
        pak_tool.py insert FILE --game NXXE --pub 01 --name "MY NOTE" [--ext ""] (--size BYTES [--fill HEX] | --data FILE) [--slice N]
        pak_tool.py extract FILE INDEX -o OUT [--slice N]        note data (whole pages) to a file
        pak_tool.py delete FILE INDEX [--slice N]
        pak_tool.py corrupt FILE KIND [--slice N] [--seed N]    KIND: id-primary id-all fat-primary fat-both fat-sum note-chain crosslink
                                                                    noteloop zero-notes garbage-notes random truncate short extend
        pak_tool.py diff A B [--slice N]                        structural difference of two images
        pak_tool.py same-notes A B [--game CODE]                exit 0 if all (or the given game's) notes are byte-identical in both images
        pak_tool.py fake FILE [--games N] [--seed N]            fill an image with synthetic notes of imaginary games
        pak_tool.py selftest
"""
import argparse, json, os, random, struct, sys, tempfile, time

PAK_SIZE = 0x8000
PAGE = 256
BLK = 32
ID_OFFSETS = (0x20, 0x60, 0x80, 0xC0)
FAT_PAGE = (1, 2)
NOTE_PAGES = (3, 4)
FIRST_DATA_PAGE = 5
DEX_MAGIC = b"123-456-STD\0"
DEX_HEADER = 0x1040
SRM_SIZE = 0x48800

# N64 note character set (the table the game itself uses: 0x0F = space, 0x10-0x19 digits, 0x1A-0x33 A-Z, punctuation 0x34-0x41)
NOTE_CHARS = {0x00: '', 0x0F: ' '}
NOTE_CHARS.update({0x10 + i: str(i) for i in range(10)})
NOTE_CHARS.update({0x1A + i: chr(65 + i) for i in range(26)})
NOTE_CHARS.update({0x34: '!', 0x35: '"', 0x36: '#', 0x37: "'", 0x38: '*', 0x39: '+', 0x3A: ',', 0x3B: '-', 0x3C: '.', 0x3D: '/', 0x3E: ':', 0x3F: '=', 0x40: '?', 0x41: '@'})
NOTE_CODES = {v: k for k, v in NOTE_CHARS.items() if v}


def crc5_addr(blk):
    """5-bit address CRC of an 11-bit block number (LFSR formulation used by libultra's __osContAddressCrc)."""
    crc = 0
    a = blk
    for _ in range(16):
        bit = (a >> 10) & 1
        tap = 0x15 if crc & 0x10 else 0
        a <<= 1
        crc = (((crc << 1) & 0xFF) | bit) ^ tap
    return crc & 0x1F


ADDR_CRC_BIT_VALUES = {15: 0x01, 14: 0x1A, 13: 0x0D, 12: 0x1C, 11: 0x0E, 10: 0x07, 9: 0x19, 8: 0x16, 7: 0x0B, 6: 0x1F, 5: 0x15}


def crc5_addr_table(addr16):
    """The same CRC from the per-bit XOR table documented on n64brew (address = block << 5)."""
    crc = 0
    for bit, val in ADDR_CRC_BIT_VALUES.items():
        if addr16 & (1 << bit):
            crc ^= val
    return crc


def crc8_data(data):
    """CRC-8 (polynomial 0x85, seed 0, MSB first) of 32 data bytes, as the controller computes it."""
    crc = 0
    for byte in data:
        for b in range(7, -1, -1):
            tap = 0x85 if crc & 0x80 else 0
            crc = (((crc << 1) & 0xFF) | ((byte >> b) & 1)) ^ tap
    for _ in range(8):
        tap = 0x85 if crc & 0x80 else 0
        crc = ((crc << 1) & 0xFF) ^ tap
    return crc


def decode_name(b):
    out = []
    for c in b:
        if c == 0:
            break
        out.append(NOTE_CHARS.get(c, '<%02X>' % c))
    return ''.join(out)


def encode_name(s, n):
    out = bytearray(n)
    if len(s) > n:
        raise ValueError('name too long (%d > %d): %r' % (len(s), n, s))
    for i, ch in enumerate(s.upper()):
        if ch not in NOTE_CODES:
            raise ValueError('character %r cannot be used in a note name' % ch)
        out[i] = NOTE_CODES[ch]
    return bytes(out)


def ascii_code(b):
    return ''.join(chr(c) if 32 <= c < 127 else '\\x%02X' % c for c in b)


# ---------------------------------------------------------------------------------------------------------------------------------
class Container:
    """A pak image inside a file: keeps everything outside the 32 KiB window (headers, other paks, trailers) byte-exact."""

    def __init__(self, raw, slice_=0):
        self.raw = bytearray(raw)
        self.slice = slice_
        self.fmt, self.off = self.detect(self.raw, slice_)
        if self.off + PAK_SIZE > len(self.raw):                         # short file: pad with zeros
            self.raw.extend(b'\0' * (self.off + PAK_SIZE - len(self.raw)))
            self.padded = True
        else:
            self.padded = False

    @staticmethod
    def detect(b, slice_):
        n = len(b)
        if n == PAK_SIZE:
            return 'raw 32 KiB', 0
        if n >= DEX_HEADER + PAK_SIZE and bytes(b[:12]) == DEX_MAGIC:
            return 'DexDrive .n64', DEX_HEADER
        if n == SRM_SIZE:
            return 'mupen64plus-next .srm', 0x800 + (slice_ & 3) * PAK_SIZE
        if n > PAK_SIZE and n % PAK_SIZE == 0:
            k = n // PAK_SIZE
            s = slice_ if slice_ < k else 0
            return '%d-in-1' % k, s * PAK_SIZE
        if n > PAK_SIZE:
            return 'raw + %d bytes appended' % (n - PAK_SIZE), 0
        return 'short (%d bytes)' % n, 0

    @property
    def pak(self):
        return self.raw[self.off:self.off + PAK_SIZE]

    def set_pak(self, data):
        assert len(data) == PAK_SIZE
        self.raw[self.off:self.off + PAK_SIZE] = data

    def bytes(self):
        return bytes(self.raw)


def load(path, slice_=0):
    with open(path, 'rb') as f:
        return Container(f.read(), slice_)


def save(path, cont):
    tmp = path + '.tmp'
    with open(tmp, 'wb') as f:
        f.write(cont.bytes())
    os.replace(tmp, path)


# ---------------------------------------------------------------------------------------------------------------------------------
def id_sums(block):
    s = sum(struct.unpack('>14H', bytes(block[:28]))) & 0xFFFF
    return s, (0xFFF2 - s) & 0xFFFF


def fat_sum(page):
    return sum(page[10:256]) & 0xFF


def make_formatted(seed=None, serial=None):
    """A factory-formatted, empty one-bank pak (the layout pak.c / Project64 create)."""
    rng = random.Random(seed)
    img = bytearray(PAK_SIZE)
    img[0] = 0x81
    for i in range(1, 32):
        img[i] = i
    ser = bytes(serial) if serial is not None else bytes(rng.getrandbits(8) for _ in range(24))
    idb = bytearray(ser) + bytearray([0, 1, 1, 0])
    s1, s2 = id_sums(idb)
    idb += struct.pack('>HH', s1, s2)
    for o in ID_OFFSETS:
        img[o:o + 32] = idb
    page = bytearray(PAGE)
    for i in range(5, 128):
        page[i * 2 + 1] = 3
    page[1] = fat_sum(page)
    img[0x100:0x200] = page
    img[0x200:0x300] = page
    return img


class Note:
    def __init__(self, index, raw):
        self.index = index
        self.raw = bytes(raw)
        self.game = raw[0:4]
        self.pub = raw[4:6]
        self.start = struct.unpack('>H', raw[6:8])[0]
        self.status = raw[8]
        self.reserved = raw[9]
        self.data_sum = struct.unpack('>H', raw[10:12])[0]
        self.ext = raw[12:16]
        self.name = raw[16:32]
        self.used = bool(struct.unpack('>I', raw[0:4])[0]) and bool(struct.unpack('>H', raw[4:6])[0])
        self.chain = []
        self.chain_status = ''

    def title(self):
        n = decode_name(self.name)
        e = decode_name(self.ext)
        return n + ('.' + e if e else '')


class Pak:
    def __init__(self, data):
        self.d = bytearray(data)
        assert len(self.d) == PAK_SIZE

    def page(self, n):
        return self.d[n * PAGE:(n + 1) * PAGE]

    def fat_entries(self, which):
        return list(struct.unpack('>128H', bytes(self.page(FAT_PAGE[which]))))

    def note_raw(self, i):
        return bytes(self.d[0x300 + i * 32:0x300 + (i + 1) * 32])

    def notes(self):
        return [Note(i, self.note_raw(i)) for i in range(16)]

    def id_info(self):
        res = []
        for o in ID_OFFSETS:
            b = bytes(self.d[o:o + 32])
            s1, s2 = id_sums(b)
            ck, ick = struct.unpack('>HH', b[28:32])
            dev, banks, ver = struct.unpack('>HBB', b[24:28])
            res.append(dict(offset=o, ok=(ck == s1 and ick == s2), cksum=ck, icksum=ick, want=(s1, s2), deviceid=dev, banks=banks, version=ver,
                            serial=b[:24].hex(), raw=b))
        return res

    def follow(self, start, fat):
        """follow a note's page chain: returns (pages, status) status '' = ok"""
        bank, page = start >> 8, start & 0xFF
        pages = []
        seen = set()
        if bank != 0:
            return pages, 'start page in bank %d (multi-bank paks are not handled)' % bank
        if page < FIRST_DATA_PAGE or page > 127:
            return pages, 'start page %d out of range' % page
        while True:
            if page in seen:
                return pages, 'chain loops at page %d' % page
            seen.add(page)
            pages.append(page)
            e = fat[page]
            if e == 1:
                return pages, ''
            if e == 3:
                return pages, 'page %d is marked free' % page
            if (e >> 8) != 0 or e < FIRST_DATA_PAGE or e > 127:
                return pages, 'page %d has bad link 0x%04X' % (page, e)
            page = e
            if len(pages) > 128:
                return pages, 'chain too long'


def analyse(pak):
    """returns dict(problems=[(level, text)], ids, fat, notes, free, used, orphans...) - level: 'error' | 'warn' | 'info'"""
    P = []
    ids = pak.id_info()
    nvalid = sum(1 for i in ids if i['ok'])
    if nvalid == 0:
        P.append(('error', 'no valid id block (libultra: PFS_ERR_ID_FATAL, the pak needs to be re-formatted/repaired)'))
    elif nvalid < 4:
        P.append(('warn', '%d of 4 id blocks valid (libultra repairs the others on the next osPfsInitPak)' % nvalid))
    good = [i for i in ids if i['ok']]
    if good:
        g = good[0]
        if not (g['deviceid'] & 1):
            P.append(('warn', 'device id 0x%04X has bit 0 clear (libultra rewrites the id)' % g['deviceid']))
        if g['banks'] != 1:
            P.append(('warn', 'id block says %d banks; only a 1-bank pak is analysed' % g['banks']))
        if len(set(i['raw'] for i in good)) > 1:
            P.append(('warn', 'valid id block copies differ'))
    f = [pak.fat_entries(0), pak.fat_entries(1)]
    fsum_ok = [fat_sum(pak.page(FAT_PAGE[k])) == pak.page(FAT_PAGE[k])[1] for k in (0, 1)]
    for k in (0, 1):
        pg = pak.page(FAT_PAGE[k])
        if not fsum_ok[k]:                                       # libultra restores a bad table from the other copy (__osPfsRWInode)
            P.append(('warn' if any(fsum_ok) else 'error', 'index table %d: checksum 0x%02X, expected 0x%02X%s' % (
                k + 1, pg[1], fat_sum(pg), ' (the other copy is good: libultra repairs it)' if any(fsum_ok) else '')))
        if pg[0] != 0:
            P.append(('info', 'index table %d: byte 0 = 0x%02X (normally 0)' % (k + 1, pg[0])))
        if any(f[k][i] != 0 for i in range(1, FIRST_DATA_PAGE)):
            P.append(('warn', 'index table %d: reserved entries 1-4 are not zero' % (k + 1)))
    if pak.page(FAT_PAGE[0]) != pak.page(FAT_PAGE[1]):
        P.append(('warn' if (fsum_ok[0] or fsum_ok[1]) else 'error', 'index table 1 and its backup (page 2) differ%s' % ('' if all(fsum_ok) else ' (and a checksum is bad)')))
    fat = f[0] if fsum_ok[0] or not fsum_ok[1] else f[1]
    notes = pak.notes()
    refs = {}
    for n in notes:
        if n.used:
            n.chain, n.chain_status = pak.follow(n.start, fat)
            if n.chain_status:
                P.append(('error', 'note %d (%s): %s' % (n.index, n.title(), n.chain_status)))
            for p in n.chain:
                refs.setdefault(p, []).append(n.index)
            if not (n.status & 2):
                P.append(('info', 'note %d: status byte 0x%02X (SDK-written notes usually have bit 0x02 set; libultra does not care)' % (n.index, n.status)))
        else:
            if n.raw != b'\0' * 32:
                P.append(('warn', 'note slot %d is unused but not zeroed (%s)' % (n.index, n.raw.hex())))
    for p, who in sorted(refs.items()):
        if len(who) > 1:
            P.append(('error', 'page %d is shared by notes %s (cross-linked)' % (p, who)))
    free = [p for p in range(FIRST_DATA_PAGE, 128) if fat[p] == 3]
    used = [p for p in range(FIRST_DATA_PAGE, 128) if fat[p] != 3]
    orphans = [p for p in used if p not in refs]
    for p in orphans:
        e = fat[p]
        if e == 0 or e == 1 or (e >= FIRST_DATA_PAGE and e <= 127):
            pass
    if orphans:
        P.append(('warn', '%d allocated page(s) belong to no note: %s' % (len(orphans), orphans[:12])))
    bad = [p for p in range(FIRST_DATA_PAGE, 128) if fat[p] not in (1, 3) and not (FIRST_DATA_PAGE <= fat[p] <= 127)]
    if bad:
        P.append(('error', 'index entries with invalid values: %s' % ['%d:0x%04X' % (p, fat[p]) for p in bad[:8]]))
    return dict(problems=P, ids=ids, fat=fat, notes=notes, free=free, used=used, orphans=orphans, refs=refs)


def verdict(an):
    lv = [l for l, _ in an['problems']]
    return 2 if 'error' in lv else (1 if 'warn' in lv else 0)


def print_info(cont, path, as_json=False):
    pak = Pak(cont.pak)
    an = analyse(pak)
    if as_json:
        out = dict(file=path, container=cont.fmt, offset=cont.off, verdict=verdict(an), problems=an['problems'], free_pages=len(an['free']),
                   id_blocks=[{k: (v.hex() if isinstance(v, bytes) else v) for k, v in i.items()} for i in an['ids']],
                   notes=[dict(index=n.index, game=ascii_code(n.game), publisher=ascii_code(n.pub), start=n.start, status=n.status, name=decode_name(n.name),
                               ext=decode_name(n.ext), pages=len(n.chain), size=len(n.chain) * PAGE, chain=n.chain, chain_status=n.chain_status)
                          for n in an['notes'] if n.used])
        print(json.dumps(out, indent=1))
        return verdict(an)
    print('%s: %s%s' % (path, cont.fmt, ' (padded with zeros)' if cont.padded else ''))
    for i in an['ids']:
        print('  id block @0x%02X: %s  device 0x%04X banks %d version %d  checksum %04X/%04X%s  serial %s' % (
            i['offset'], 'ok ' if i['ok'] else 'BAD', i['deviceid'], i['banks'], i['version'], i['cksum'], i['icksum'],
            '' if i['ok'] else ' (expected %04X/%04X)' % i['want'], i['serial'][:16] + '..'))
    print('  free pages %d of 123 (%d bytes), notes in use %d of 16' % (len(an['free']), len(an['free']) * PAGE, sum(1 for n in an['notes'] if n.used)))
    for n in an['notes']:
        if n.used:
            print('  note %2d: game %-4s pub %-2s start %3d pages %3d (%5d bytes) status %02X  %s%s' % (
                n.index, ascii_code(n.game), ascii_code(n.pub), n.start & 0xFF, len(n.chain), len(n.chain) * PAGE, n.status, n.title(),
                '   [%s]' % n.chain_status if n.chain_status else ''))
    for lvl, text in an['problems']:
        print('  %-5s %s' % (lvl.upper(), text))
    v = verdict(an)
    print('  verdict: %s' % ('OK' if v == 0 else ('OK with warnings' if v == 1 else 'DAMAGED')))
    return v


# ---------------------------------------------------------------------------------------------------------------------------------
def write_fat(pak, fat):
    page = bytearray(PAGE)
    for i, e in enumerate(fat):
        if i == 0:
            continue
        struct.pack_into('>H', page, i * 2, e)
    page[1] = fat_sum(page)
    pak.d[0x100:0x200] = page
    pak.d[0x200:0x300] = page


def insert_note(pak, game, pub, name, ext, data, status=0x02):
    an = analyse(pak)
    if any(l == 'error' for l, _ in an['problems']):
        raise SystemExit('refusing to edit a damaged pak (run info)')
    fat = list(an['fat'])
    npages = max(1, (len(data) + PAGE - 1) // PAGE)
    free = [p for p in range(FIRST_DATA_PAGE, 128) if fat[p] == 3]
    if len(free) < npages:
        raise SystemExit('not enough free pages (%d needed, %d free)' % (npages, len(free)))
    slot = next((n.index for n in an['notes'] if not n.used), None)
    if slot is None:
        raise SystemExit('note table is full')
    for n in an['notes']:
        if n.used and n.game == game and n.pub == pub and n.name == encode_name(name, 16) and n.ext == encode_name(ext, 4):
            raise SystemExit('a note with this game/publisher/name/extension exists (slot %d)' % n.index)
    pages = free[:npages]
    for a, b in zip(pages, pages[1:]):
        fat[a] = b
    fat[pages[-1]] = 1
    padded = bytes(data) + b'\0' * (npages * PAGE - len(data))
    for k, p in enumerate(pages):
        pak.d[p * PAGE:(p + 1) * PAGE] = padded[k * PAGE:(k + 1) * PAGE]
    ent = bytearray(32)
    ent[0:4] = game
    ent[4:6] = pub
    struct.pack_into('>H', ent, 6, pages[0])
    ent[8] = status
    ent[12:16] = encode_name(ext, 4)
    ent[16:32] = encode_name(name, 16)
    pak.d[0x300 + slot * 32:0x300 + slot * 32 + 32] = ent
    write_fat(pak, fat)
    return slot, pages


def note_data(pak, an, idx):
    n = an['notes'][idx]
    if not n.used or n.chain_status:
        raise SystemExit('note %d is not a valid note' % idx)
    return b''.join(bytes(pak.page(p)) for p in n.chain)


def delete_note(pak, idx):
    an = analyse(pak)
    n = an['notes'][idx]
    if not n.used:
        raise SystemExit('note %d is empty' % idx)
    fat = list(an['fat'])
    for p in n.chain:
        fat[p] = 3
    pak.d[0x300 + idx * 32:0x300 + idx * 32 + 32] = b'\0' * 32
    write_fat(pak, fat)


def fake_games(pak, ngames, rng):
    names = ['SPEED RACER', 'CASTLE QUEST', 'MOON PATROL', 'KART DASH', 'PUZZLE PAK', 'SKY ACE', 'HOOP STARS', 'DUNGEON DIVE']
    made = []
    for g in range(ngames):
        code = ('N%s%s%s' % (chr(65 + rng.randrange(26)), chr(65 + rng.randrange(26)), 'E')).encode()
        pub = ('%02d' % rng.randrange(1, 99)).encode()
        size = rng.choice([256, 512, 768, 1024, 2560])
        data = bytes(rng.getrandbits(8) for _ in range(size))
        nm = names[g % len(names)]
        try:
            slot, pages = insert_note(pak, code, pub, nm, rng.choice(['', 'A', 'DAT']), data)
            made.append((slot, code.decode(), nm, len(pages)))
        except SystemExit:
            break
    return made


def corrupt(pak, kind, rng):
    d = pak.d
    if kind == 'id-primary':
        d[0x20 + 30] ^= 0x55
    elif kind == 'id-all':
        for o in ID_OFFSETS:
            d[o + 28] ^= 0xFF
    elif kind == 'fat-primary':
        d[0x100 + 40] ^= 0x04
    elif kind == 'fat-both':
        d[0x100 + 40] ^= 0x04
        d[0x200 + 60] ^= 0x08
    elif kind == 'fat-sum':
        d[0x101] ^= 0x01
    elif kind == 'note-chain':
        an = analyse(pak)
        n = next((n for n in an['notes'] if n.used), None)
        if not n:
            raise SystemExit('no note to damage')
        fat = list(an['fat'])
        fat[n.chain[-1]] = 3                                   # the last page of the chain looks free: chain ends in a free page
        write_fat(pak, fat)
    elif kind == 'crosslink':
        an = analyse(pak)
        used = [n for n in an['notes'] if n.used]
        if len(used) < 2:
            raise SystemExit('need two notes')
        struct.pack_into('>H', d, 0x300 + used[1].index * 32 + 6, used[0].start)
    elif kind == 'noteloop':
        an = analyse(pak)
        n = next((n for n in an['notes'] if n.used), None)
        if not n:
            raise SystemExit('no note')
        fat = list(an['fat'])
        fat[n.chain[-1]] = n.chain[0]
        write_fat(pak, fat)
    elif kind == 'zero-notes':
        d[0x300:0x500] = b'\0' * 512
    elif kind == 'garbage-notes':
        for i in range(0x300, 0x500):
            d[i] = rng.getrandbits(8)
    elif kind == 'random':
        for _ in range(64):
            d[rng.randrange(PAK_SIZE)] = rng.getrandbits(8)
    elif kind == 'zero-all':
        d[:] = b'\0' * PAK_SIZE
    else:
        raise SystemExit('unknown corruption %r' % kind)


# ---------------------------------------------------------------------------------------------------------------------------------
def cmd_info(a):
    c = load(a.file, a.slice)
    return print_info(c, a.file, a.json)


def cmd_create(a):
    rng_seed = a.seed
    if a.blank:
        pak = bytearray(PAK_SIZE)
    elif a.fill is not None:
        pak = bytearray([int(a.fill, 16)]) * PAK_SIZE
    else:
        pak = make_formatted(rng_seed)
    data = bytes(pak)
    if a.container == 'dexdrive':
        data = DEX_MAGIC + b'\0' * (DEX_HEADER - len(DEX_MAGIC)) + data
    elif a.container == '4in1':
        others = [bytes(make_formatted((rng_seed or 0) + k)) for k in (1, 2, 3)]
        data = data + b''.join(others)
    with open(a.file, 'wb') as f:
        f.write(data)
    print('created %s (%d bytes, %s)' % (a.file, len(data), 'blank' if a.blank else ('fill %s' % a.fill if a.fill else 'formatted')))
    return 0


def cmd_insert(a):
    c = load(a.file, a.slice)
    pak = Pak(c.pak)
    if a.data:
        data = open(a.data, 'rb').read()
    else:
        fill = int(a.fill, 16) if a.fill else 0
        data = bytes([fill]) * (a.size or 256)
    game = a.game.encode('ascii')
    pub = a.pub.encode('ascii')
    if len(game) != 4 or len(pub) != 2:
        raise SystemExit('game code is 4 characters, publisher code 2')
    slot, pages = insert_note(pak, game, pub, a.name, a.ext, data)
    c.set_pak(pak.d)
    save(a.file, c)
    print('inserted note %d (%d pages: %s)' % (slot, len(pages), pages[:8]))
    return 0


def cmd_extract(a):
    c = load(a.file, a.slice)
    pak = Pak(c.pak)
    d = note_data(pak, analyse(pak), a.index)
    with open(a.out, 'wb') as f:
        f.write(d)
    print('wrote %d bytes' % len(d))
    return 0


def cmd_delete(a):
    c = load(a.file, a.slice)
    pak = Pak(c.pak)
    delete_note(pak, a.index)
    c.set_pak(pak.d)
    save(a.file, c)
    print('deleted note %d' % a.index)
    return 0


def cmd_corrupt(a):
    rng = random.Random(a.seed)
    if a.kind in ('truncate', 'short', 'extend'):
        raw = open(a.file, 'rb').read()
        if a.kind == 'truncate':
            raw = raw[:len(raw) // 2]
        elif a.kind == 'short':
            raw = raw[:100]
        else:
            raw = raw + bytes(rng.getrandbits(8) for _ in range(1234))
        open(a.file, 'wb').write(raw)
        print('%s: %d bytes' % (a.kind, len(raw)))
        return 0
    c = load(a.file, a.slice)
    pak = Pak(c.pak)
    corrupt(pak, a.kind, rng)
    c.set_pak(pak.d)
    save(a.file, c)
    print('applied %s' % a.kind)
    return 0


def cmd_diff(a):
    A, B = Pak(load(a.a, a.slice).pak), Pak(load(a.b, a.slice).pak)
    if A.d == B.d:
        print('identical')
        return 0
    anA, anB = analyse(A), analyse(B)
    for k in range(4):
        if A.d[ID_OFFSETS[k]:ID_OFFSETS[k] + 32] != B.d[ID_OFFSETS[k]:ID_OFFSETS[k] + 32]:
            print('id block copy %d differs' % (k + 1))
    if A.d[0:0x20] != B.d[0:0x20]:
        print('label area differs')
    if A.d[0x100:0x200] != B.d[0x100:0x200]:
        print('index table 1 differs')
    if A.d[0x200:0x300] != B.d[0x200:0x300]:
        print('index table 2 (backup) differs')
    for i in range(16):
        na, nb = anA['notes'][i], anB['notes'][i]
        if na.raw != nb.raw:
            print('note slot %d: %s -> %s' % (i, na.title() if na.used else '(empty)', nb.title() if nb.used else '(empty)'))
    changed = [p for p in range(FIRST_DATA_PAGE, 128) if A.page(p) != B.page(p)]
    owner = {}
    for an in (anA, anB):
        for p, who in an['refs'].items():
            owner.setdefault(p, set()).update(who)
    for p in changed:
        print('data page %d changed (notes %s)' % (p, sorted(owner.get(p, []))))
    return 1


def note_signature(pak, an, n):
    return (n.raw, tuple(bytes(pak.page(p)) for p in n.chain))


def cmd_same_notes(a):
    A, B = Pak(load(a.a).pak), Pak(load(a.b).pak)
    anA, anB = analyse(A), analyse(B)
    want = a.game.encode() if a.game else None
    bad = 0
    for na in anA['notes']:
        if not na.used or (want and na.game != want):
            continue
        sig = note_signature(A, anA, na)
        match = [nb for nb in anB['notes'] if nb.used and nb.game == na.game and nb.pub == na.pub and nb.name == na.name and nb.ext == na.ext]
        if not match:
            print('missing in B: %s %s' % (ascii_code(na.game), na.title()))
            bad += 1
            continue
        nb = match[0]
        if A.page(0) is None:
            pass
        # the start page may legitimately move when the other note table entries change; compare name, codes, size and data
        da = b''.join(bytes(A.page(p)) for p in na.chain)
        db = b''.join(bytes(B.page(p)) for p in nb.chain)
        meta_a = na.raw[:6] + na.raw[8:]
        meta_b = nb.raw[:6] + nb.raw[8:]
        if da != db or meta_a != meta_b:
            print('CHANGED: %s %s' % (ascii_code(na.game), na.title()))
            bad += 1
        elif na.start != nb.start:
            print('moved (same data): %s %s start %d -> %d' % (ascii_code(na.game), na.title(), na.start, nb.start))
    if not bad:
        print('all compared notes are identical')
    return 1 if bad else 0


def cmd_fake(a):
    c = load(a.file)
    pak = Pak(c.pak)
    made = fake_games(pak, a.games, random.Random(a.seed))
    c.set_pak(pak.d)
    save(a.file, c)
    for m in made:
        print('note %d: %s %s (%d pages)' % m)
    return 0


def cmd_selftest(a):
    ok = True

    def check(cond, msg):
        nonlocal ok
        print('%-4s %s' % ('ok' if cond else 'FAIL', msg))
        ok = ok and cond
    # CRCs: both formulations of the address CRC agree for all blocks; data CRC vectors
    check(all(crc5_addr(b) == crc5_addr_table(b << 5) for b in range(0x800)), 'address CRC: LFSR and the n64brew bit table agree for all 2048 blocks')
    check(crc8_data(bytes(32)) == 0, 'data CRC of 32 zero bytes is 0')
    check(crc8_data(bytes([1]) * 32) != crc8_data(bytes([0]) * 32), 'data CRC separates 01.. from 00..')
    p = Pak(make_formatted(1))
    an = analyse(p)
    check(verdict(an) == 0 and len(an['free']) == 123, 'formatted image validates (123 free pages)')
    check(p.d[0x101] == 0x71 and p.d[0x201] == 0x71, 'index checksum of an empty pak is 0x71')
    slot, pages = insert_note(p, b'NABE', b'01', 'TEST NOTE', 'X', bytes(range(256)) * 3)
    an = analyse(p)
    check(verdict(an) == 0 and len(an['notes'][slot].chain) == 3 and len(an['free']) == 120, 'insert: 3 pages, valid')
    check(note_data(p, an, slot)[:5] == bytes(range(5)), 'extract returns the data')
    q = Pak(p.d)
    insert_note(q, b'NCDE', b'02', 'OTHER', '', b'abc')
    delete_note(q, slot)
    an2 = analyse(q)
    check(verdict(an2) == 0 and len(an2['free']) == 122, 'delete frees the pages')
    for kind, expect in (('id-primary', 1), ('id-all', 2), ('fat-primary', 1), ('fat-both', 2), ('fat-sum', 1), ('note-chain', 2), ('crosslink', 2), ('noteloop', 2)):
        z = Pak(p.d)
        insert_note(z, b'NXYE', b'03', 'SECOND', '', b'z' * 300)
        corrupt(z, kind, random.Random(3))
        v = verdict(analyse(z))
        check(v >= expect or (kind == 'fat-primary' and v >= 1), 'corruption %-11s detected (verdict %d)' % (kind, v))
    d = Container(b'123-456-STD\0' + bytes(DEX_HEADER - 12) + bytes(make_formatted(2)))
    check(d.fmt.startswith('DexDrive') and d.off == DEX_HEADER and verdict(analyse(Pak(d.pak))) == 0, 'DexDrive container detected')
    m = Container(bytes(make_formatted(3)) * 4, 2)
    check(m.fmt == '4-in-1' and m.off == 2 * PAK_SIZE, '4-in-1 container, slice 3')
    t = Container(bytes(make_formatted(4)) + b'MPKMeta trailer', 0)
    check(t.off == 0 and 'appended' in t.fmt, 'trailing data tolerated')
    s = Container(b'\0' * 100)
    check(s.padded and len(s.raw) == PAK_SIZE, 'short file padded')
    return 0 if ok else 1


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest='cmd', required=True)

    def add(name, fn, *args):
        s = sp.add_parser(name)
        s.set_defaults(fn=fn)
        for names, kw in args:
            s.add_argument(*names, **kw)
        return s
    SL = (('--slice',), dict(type=int, default=0, help='0-based slice of a multi-pak container'))
    add('info', cmd_info, (('file',), {}), SL, (('--json',), dict(action='store_true')))
    add('create', cmd_create, (('file',), {}), (('--blank',), dict(action='store_true')), (('--formatted',), dict(action='store_true')),
        (('--fill',), dict(default=None)), (('--seed',), dict(type=int, default=None)), (('--container',), dict(default='raw', choices=['raw', 'dexdrive', '4in1'])))
    add('insert', cmd_insert, (('file',), {}), SL, (('--game',), dict(required=True)), (('--pub',), dict(required=True)), (('--name',), dict(required=True)),
        (('--ext',), dict(default='')), (('--size',), dict(type=int, default=None)), (('--fill',), dict(default=None)), (('--data',), dict(default=None)))
    add('extract', cmd_extract, (('file',), {}), (('index',), dict(type=int)), (('-o', '--out'), dict(required=True)), SL)
    add('delete', cmd_delete, (('file',), {}), (('index',), dict(type=int)), SL)
    add('corrupt', cmd_corrupt, (('file',), {}), (('kind',), {}), SL, (('--seed',), dict(type=int, default=1)))
    add('diff', cmd_diff, (('a',), {}), (('b',), {}), SL)
    add('same-notes', cmd_same_notes, (('a',), {}), (('b',), {}), (('--game',), dict(default=None)))
    add('fake', cmd_fake, (('file',), {}), (('--games',), dict(type=int, default=3)), (('--seed',), dict(type=int, default=1)))
    add('selftest', cmd_selftest)
    a = ap.parse_args(argv)
    return a.fn(a)


if __name__ == '__main__':
    sys.exit(main())
