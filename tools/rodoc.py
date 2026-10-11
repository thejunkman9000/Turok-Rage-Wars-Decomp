#!/usr/bin/env python3
"""rodata doctor: compare the data an @SN object produces with the ROM bytes at the function's `ro=` piece.

The worker checker (chk) compares CODE only; float constants, doubles, strings and jump tables are never compared, so a matched function can carry
a literal that differs from the original (and the real build then differs at the ro= piece).  This tool compiles a source exactly like tools/cc.sh
does, extracts the rodata of the object (relocated words, i.e. jump-table entries, are masked) and prints every 4-byte word that differs from the
ROM, with the float interpretation of both words.  `--place` slides the object's rodata over the ROM around the expected spot and reports every
offset where it matches (a section must start at a multiple of its alignment, usually 8 when the object holds a double).

usage (in WSL, cwd = the Linux-side tree ~/trw):
  python3 tools/rodoc.py <src.c> <cc mode> <rom offset hex> [<size>]       e.g.  wip/x.c sn+nb 0xE1854 72
  python3 tools/rodoc.py --results <results.txt> <ws dir> <func>           take mode / ro= from a worker's results line
  options: --place [<lo hex> <hi hex>]   search window for the match (default: ro offset -64 .. +64)
Exit 0 when the object data equals the ROM bytes, 1 otherwise."""
import os, re, struct, subprocess, sys, tempfile

ROM = os.environ.get('ROM', 'baserom.us.v11.z64')

def run(*a):
    return subprocess.run(a, capture_output=True, text=True)

def rodata_of(obj):
    """-> (bytes of .rodata+.rdata, set of word offsets that carry a relocation, alignment)"""
    blob = b''; relocs = set(); align = 4
    h = run('mips-linux-gnu-objdump', '-h', obj).stdout
    for name in ('.rodata', '.rdata'):
        m = re.search(r'\s%s\s+([0-9a-f]+)\s+[0-9a-f]+\s+[0-9a-f]+\s+[0-9a-f]+\s+2\*\*(\d+)' % re.escape(name), h)
        if not m or int(m.group(1), 16) == 0: continue
        with tempfile.NamedTemporaryFile(suffix='.bin', delete=False) as t: path = t.name
        run('mips-linux-gnu-objcopy', '-O', 'binary', '-j', name, obj, path)
        data = open(path, 'rb').read(); os.remove(path)
        base = len(blob)
        r = run('mips-linux-gnu-objdump', '-r', '-j', name, obj).stdout
        for l in r.split('\n'):
            mm = re.match(r'\s*([0-9a-f]{8})\s+R_MIPS', l)
            if mm: relocs.add(base + int(mm.group(1), 16))
        blob += data; align = max(align, 1 << int(m.group(2)))
    return blob, relocs, align

def shortest_float(w):
    f = struct.unpack('>f', struct.pack('>I', w))[0]
    if f != f or f in (float('inf'), float('-inf')): return repr(f)
    for n in range(1, 12):
        s = '%.*g' % (n, f)
        if struct.pack('>f', float(s)) == struct.pack('>I', w): return s + ('' if re.search(r'[.eE]', s) else '.0') + 'f'
    return '%.9g' % f

def mode_from_flags(rest):
    if '@SN272' in rest: mode = 'sn272'
    else:
        mode = 'sn'
        if '-msplit-addresses' in rest: mode += '+sa'
        if '-mcpu=r4000' in rest: mode += '+r4k'
        if '@EPI' in rest: mode += '+epi'
    for tok, suf in (('@L', '+snl'), ('@K', '+snk'), ('@Z', '+snz'), ('-fno-builtin', '+nb'), ('-fno-thread-jumps', '+ntj'),
                     ('-fno-rerun-cse-after-loop', '+nrc'), ('-fno-expensive-optimizations', '+neo'), ('-fno-strength-reduce', '+nsr')):
        if tok in rest: mode += suf
    return mode

def from_results(res, ws, fn):
    best = None
    for l in open(res, errors='replace'):
        body = l.split('#')[0].split()
        if len(body) >= 4 and body[0] == fn and body[3] == 'EXACT': best = l
    if not best: sys.exit('no EXACT line for ' + fn)
    body = best.split('#')[0].split(); rest = body[4:]
    note = best.split('#', 1)[1] if '#' in best else ''
    mm = re.search(r'flags:\s*((?:[@-]\S+[ \t]*)+)', note)
    if mm: rest += [t.rstrip('.,;') for t in mm.group(1).split()]
    rest = [t.strip('[]') for t in rest]
    rest = [u for t in rest for u in ((t, t.split('=', 1)[1]) if t.startswith('flags=') else (t,))]
    ro = next((t for t in rest if t.startswith('ro=')), None)
    off = size = None
    if ro:
        a = ro[3:].split(':'); off = int(a[0], 16); size = int(a[1])
    return f'{ws}/wip/out/{fn}.c', mode_from_flags(rest), off, size

