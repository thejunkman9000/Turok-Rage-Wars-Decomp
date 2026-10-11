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
    fmap = {}
    for l in open(f'wip/funcmap_{ver}.txt'):
        f = l.split(); fmap[f[0]] = (f[3], int(f[4], 16))
    sweep = {}
    for l in open(f'wip/ver/{ver}/sweep.txt'):
        f = l.split(None, 2)
        if len(f) == 3: sweep[f[0]] = f[2].strip()
    amap = Map(ver)
    # ---- manifests
    kept = collections.Counter(); dropped = collections.Counter()
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
            if m: opts.append(f'ro={m.group(1)}:{m.group(2)}')
            lines.append(f'{name} 0x{rom:X} {f[2]} {f[3]}' + ''.join(' ' + o for o in opts))
            kept[fn] += 1
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
    # ---- layout + yaml skeleton
    open(os.path.join(out, 'ver_layout.txt'), 'w').write(''.join(f'{k} = 0x{lay[k]:X}\n' for k in ('MAIN_CODE_END', 'DATA_END', 'OVL_START', 'OVL_END')))
    y = open('turok_ragewars.yaml', newline='').read().replace('\r\n', '\n')
    y = y.replace('target_path: baserom.us.v11.z64', f'target_path: {ROMS[ver]}\n  symbol_name_format: auto_$VRAM\n  symbol_name_format_no_rom: auto_$VRAM')      # auto names must not collide with our identity names (func_XXXXXXXX = the 1.1 address)
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
    for l in open('docs/game_funcs.txt'):
        if l.startswith('#') or not l.strip(): continue
        f = l.split(); name = f[1]
        if name not in fmap or fmap[name][0] == 'none': continue
        rom = fmap[name][1]
        vma = rom + MAIN_VMA_OFF if rom < lay['OVL_START'] else rom - lay['OVL_START'] + 0x400000
        sa.append(f'{name} = 0x{vma:08X}; // type:func'); nf += 1
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
        b = amap.name(n)
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
    open(os.path.join(out, 'their_alias.ld'), 'w', newline='\n').write('\n'.join(al) + '\n')
    src = f'{THEIRS}/{ver}/symbols.ld'
    t = open(src).read()
    open(os.path.join(out, 'their_syms.ld'), 'w', newline='\n').write(f'/* generated from melalawi/ragewars-decomp versions/{ver}/symbols.ld (CC0) */\n' + t)
    # extra_syms.ld defines function names at their 1.1 addresses (asm functions the C objects reference): in another release splat names those functions itself (symbol_addrs.txt above)
    ex = [l.rstrip('\n') for l in open('extra_syms.ld') if not re.match(r'\s*(?:func|D|jtbl)_[0-9A-Fa-f]{8}\s*=\s*0x[0-9A-Fa-f]{8};', l) or re.match(r'\s*D_A4', l)]
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
