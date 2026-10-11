#!/usr/bin/env python3
"""Generate the version-specific inputs of a build of another release inside a workspace copy of the tree (tools/mkws.py <name>).

usage: python tools/mkver.py <us|eu|de> --out D:/Projects/ws/<workspace> [--all]
Needs, in the main tree: wip/funcmap_<ver>.txt (tools/ver_funcmap.py), wip/ver/<ver>/sweep.txt + syms.ld (+ syms_inferred.ld) (tools/ver_sweep.py).
Writes into the workspace (and never touches the main tree):
  funcs.txt / funcs_a.txt   the units whose unchanged 1.1 C reproduces the release (sweep verdict EXACT), at the release's ROM offsets, `ro=` pieces found in its ROM
  symbol_addrs.txt          our names (func_XXXXXXXX of the 1.1 address, libultra names) at the release's addresses: splat names its asm with them, so C and asm link by NAME
  c_syms.ld / their_alias.ld / their_syms.ld   the linker symbols of the C objects at the release's addresses (their table: versions/<ver>/symbols.ld)
  turok_ragewars.yaml       the 1.1 skeleton with this release's segment starts; ver_layout.txt for tools/gen_yaml.py (env VER_LAYOUT)
  Makefile                  BASEROM = the release's ROM
and patches the workspace's tools/cycle.ps1 (VER_LAYOUT, no regeneration of the 1.1 symbol files).
Units that are not EXACT stay asm (splat) for now: the build is byte-identical without them."""
import bisect, collections, os, re, shutil, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
ROMS = {'us': 'baserom.us.v10.z64', 'eu': 'baserom.eu.z64', 'de': 'baserom.de.z64'}
THEIRS = 'D:/Projects/ext/ragewars-decomp/versions'
LAYOUT = {'us': dict(MAIN_CODE_END=0xC24F0, DATA_END=0x164000, OVL_START=0x164000, OVL_END=0x1B20D0, unresolved=False),      # segment starts from melalawi/ragewars-decomp versions/<ver>/RageWars.yaml
          'eu': dict(MAIN_CODE_END=0xC2860, DATA_END=0x176000, OVL_START=0x176000, OVL_END=0x1C5230, unresolved=False),
          'de': dict(MAIN_CODE_END=0xC25C0, DATA_END=0x166000, OVL_START=0x166000, OVL_END=0x1B3F60, unresolved=False)}
MAIN_VMA_OFF = 0x1FF400          # main image: VMA = ROM + 0x1FF400 (code), overlay A: VMA = 0x400000 + ROM - OVL_START

def opt(k, d=None): return sys.argv[sys.argv.index(k) + 1] if k in sys.argv else d

def load_pairs(ver):
    m = {}
    for l in open(f'wip/symmap_{ver}.txt'):
        a, b, c = l.split(); a = int(a, 16); b = int(b, 16)
        if a not in m: m[a] = b
    return m

class Map:
    """1.1 address -> release address: exact pairs, inferred symbol addresses, then piecewise-constant interpolation"""
    def __init__(self, ver):
        self.pairs = load_pairs(ver)
        self.keys = sorted(self.pairs)
        self.byname = {}
        for fn in (f'wip/ver/{ver}/syms.ld', f'wip/ver/{ver}/syms_inferred.ld'):
            if not os.path.exists(fn): continue
            for l in open(fn):
                m = re.match(r'\s*(?:PROVIDE\()?(\w+)\s*=\s*(0x[0-9A-Fa-f]+)', l)
                if m: self.byname[m.group(1)] = int(m.group(2), 16)
    def addr(self, a):
        """a: address as the 1.1 sources spell it (code 0x002xxxxx / 0x004xxxxx, data 0x8xxxxxxx)"""
        key = a | 0x80000000 if a < 0x00800000 else a
        if key in self.pairs:
            b = self.pairs[key]
            return b & 0x00FFFFFF if a < 0x00800000 else b
        i = bisect.bisect_left(self.keys, key)
        if 0 < i < len(self.keys):
            lo, hi = self.keys[i - 1], self.keys[i]
            if self.pairs[lo] - lo == self.pairs[hi] - hi:
                b = key + (self.pairs[lo] - lo)
                return b & 0x00FFFFFF if a < 0x00800000 else b
        return None
    def name(self, n):
        if n in self.byname: return self.byname[n]
        m = re.fullmatch(r'(?:D|func|jtbl)_([0-9A-Fa-f]{8})', n)
        if m: return self.addr(int(m.group(1), 16))
        return None

