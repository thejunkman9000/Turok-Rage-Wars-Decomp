#!/usr/bin/env python3
"""Differential test driver: original machine code (interpreted) vs docs/hand_asm_c/rnc.c.

  py run_tests.py [--quick] [--seed N] [--rom PATH]

Steps
  1. builds test_rnc.c + ../rnc.c with `zig cc` (python -m ziglang cc) into a temp dir;
  2. `test_rnc crc <rom>`  - every method 1 blob of the ROM through the C decoder, CRC16 of the
     result must equal the CRC stored in the RNC header (independent of the interpreter);
  3. builds test cases, runs each through the ORIGINAL code in mips_interp.py (words taken from
     src/libultra/rnc*.s) and records the resulting memory; then lets test_rnc compare the C result.
Case sources: ROM method 1 blobs (sample), ROM blobs with bit flips / truncation, method 2 streams
made by an encoder written from the reverse-engineered format (valid), and mutated / random streams.
"""
import os, random, struct, subprocess, sys, tempfile, time

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..', '..'))
sys.path.insert(0, HERE)
from mips_interp import Mem, Cpu, load_s, Overflow, BadOpcode, StepLimit  # noqa

UNITS = ['rncUnpackMethod1', 'rncUnpackMethod1Body', 'rncReadHuffCode', 'rncInputBits',
         'rncRefillBitBuf', 'rncMakeHuffTable', 'rncUnpackMethod2', 'rncUnpackMethod2Body']
ENTRY1 = 0x002B2590
ENTRY2 = 0x002B2A10
STOP = 0x00F00000       # return address sentinel (outside code)
MARGIN, SLACK, PAD = 0x400, 0x100, 0x1000
IN_SLACK = 16           # must equal RNC_IN_SLACK in rnc.c
IN_BASE = 0x80200000
OUT_BASE = 0x80400000 + MARGIN
STACK = 0x807F0000
G_SIZE, G_TAIL = 0x8014D420, 0x8014D41E


def load_code():
    code = {}
    for u in UNITS:
        load_s(os.path.join(REPO, 'src', 'libultra', u + '.s'), code)
    return code


CODE = load_code()


def crc16(data):
    crc = 0
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = (crc >> 1) ^ 0xA001 if crc & 1 else crc >> 1
    return crc


class Skip(Exception):
    pass


def run_original(kind, data, in_len, out_len, max_steps=3_000_000):
    """Run the original unit.  Returns dict(region, v0, glob) or raises Skip(reason)."""
    mem = Mem()
    mem.put(IN_BASE, data)
    region_len = MARGIN + out_len + SLACK
    mem.put(OUT_BASE - MARGIN, b'\xA5' * region_len)
    in_stream = IN_BASE + (0x12 if kind == 1 else 0x12)
    packed_end = IN_BASE + 0x12 + in_len
    in_lim = packed_end + IN_SLACK
    out_lo, out_hi = OUT_BASE, OUT_BASE + out_len
    viol = []

    def on_read(a, n):
        a &= 0xFFFFFFFF
        if IN_BASE <= a < IN_BASE + 0x100000 and a + n > in_lim:
            viol.append('read past input')
        elif OUT_BASE - 0x100000 <= a < out_lo:
            viol.append('read before output')

    def on_write(a, n):
        a &= 0xFFFFFFFF
        if STACK - 0x4000 <= a < STACK + 4:
            return
        if a in (G_SIZE, G_TAIL):
            return
        if not (out_lo <= a and a + n <= out_hi):
            viol.append('write outside output at %08X' % a)

    mem.on_read = on_read
    mem.on_write = on_write
    cpu = Cpu(CODE, mem)
    cpu.r[29] = STACK
    cpu.r[31] = STOP
    if kind == 1:
        cpu.r[4] = IN_BASE + 0x12
        cpu.r[5] = OUT_BASE
        cpu.r[6] = in_len
        cpu.r[7] = out_len
        entry = ENTRY1
    else:
        cpu.r[4] = IN_BASE
        cpu.r[5] = OUT_BASE
        cpu.r[6] = in_len
        cpu.r[7] = out_len
        entry = ENTRY2
    try:
        cpu.run(entry, STOP, max_steps)
    except Overflow as e:
        raise Skip('trap ' + str(e))
    except BadOpcode as e:
        raise Skip('bad pc ' + str(e))
    except StepLimit:
        raise Skip('step limit')
    except IndexError:
        raise Skip('memory range')
    if viol:
        raise Skip(viol[0])
    if kind == 2:
        for reg in (4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19):
            pass
    return dict(region=mem.get(OUT_BASE - MARGIN, region_len), v0=cpu.r[2],
                glob=mem.r32(G_SIZE), steps=cpu.steps, regs=list(cpu.r))