def compile_obj(src, mode, off=None, size=None):
    obj = tempfile.mktemp(suffix='.o')
    env = dict(os.environ)
    if off: env['CC_RO_OFF'] = str(off)                  # the piece address decides the alignment pads (tools/sn_abs.py)
    if size: env['CC_RO_SIZE'] = str(size)
    r = subprocess.run(['bash', 'tools/cc.sh', mode, src, obj], capture_output=True, text=True, env=env)
    if r.returncode != 0 or not os.path.exists(obj):
        print('  COMPILE FAILED', r.stderr[-400:]); return None
    return obj

def match_at(rom, blob, relocs, p):
    for i in range(0, len(blob), 4):
        if i in relocs: continue
        if rom[p + i:p + i + 4] != blob[i:i + 4].ljust(4, b'\0'): return False
    return True

def compare(src, mode, off, size, place=None):
    obj = compile_obj(src, mode, off if off else None, size if size else None)
    if not obj: return 2
    blob, relocs, align = rodata_of(obj)
    syms = run('mips-linux-gnu-readelf', '-sW', obj).stdout
    funcs = [(l.split()[7], int(l.split()[1], 16)) for l in syms.split('\n') if len(l.split()) >= 8 and l.split()[3] in ('FUNC', 'NOTYPE') and l.split()[4] == 'GLOBAL' and l.split()[6].isdigit()]
    hdr = run('mips-linux-gnu-objdump', '-h', obj).stdout
    mt = re.search(r'\s\.text\s+([0-9a-f]+)', hdr)
    print('  object text %d insns; functions: %s' % (int(mt.group(1), 16) // 4 if mt else 0, ' '.join('%s@+0x%X' % f for f in sorted(funcs, key=lambda f: f[1]))))
    os.remove(obj)
    print('  object rodata %d bytes, alignment %d, %d relocated words' % (len(blob), align, len(relocs)))
    rom = open(ROM, 'rb').read()
    if off is None and place is None:
        return 0 if not blob else 1
    if place is not None:
        lo, hi = place if place[0] is not None else (off - 64, off + 64)
        hits = [p for p in range(lo, hi + 1, 4) if match_at(rom, blob, relocs, p)]
        print('  placements in 0x%X..0x%X: %s' % (lo, hi, ' '.join('0x%X%s' % (p, '' if p % align == 0 else '(unaligned)') for p in hits) or 'none'))
        if hits and off is not None: print('  ro= piece starts at 0x%X: offset from the match %+d' % (off, off - hits[0]))
        return 0 if any(p % align == 0 for p in hits) else 1
    size = size if size is not None else len(blob)
    n = max(len(blob), size)
    print('  ro piece 0x%X size %d%s' % (off, size, '' if len(blob) == size else '  <-- SIZE DIFFERS (object %d)' % len(blob)))
    bad = 0
    for i in range(0, n, 4):
        if i in relocs: continue
        a = blob[i:i + 4]; b = rom[off + i:off + i + 4]
        if a == b: continue
        bad += 1
        wa = struct.unpack('>I', a.ljust(4, b'\0'))[0] if a else None
        wb = struct.unpack('>I', b)[0]
        print('  +0x%03X  ours %s  rom %08X   as float: ours %s  rom %s' % (i, ('%08X' % wa) if wa is not None else '--------', wb, shortest_float(wa) if wa is not None else '-', shortest_float(wb)))
    if relocs:      # jump-table words: the entries are absolute code addresses of the function; the build resolves them, so only report the constant the ROM implies
        vals = {struct.unpack('>I', rom[off + i:off + i + 4])[0] - struct.unpack('>I', blob[i:i + 4])[0] for i in relocs if off + i + 4 <= len(rom)}
        print('  relocated words: %d; ROM minus object value = %s (must be one constant = the text base)' % (len(relocs), ' '.join('0x%X' % v for v in sorted(vals)[:4])))
    if bad == 0 and len(blob) == size: print('  rodata IDENTICAL to the ROM')
    return 1 if bad or len(blob) != size else 0

def main():
    a = sys.argv[1:]
    if not a: print(__doc__); return 2
    place = None
    if '--place' in a:
        i = a.index('--place'); a.pop(i)
        if i < len(a) and re.fullmatch(r'0x[0-9A-Fa-f]+', a[i]) and i + 1 < len(a) and re.fullmatch(r'0x[0-9A-Fa-f]+', a[i + 1]) and not (a[0] == '--results' and i < 4):
            place = (int(a[i], 16), int(a[i + 1], 16)); a.pop(i); a.pop(i)
        else: place = (None, None)
    if a[0] == '--results':
        src, mode, off, size = from_results(a[1], a[2], a[3])
        print(a[3], src, mode, 'ro=' + (hex(off) + ':' + str(size) if off is not None else '-'))
        return compare(src, mode, off, size, place)
    src, mode, off = a[0], a[1], int(a[2], 16)
    return compare(src, mode, off, int(a[3]) if len(a) > 3 else None, place)

if __name__ == '__main__':
    sys.exit(main())