def read_manifest(fn):
    out = []
    for l in open(fn):
        raw = l.rstrip('\n'); l2 = l.split('#')[0].strip()
        if not l2: continue
        out.append(l2.split())
    return out

def main():
    ver = sys.argv[1]; out = opt('--out'); assert out, '--out <workspace>'
    lay = LAYOUT[ver]
    fmap = {}; ent = []
    for l in open(f'wip/funcmap_{ver}.txt'):
        f = l.split(); fmap[f[0]] = (f[3], int(f[4], 16)); ent.append((int(f[1], 16), f[0], int(f[2]), f[3], int(f[4], 16)))
    # the function map is by code content: a small function can be 'found' at a wrong place (a clone, or data that looks like code).  Keep only what is consistent: a function of the
    # overlay must land in the release's overlay, one of the main image in its main image, and in 1.1 order the release offsets must increase (the longest increasing run wins).
    bad = 0
    for lo_, hi_, ovl_ in ((0x1000, lay['MAIN_CODE_END'], False), (lay['OVL_START'], lay['OVL_END'], True)):
        reg = [e for e in sorted(ent) if e[3] != 'none' and ((e[0] >= 0x16E000) == ovl_) and lo_ <= e[4] < hi_]
        tails = []; prv = [None] * len(reg)
        for i, e in enumerate(reg):
            j = bisect.bisect_left([reg[q][4] for q in tails], e[4])
            if j > 0: prv[i] = tails[j - 1]
            if j == len(tails): tails.append(i)
            else: tails[j] = i
        ok = set(); k = tails[-1] if tails else None
        while k is not None: ok.add(reg[k][1]); k = prv[k]
        for e in sorted(ent):
            if e[3] != 'none' and ((e[0] >= 0x16E000) == ovl_) and e[1] not in ok: fmap[e[1]] = ('none', 0); bad += 1
    for e in ent:                                                           # mapped outside both regions
        if e[3] != 'none' and fmap[e[1]][0] != 'none' and not (0x1000 <= e[4] < lay['MAIN_CODE_END'] or lay['OVL_START'] <= e[4] < lay['OVL_END']): fmap[e[1]] = ('none', 0); bad += 1
    print('function map: %d entries ignored as inconsistent (clones / wrong region / out of order)' % bad)
    sweep = {}
    for l in open(f'wip/ver/{ver}/sweep.txt'):
        f = l.split(None, 2)
        if len(f) == 3: sweep[f[0]] = f[2].strip()
    amap = Map(ver)
    # ---- manifests
    kept = collections.Counter(); dropped = collections.Counter()
    keptmap = []                                                         # (unit, ROM offset, subdir) of the units kept as C
    for fn, ovl in (('funcs.txt', False), ('funcs_a.txt', True)):
        lines = []
        for f in read_manifest(fn):
            name = f[0]
            v = sweep.get(name, '')
            if not v.startswith('EXACT') or name not in fmap or fmap[name][0] == 'none':
                dropped[fn] += 1; continue
            rom = fmap[name][1]
            opts = [e for e in f[4:] if not e.startswith('ro=')]
            m = re.search(r'ro=(0x[0-9A-Fa-f]+):(\d+)', v)
            if any(e.startswith('ro=') for e in f[4:]) and not m:      # the 1.1 function has a literal pool of its own that the sweep did not find in this ROM: its object's .rodata would land at the wrong address
                dropped[fn] += 1; continue
            if m:
                n_ro = int(m.group(2)); r_ro = (n_ro + 3) & ~3          # a piece is a whole number of words: the tail up to the word boundary comes from the ROM (ro=off:size:real)
                real = n_ro if r_ro != n_ro else None
                for e in f[4:]:                                         # the 1.1 entry may say that only `real` bytes of the piece are the object's own data (the rest is a tail the ROM supplies): the same object, the same data
                    mm = re.fullmatch(r'ro=0x[0-9A-Fa-f]+:(\d+):(\d+)', e)
                    if mm and int(mm.group(1)) == n_ro: real = int(mm.group(2))
                opts.append(f'ro={m.group(1)}:{r_ro}' + (f':{real}' if real is not None else ''))
            lo, hi = (lay['OVL_START'], lay['OVL_END']) if ovl else (0x1000, lay['MAIN_CODE_END'])
            if rom < lo or rom + 4 * int(f[2]) > hi:                    # a clone of the function found in another region of the release (identical small functions repeat)
                dropped[fn] += 1; continue
            lines.append((rom, int(f[2]), f'{name} 0x{rom:X} {f[2]} {f[3]}' + ''.join(' ' + o for o in opts), int(f[1], 16)))
            kept[fn] += 1
        # the units keep the 1.1 order in the release: the longest increasing run of the release offsets is the consistent set, the rest are wrong placements (clones); then no overlaps
        lines.sort(key=lambda e: e[3])                                  # (in the order of the 1.1 ROM: the manifest file is not sorted)
        tails = []; prev = [None] * len(lines)
        for i, (r, n, _, _) in enumerate(lines):
            j = bisect.bisect_left([lines[t][0] for t in tails], r)
            if j > 0: prev[i] = tails[j - 1]
            if j == len(tails): tails.append(i)
            else: tails[j] = i
        keep = set(); k = tails[-1] if tails else None
        while k is not None: keep.add(k); k = prev[k]
        out_lines = []; last_end = 0
        for i, (r, n, text, _) in enumerate(lines):
            if i not in keep or r < last_end: dropped[fn] += 1; kept[fn] -= 1; continue
            out_lines.append(text); last_end = r + 4 * n
        lines = out_lines
        for text in out_lines:
            ff = text.split(); keptmap.append((ff[0], int(ff[1], 16), ff[3]))
        open(os.path.join(out, fn), 'w', newline='\n').write('\n'.join(lines) + '\n')
    print('manifest units kept', dict(kept), 'dropped (stay asm)', dict(dropped))
    # the Makefile compiles every file under src/: remove the sources of units that are not in this release's manifests (they stay asm: splat covers them)
    names = set()
    for fn in ('funcs.txt', 'funcs_a.txt'):
        for l in open(os.path.join(out, fn)):
            if l.strip(): names.add(l.split()[0])
    rm = 0
    for root, _, files in os.walk(os.path.join(out, 'src')):
        for f in files:
            if f.endswith(('.c', '.s')) and f.rsplit('.', 1)[0] not in names:
                os.remove(os.path.join(root, f)); rm += 1
    print('removed', rm, 'source files of units that are not in the release manifests')
    # a workspace that was prepared before (this is a rerun with newer sweep verdicts) holds the INCLUDE_ASM stub that splat wrote for a unit that was not a C unit then: restore the
    # sources of the kept units, and the headers they include, from the project
    src_of = {}
    for root, _, files in os.walk('src'):
        for f in files:
            if f.endswith(('.c', '.s')): src_of.setdefault(f.rsplit('.', 1)[0], os.path.join(root, f))
    nrest = 0
    for name in sorted(names):
        p = src_of.get(name)
        if not p or name.startswith('pad_'): continue
        q = os.path.join(out, p)
        if os.path.exists(q) and open(p, 'rb').read() == open(q, 'rb').read(): continue
        os.makedirs(os.path.dirname(q), exist_ok=True); shutil.copyfile(p, q); nrest += 1
        shutil.rmtree(os.path.join(out, 'asm', 'nonmatchings', os.path.basename(os.path.dirname(p)), name), ignore_errors=True)
    shutil.copytree('include', os.path.join(out, 'include'), dirs_exist_ok=True)
    print('restored', nrest, 'sources of kept units from the project')
    # linker padding: stray words (<= 3) between two consecutive C units are not code: keep them as .word units like the 1.1 pad_XXXX units (splat would disassemble them as instructions)
    rom_bytes = open(ROMS[ver], 'rb').read()
    npad = 0
    for fn, sub in (('funcs.txt', None), ('funcs_a.txt', None)):
        ents = []
        for l in open(os.path.join(out, fn)):
            f = l.split()
            if len(f) >= 4 and not f[0].startswith('pad_'): ents.append((int(f[1], 16), int(f[2]), f[3], f[0]))
        ents.sort()
        extra = []
        for (r1, n1, s1, nm1), (r2, n2, s2, nm2) in zip(ents, ents[1:]):
            gap = r2 - (r1 + 4 * n1)
            if 0 < gap <= 12 and gap % 4 == 0 and s1 == s2:
                g = r1 + 4 * n1; words = [int.from_bytes(rom_bytes[g + 4 * i:g + 4 * i + 4], 'big') for i in range(gap // 4)]
                pname = 'pad_%06X' % g
                d = os.path.join(out, 'src', s1); os.makedirs(d, exist_ok=True)
                body = ''.join(f'    /* {g + 4 * i:X} */  .word      0x{w:08X}\n' for i, w in enumerate(words))
                open(os.path.join(d, pname + '.s'), 'w', newline='\n').write(f'.include "macro.inc"\n\n.set noat\n.set noreorder\n\n.section .text, "ax"\n\n/* linker padding: stray words between objects, ROM 0x{g:X} */\nglabel {pname}\n{body}endlabel {pname}\n')
                extra.append(f'{pname} 0x{g:X} {gap // 4} {s1}'); npad += 1
        if extra: open(os.path.join(out, fn), 'a', newline='\n').write('\n'.join(extra) + '\n')
    print('generated', npad, 'padding units')
    # ---- layout + yaml skeleton
    open(os.path.join(out, 'ver_layout.txt'), 'w', newline='\n').write(''.join(f'{k} = 0x{lay[k]:X}\n' for k in ('MAIN_CODE_END', 'DATA_END', 'OVL_START', 'OVL_END')))
    y = open('turok_ragewars.yaml', newline='').read().replace('\r\n', '\n')
    y = y.replace('target_path: baserom.us.v11.z64', f'target_path: {ROMS[ver]}\n  symbol_name_format: auto_$VRAM\n  symbol_name_format_no_rom: auto_$VRAM')      # auto names must not collide with our identity names (func_XXXXXXXX = the 1.1 address)
    import hashlib
    sha = hashlib.sha1(open(ROMS[ver], 'rb').read()).hexdigest()
    y = re.sub(r'(?m)^sha1: [0-9a-f]{40}', f'sha1: {sha}', y)
    if not lay['unresolved']:
        y = re.sub(r'\n  # 56 KB, structure unresolved.*?\n  - \[0x160000, bin, ovl_unresolved_160000\]\n', '\n', y, flags=re.S)
    y = y.replace('    start: 0x16E000\n    vram: 0x400000', f"    start: 0x{lay['OVL_START']:X}\n    vram: 0x400000")
    open(os.path.join(out, 'turok_ragewars.yaml'), 'w', newline='\n').write(y)
    mk = open('Makefile', newline='').read().replace('BASEROM  := baserom.us.v11.z64', f'BASEROM  := {ROMS[ver]}')
    open(os.path.join(out, 'Makefile'), 'w', newline='\n').write(mk)
    # ---- symbol_addrs.txt: libultra/hardware names translated, plus every game function by its 1.1 name at the release's address
    sa = []; skipped = 0
    for l in open('symbol_addrs.txt', encoding='utf-8', errors='replace'):
        m = re.match(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+);(.*)', l)
        if not m: sa.append(l.rstrip('\n')); continue
        b = amap.name(m.group(1)) if m.group(1) in amap.byname else amap.addr(int(m.group(2), 16))
        if b is None: skipped += 1; sa.append('// unmapped: ' + l.rstrip('\n')); continue
        sa.append(f'{m.group(1)} = 0x{b:08X};{m.group(3)}')
    nf = 0
    have = set(m.group(1) for m in (re.match(r'(\w+)\s*=\s*0x', l) for l in sa) if m)      # libultra names are game_funcs entries too: one definition per name
    for l in open('docs/game_funcs.txt'):
        if l.startswith('#') or not l.strip(): continue
        f = l.split(); name = f[1]
        if name in have or name not in fmap or fmap[name][0] == 'none': continue
        rom = fmap[name][1]
        vma = rom + MAIN_VMA_OFF if rom < lay['OVL_START'] else rom - lay['OVL_START'] + 0x400000
        sa.append(f'{name} = 0x{vma:08X}; // type:func'); nf += 1
    seen_addr = {}                                                         # two symbols at one address (translated names that collide in a release): splat rejects the file, keep the first
    for i, l in enumerate(sa):
        m = re.match(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+);.*type:func', l)
        if not m: continue
        a = int(m.group(2), 16)
        if a in seen_addr: sa[i] = f'// same address as {seen_addr[a]}: ' + l
        else: seen_addr[a] = m.group(1)
    open(os.path.join(out, 'symbol_addrs.txt'), 'w', newline='\n').write('\n'.join(sa) + '\n')
    print('symbol_addrs: game functions', nf, 'unmapped libultra/other names', skipped)
    # ---- linker symbol files of the C objects
    names = {}
    for fn in ('c_syms.ld',):
        for l in open(fn):
            m = re.match(r'\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+);', l)
            if m: names[m.group(1)] = int(m.group(2), 16)
    cs = []; unm = []
    for n, a in sorted(names.items()):
        b = None
        mf = re.fullmatch(r'func_[0-9A-Fa-f]{8}', n)
        if mf and n in fmap and fmap[n][0] != 'none':             # a game function: the function map is authoritative (the instruction-pair map has gaps)
            rom = fmap[n][1]; b = rom + MAIN_VMA_OFF if rom < lay['OVL_START'] else rom - lay['OVL_START'] + 0x400000
        if b is None: b = amap.name(n)
        if b is None: b = amap.addr(a)
        if b is None: unm.append(n); b = a
        cs.append(f'{n} = 0x{b:08X};')
    open(os.path.join(out, 'c_syms.ld'), 'w', newline='\n').write('\n'.join(cs) + '\n')
    print('c_syms: %d symbols, %d without a mapping (kept at the 1.1 address)' % (len(cs), len(unm)))
    open(os.path.join(out, 'wip', 'c_syms_unmapped.txt'), 'w').write('\n'.join(unm) + '\n') if os.path.isdir(os.path.join(out, 'wip')) else None
    al = ['/* generated by tools/mkver.py */']
    for l in open('their_alias.ld'):
        m = re.match(r'PROVIDE\((\w+) = (0x[0-9A-Fa-f]+)\);', l)
        if m:
            b = amap.name(m.group(1))
            if b is None: b = amap.addr(int(m.group(2), 16))
            if b is not None: al.append(f'PROVIDE({m.group(1)} = 0x{b:08X});')
    src = f'{THEIRS}/{ver}/symbols.ld'
    t = open(src).read()
    # the 1.1 sources also use names of melalawi's 1.1 table (their_syms.ld) that the release's own table does not have: same names at the release's addresses
    rel = set(re.findall(r'(?m)^\s*(?:PROVIDE\()?\s*([.\w]+)\s*=', t)) | set(re.findall(r'PROVIDE\(([.\w]+) =', '\n'.join(al)))
    nt = 0
    for l in open('their_syms.ld'):
        m = re.match(r'PROVIDE\((\w+) = (0x[0-9A-Fa-f]+)\);', l)
        if not m or m.group(1) in rel: continue
        b = amap.name(m.group(1))
        if b is None: b = amap.addr(int(m.group(2), 16))
        if b is not None: al.append(f'PROVIDE({m.group(1)} = 0x{b:08X});'); nt += 1
    print('their_alias: %d names of the 1.1 table translated' % nt)
    # splat names a call target that lies in a unit we compile from C (so it has no asm definition) with its auto name, func_auto_<address>: the C object defines it as func_<1.1 address>
    na = 0
    for l in sa:
        m = re.match(r'(func_[0-9A-Fa-f]{8}) = (0x[0-9A-Fa-f]{8});', l)
        if m: al.append(f'PROVIDE(func_auto_{int(m.group(2), 16):08X} = {m.group(2)});'); na += 1
    for name, rom, sub in keptmap:                                       # libultra units are named by the SDK, not by an identity name: asm that calls them uses the auto name of their address
        if sub == 'libultra':
            vma = rom + MAIN_VMA_OFF
            al.append(f'PROVIDE(func_auto_{vma:08X} = 0x{vma:08X});'); na += 1
    print('their_alias: %d func_auto_ aliases of the C functions' % na)
    open(os.path.join(out, 'their_alias.ld'), 'w', newline='\n').write('\n'.join(al) + '\n')
    open(os.path.join(out, 'their_syms.ld'), 'w', newline='\n').write(f'/* generated from melalawi/ragewars-decomp versions/{ver}/symbols.ld (CC0) */\n' + t)
    # extra_syms.ld defines function names at their 1.1 addresses (asm functions the C objects reference): in another release splat names those functions itself (symbol_addrs.txt above)
    ex = [l.rstrip('\n') for l in open('extra_syms.ld') if not re.match(r'\s*(?:func|D|jtbl)_[0-9A-Fa-f]{8}\s*=\s*0x[0-9A-Fa-f]{8};', l) or re.match(r'\s*D_A4', l)]
    # the 1.1 sources also spell targets that have no symbol of ours the way splat names an undefined function/object in that release (func_402FB4, D_800CE040): translate those addresses too
    nu = 0
    for fn in ('undefined_funcs_auto.txt', 'undefined_syms_auto.txt'):
        for l in open(fn):
            m = re.match(r'\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+);', l)
            if not m: continue
            b = amap.name(m.group(1))
            if b is None: b = amap.addr(int(m.group(2), 16))
            if b is None: continue
            ex.append(f'{m.group(1)} = 0x{b:08X};' if int(m.group(2), 16) >= 0x00800000 else f'{m.group(1)} = 0x{b:X};'); nu += 1
    print('extra_syms: %d translated undefined symbols of the 1.1 sources' % nu)
    open(os.path.join(out, 'extra_syms.ld'), 'w', newline='\n').write('\n'.join(ex) + '\n')
    # ---- workspace cycle.ps1: layout env, no regeneration of the 1.1 symbol files
    cp = os.path.join(out, 'tools', 'cycle.ps1')
    t = open(cp, newline='').read()
    t = re.sub(r'\.\\\.venv\\Scripts\\python\.exe tools\\gen_c_syms\.py \| Out-Null\r?\n', '', t)
    t = re.sub(r'\.\\\.venv\\Scripts\\python\.exe tools\\gen_alias\.py \| Out-Null\r?\n', '', t)
    if 'VER_LAYOUT' not in t: t = re.sub(r'(Set-Location [^\r\n]+\r?\n)', r"\1$env:VER_LAYOUT = (Join-Path (Get-Location) 'ver_layout.txt')\n", t, count=1)
    open(cp, 'w', newline='\n').write(t)
    print('workspace', out, 'prepared; next: powershell tools\\cycle.ps1 there')

if __name__ == '__main__': main()