# ---------------------------------------------------------------- RNC method 2 encoder (test only)
class Enc2:
    """Writes a method 2 stream exactly the way the decoder consumes it (control bytes are
    allocated at the moment their first bit is needed, literal bytes are interleaved)."""

    def __init__(self):
        self.out = bytearray()
        self.ctl = None   # index of the open control byte
        self.nbits = 0    # bits already stored in it
        self.skip = 2     # first byte: its 2 top bits are skipped by the decoder
        self.ctl = 0
        self.out.append(0)
        self.nbits = 2

    def bit(self, b):
        if self.nbits == 8:
            self.ctl = len(self.out)
            self.out.append(0)
            self.nbits = 0
        self.out[self.ctl] |= (b & 1) << (7 - self.nbits)
        self.nbits += 1

    def bits(self, *bs):
        for b in bs:
            self.bit(b)

    def byte(self, v):
        self.out.append(v & 0xFF)

    def literal(self, v):
        self.bit(0)
        self.byte(v)

    def end_literals(self):
        self.bit(1)         # flag that terminates a literal run

    def dist(self, d, with_hi):
        """d = distance - 1 (0..0xFFF)."""
        hi, lo = d >> 8, d & 0xFF
        if with_hi:
            if hi == 0:
                self.bit(0)
            else:
                self.bit(1)
                if hi == 1:
                    self.bits(1, 0)
                elif hi < 4:
                    self.bits(0, 0, hi & 1)
                elif hi < 8:
                    self.bits((hi >> 1) & 1, 1, hi & 1, 1)
                else:
                    self.bits((hi >> 2) & 1, 1, (hi >> 1) & 1, 0, hi & 1)
        self.byte(lo)

    def match(self, length, d):
        assert length >= 2
        if length == 2:
            assert d < 256
            self.bits(1, 0)
            self.dist(d, False)
            return
        if length == 3:
            self.bits(1, 1, 0)
        elif length in (4, 5):
            self.bits(0, length - 4, 0)
        elif length in (6, 7):
            self.bits(0, 0, 1, length - 6)
        elif length == 8:
            self.bits(0, 1, 1, 0)
        else:
            self.bits(1, 1, 1)
            self.byte(length - 8)
        self.dist(d, True)

    def raw_run(self, data):
        assert len(data) % 4 == 0 and 12 <= len(data) <= 60
        n = len(data) // 4 - 3
        self.bits(0, 1, 1, 1, (n >> 3) & 1, (n >> 2) & 1, (n >> 1) & 1, n & 1)
        self.out += data

    def finish(self, more=False):
        self.bits(1, 1, 1)
        self.byte(0)
        self.bit(0)


def make_method2_tokens(rng, target):
    """Generate token list, then encode.  Token grammar of the stream:
         LIT(v)*  1  MATCH...   (a '1' flag always separates the literal loop from the match)"""
    enc = Enc2()
    out = bytearray()
    first = True
    while len(out) < target:
        # literal run (0..5 literals), then the '1' flag
        for _ in range(rng.choice([0, 0, 1, 2, 3, 5])):
            v = rng.randrange(256) if rng.random() < 0.5 else rng.choice(b'ABCD \x00')
            enc.literal(v)
            out.append(v)
        enc.bit(1)
        r = rng.random()
        if len(out) < 4:
            r = 0.99        # need data first: use the raw run / continue marker
        if r < 0.80:
            maxd = min(len(out), 0x1000)
            d = rng.randrange(maxd) if rng.random() < 0.6 else rng.randrange(min(maxd, 16))
            if rng.random() < 0.15:
                d = 0
            L = rng.choice([2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 15, 40, 100, 263, rng.randint(2, 263)])
            if L == 2 and d >= 256:
                L = 3
            enc.match(L, d)
            for _ in range(L):
                out.append(out[-d - 1] if len(out) > d else 0)
        elif r < 0.95:
            # raw run = flag 0 (len code 0,1,1,1): note the leading '1' flag above is the literal-loop
            # terminator; the escape starts with the "0" of the long-length family.
            data = bytes(rng.randrange(256) for _ in range(4 * rng.randint(3, 15)))
            enc.bits(0, 1, 1, 1)
            n = len(data) // 4 - 3
            enc.bits((n >> 3) & 1, (n >> 2) & 1, (n >> 1) & 1, n & 1)
            enc.out += data
            out += data
        else:
            enc.bits(1, 1, 1)
            enc.byte(0)
            enc.bit(1)      # continue marker
    enc.bit(1)
    enc.bits(1, 1, 1)
    enc.byte(0)
    enc.bit(0)
    return bytes(enc.out), bytes(out)


def wrap_rnc(method, unpacked, stream):
    hdr = b'RNC' + bytes([method]) + struct.pack('>II', len(unpacked), len(stream))
    hdr += struct.pack('>HH', crc16(unpacked), crc16(stream)) + bytes([0, 1])
    return hdr + stream


# ---------------------------------------------------------------- cases
def case_record(kind, data, in_len, out_len, res):
    hdr = struct.pack('<7I', kind, len(data), in_len, out_len, len(res['region']), res['v0'], res['glob'])
    return hdr + data + res['region']


def main():
    argv = sys.argv[1:]
    quick = '--quick' in argv
    seed = int(argv[argv.index('--seed') + 1]) if '--seed' in argv else 1
    rom_path = argv[argv.index('--rom') + 1] if '--rom' in argv else os.path.join(REPO, 'baserom.us.v11.z64')
    rng = random.Random(seed)
    tmp = tempfile.mkdtemp(prefix='rnc_test_')
    exe = os.path.join(tmp, 'test_rnc.exe')
    cmd = [sys.executable, '-m', 'ziglang', 'cc', '-std=c99', '-O2', '-Wall', '-Wextra', '-o', exe,
           os.path.join(HERE, 'test_rnc.c'), os.path.join(HERE, '..', 'rnc.c')]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        print(r.stdout, r.stderr)
        return 2
    if r.stderr.strip():
        print(r.stderr)
    print('built', exe)

    rc_total = 0
    if os.path.exists(rom_path):
        out = subprocess.run([exe, 'crc', rom_path], capture_output=True, text=True)
        print('[ROM CRC] ' + out.stdout.strip().splitlines()[-1])
        rc_total |= out.returncode
        rom = open(rom_path, 'rb').read()
    else:
        rom = None

    cases = []   # (kind, data, in_len, out_len, label)
    expected = {}
    # -- ROM method 1 blobs
    if rom:
        blobs = []
        pos = 0
        while True:
            pos = rom.find(b'RNC\x01', pos)
            if pos < 0:
                break
            un, pk = struct.unpack('>II', rom[pos + 4:pos + 12])
            if 0 < un < 0x1000000 and 0 < pk < 0x400000 and pos + 18 + pk <= len(rom):
                blobs.append((pos, un, pk))
            pos += 1
        blobs.sort(key=lambda b: b[2])
        n_small = 12 if quick else 60
        n_rand = 4 if quick else 30
        pick = blobs[:n_small] + rng.sample(blobs[n_small:], min(n_rand, len(blobs) - n_small))
        pick = [b for b in pick if b[2] <= (3000 if quick else 12000)] or blobs[:n_small]
        for pos, un, pk in pick:
            data = rom[pos:pos + 18 + pk]
            cases.append((1, data, pk, un, 'rom1 @%X' % pos))
        # corrupted ROM blobs: bit flips and truncation
        for pos, un, pk in blobs[:(8 if quick else 40)]:
            data = bytearray(rom[pos:pos + 18 + pk])
            for _ in range(rng.randint(1, 3)):
                i = rng.randrange(18, len(data))
                data[i] ^= 1 << rng.randrange(8)
            cases.append((1, bytes(data), pk, un, 'rom1 flip @%X' % pos))
            cut = rng.randint(1, max(1, pk - 1))
            cases.append((1, bytes(data[:18 + cut]), cut, un, 'rom1 trunc @%X' % pos))
        # random garbage streams as method 1 (very likely invalid Huffman tables)
        for i in range(10 if quick else 60):
            n = rng.randint(30, 400)
            data = b'RNC\x01' + struct.pack('>II', 3000, n) + b'\0' * 6 + bytes(rng.randrange(256) for _ in range(n))
            cases.append((1, data, n, 3000, 'rand1 #%d' % i))
    # -- method 2: valid
    for i in range(12 if quick else 80):
        stream, unpacked = make_method2_tokens(rng, rng.choice([20, 100, 600, 3000, 8000]))
        data = wrap_rnc(2, unpacked, stream)
        cases.append((2, data, len(stream), len(unpacked), 'enc2 #%d' % i))
        expected[('enc2 #%d' % i)] = unpacked
        if i < (6 if quick else 40):
            d = bytearray(data)
            for _ in range(rng.randint(1, 4)):
                d[rng.randrange(18, len(d))] ^= 1 << rng.randrange(8)
            cases.append((2, bytes(d), len(stream), len(unpacked), 'enc2 flip #%d' % i))
            cut = rng.randint(1, max(1, len(stream) - 1))
            d2 = data[:18 + cut]
            cases.append((2, bytes(d2), cut, len(unpacked), 'enc2 trunc #%d' % i))
    for i in range(10 if quick else 80):
        n = rng.randint(10, 300)
        un = rng.choice([100, 1000, 4000])
        data = b'RNC\x02' + struct.pack('>II', un, n) + b'\0' * 6 + bytes(rng.randrange(256) for _ in range(n))
        cases.append((2, data, n, un, 'rand2 #%d' % i))

    if os.environ.get('RNC_DUMP'):
        for kind, data, in_len, out_len, label in cases:
            if label == os.environ['RNC_DUMP']:
                open(os.environ['RNC_DUMP_FILE'], 'wb').write(data)
                print('dumped', label, kind, in_len, out_len)
        return 0
    # -- run originals
    t0 = time.time()
    recs = []
    skipped = {}
    ok_labels = []
    sizes_check = 0
    enc_bad = 0
    usable_by = {}
    for kind, data, in_len, out_len, label in cases:
        try:
            res = run_original(kind, data, in_len, out_len, max_steps=min(3_000_000, 150_000 + 120 * out_len))
        except Skip as s:
            key = str(s).split(' at ')[0]
            skipped[key] = skipped.get(key, 0) + 1
            continue
        recs.append(case_record(kind, data, in_len, out_len, res))
        cat = ' '.join(t for t in label.split()[:2] if not t.startswith('@') and not t.startswith('#'))
        usable_by[cat] = usable_by.get(cat, 0) + 1
        ok_labels.append(label)
        if label in expected:
            sizes_check += 1
            got = res['region'][MARGIN:MARGIN + len(expected[label])]
            if got != expected[label] or res['glob'] != len(expected[label]):
                enc_bad += 1
                print('ENCODER/FORMAT MISMATCH in', label)
    print('original machine code run on %d cases in %.0fs; %d usable, skipped (original out of bounds / trapped / looping): %s'
          % (len(cases), time.time() - t0, len(recs), skipped or 'none'))
    print('usable cases by category:', usable_by)
    # sanity: the valid encoder streams must really produce the encoder's data (checks the encoder
    # and the format description, independent of C)
    path = os.path.join(tmp, 'cases.bin')
    with open(path, 'wb') as f:
        for rec in recs:
            f.write(rec)
    r = subprocess.run([exe, 'cases', path], capture_output=True, text=True)
    import re
    for line in r.stdout.strip().splitlines():
        m = re.match(r'case (\d+) ', line)
        print(line + ('   [%s]' % ok_labels[int(m.group(1)) - 1] if m else ''))
    rc_total |= r.returncode
    print('encoder self-check: %d valid method 2 streams decoded by the ORIGINAL code to exactly the encoder input, %d mismatches'
          % (sizes_check, enc_bad))
    rc_total |= 1 if enc_bad else 0
    print('RESULT:', 'ALL EQUIVALENT' if rc_total == 0 else 'MISMATCH')
    return rc_total


if __name__ == '__main__':
    sys.exit(main())
