#!/usr/bin/env python3
"""Decomp progress chart: python tools/progress_chart.py out.png [--no-history] [--committed]
   --committed  count the manifests of HEAD instead of the working tree (an integration that is still being verified does not count)

 1. US v1.1 (the build this repo reproduces byte for byte): matched game code by instructions (main image, overlay A, all)
 2. history: matched share of all game code at every commit that touched the function manifests
 3. the other releases (US v1.0, Europe, Germany): how much of the US v1.1 game code exists identically in them
    (tools/ver_cover.py) and how much of it is already covered by our matched C
Needs the ROMs for part 3 (project root, never committed); the part is skipped when they are missing."""
import os, re, subprocess, sys, time
from PIL import Image, ImageDraw, ImageFont

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
sys.path.insert(0, os.path.join(ROOT, 'tools'))

BG, PANEL, GRID = (22, 24, 32), (34, 37, 49), (58, 62, 78)
TXT, DIM = (236, 238, 244), (150, 156, 172)
GREEN, TEAL, ORANGE, GREY = (84, 196, 128), (64, 164, 190), (230, 150, 70), (86, 90, 106)
STATUS = {'us-rev1': 'byte-identical', 'us': 'byte-identical (asm for the rest)', 'eu': 'byte-identical (asm for the rest)', 'de': 'byte-identical (asm for the rest)'}     # state of the per-release ROM builds

def font(size, bold=False, mono=False):
    for name in (('consolab.ttf' if bold else 'consola.ttf') if mono else ('segoeuib.ttf' if bold else 'segoeui.ttf'), 'arial.ttf'):
        try: return ImageFont.truetype('C:/Windows/Fonts/' + name, size)
        except OSError: pass
    return ImageFont.load_default()

def manifests(text_of):
    """ROM ranges covered by matched C: one (start, end) per manifest entry (a span entry covers every function inside it, a stray head word may sit before the real entry)"""
    cov = []
    for fn in ('funcs.txt', 'funcs_a.txt'):
        t = text_of(fn)
        for l in (t or '').splitlines():
            f = l.split('#')[0].split()
            if len(f) >= 4 and f[3] in ('game', 'ovl_a'):      # pad_* entries count as covered (alignment words inside a function's recorded size)
                try: a = int(f[1], 16); cov.append((a, a + 4 * int(f[2])))
                except ValueError: pass
    return sorted(cov)

def universe():
    funcs = []
    for l in open('docs/game_funcs.txt'):
        f = l.split()
        if len(f) >= 3 and f[1].startswith('func_'): funcs.append((f[1], int(f[2]), int(f[0], 16)))      # name, instructions, ROM offset
    return funcs

def matched(cov, uni):
    """names of the universe functions of which at least 3/4 of the bytes lie in a matched entry"""
    out = set()
    for n, i, rom in uni:
        a, b = rom, rom + 4 * i
        if sum(max(0, min(b, e) - max(a, s)) for s, e in cov if s < b and e > a) * 4 >= (b - a) * 3: out.add(n)
    return out

def matched_now(committed=False):
    """names of the matched universe functions (working tree manifests, or those of HEAD)"""
    def read(fn):
        if committed:
            r = subprocess.run(['git', 'show', f'HEAD:{fn}'], capture_output=True, text=True, errors='replace')
            return r.stdout if r.returncode == 0 else ''
        return open(fn).read() if os.path.exists(fn) else ''
    return matched(manifests(read), universe())

def hand_names():
    """docs/hand_asm.txt: the units the original authors wrote in assembler"""
    out = set()
    if os.path.exists('docs/hand_asm.txt'):
        for l in open('docs/hand_asm.txt'):
            f = l.split('#')[0].split()
            if f: out.add(f[0])
    return out

def unit_ranges(committed=False):
    """{kind: [(rom start, rom end)]} of the non-pad manifest units by what their source is: 'c' (a .c file), 'hand' (a .s file of docs/hand_asm.txt: written in assembler by the original
    authors), 'asm' (any other .s: C-origin code that is still assembler); and the libultra / libaudio units separately with their instruction counts"""
    if committed:                                   # True = HEAD, else a revision
        rev = 'HEAD' if committed is True else committed
        files = set(subprocess.run(['git', 'ls-tree', '-r', '--name-only', rev, 'src'], capture_output=True, text=True).stdout.split())
        exists = lambda p: p in files
        def read(fn):
            r = subprocess.run(['git', 'show', f'{rev}:{fn}'], capture_output=True, text=True, errors='replace')
            return r.stdout if r.returncode == 0 else ''
    else:
        exists = os.path.exists
        read = lambda fn: open(fn).read() if os.path.exists(fn) else ''
    hand = hand_names()
    kinds = {'c': [], 'hand': [], 'asm': []}; lu = {'c': 0, 'hand': 0, 'asm': 0}
    for fn in ('funcs.txt', 'funcs_a.txt'):
        for l in read(fn).splitlines():
            f = l.split('#')[0].split()
            if len(f) < 4 or f[0].startswith('pad_'): continue
            try: a = int(f[1], 16); n = int(f[2])
            except ValueError: continue
            if exists(f'src/{f[3]}/{f[0]}.c'):
                import re as _re
                k = 'asm' if _re.search(r'(?m)^\s*INCLUDE_ASM', read(f'src/{f[3]}/{f[0]}.c')) else 'c'      # a NON_MATCHING draft that builds through INCLUDE_ASM is assembler, not matched C
            elif exists(f'src/{f[3]}/{f[0]}.s'): k = 'hand' if f[0] in hand else 'asm'
            else: continue
            if f[3] == 'libultra': lu[k] += n
            elif f[3] in ('game', 'ovl_a'): kinds[k].append((a, a + 4 * n))
    return {k: sorted(v) for k, v in kinds.items()}, lu

def current(committed=False):
    """per region [functions, insns, C functions, C insns, hand-written asm insns, asm placeholder insns]; and the libultra / libaudio instruction counts by kind"""
    uni = universe(); kinds, lu = unit_ranges(committed)
    cset = matched(kinds['c'], uni); hset = matched(kinds['hand'], uni) - cset; aset = matched(kinds['asm'], uni) - cset - hset
    tot = {'main': [0, 0, 0, 0, 0, 0], 'ovl': [0, 0, 0, 0, 0, 0]}
    for n, i, _ in uni:
        k = 'ovl' if 0x400000 <= int(n[5:], 16) < 0x500000 else 'main'
        t = tot[k]; t[0] += 1; t[1] += i
        if n in cset: t[2] += 1; t[3] += i
        elif n in hset: t[4] += i
        elif n in aset: t[5] += i
    tot['lu'] = lu
    return tot

def history():
    """[(commit time, matched insns of all game code)] over the commits that changed the manifests"""
    uni = universe(); total = sum(i for _, i, _ in uni)
    out = subprocess.run(['git', 'log', '--reverse', '--format=%H %ct', '--', 'funcs.txt', 'funcs_a.txt'], capture_output=True, text=True).stdout.splitlines()
    pts = []
    for l in out:
        f = l.split()
        if len(f) != 2: continue
        kinds, _ = unit_ranges(f[0])
        done = matched(kinds['c'], uni) | matched(kinds['hand'], uni)
        pts.append((int(f[1]), sum(i for n, i, _ in uni if n in done)))
    return pts, total

def bar(d, x, y, w, h, frac, color, label_in='', label_out='', f_in=None, f_out=None):
    d.rounded_rectangle((x, y, x + w, y + h), 6, fill=GRID)
    if frac > 0: d.rounded_rectangle((x, y, x + max(8, w * frac), y + h), 6, fill=color)
    if label_in: d.text((x + 12, y + h / 2), label_in, fill=(8, 22, 14), font=f_in, anchor='lm')
    if label_out: d.text((x + w + 14, y + h / 2), label_out, fill=TXT, font=f_out, anchor='lm')

def main():
    out = sys.argv[1] if len(sys.argv) > 1 and not sys.argv[1].startswith('--') else 'assets/progress.png'
    tot = current(committed='--committed' in sys.argv)
    lu = tot['lu']; allt = [a + b for a, b in zip(tot['main'], tot['ovl'])]
    W, M = 1280, 40
    covers = None
    try:
        import ver_cover
        kinds, _lu = unit_ranges('--committed' in sys.argv); covers = ver_cover.compute(done_names=matched(kinds['c'], universe()))      # (C only: asm placeholders and pads are not matched code)
    except Exception as e:
        print('release comparison skipped:', e)
    hist = None if '--no-history' in sys.argv else history()
    H = 112 + 3 * 74 + 56 + 110 + (300 if hist else 0) + ((72 + 4 * 66 + 90) if covers else 0) + 40
    im = Image.new('RGB', (W, H), BG); d = ImageDraw.Draw(im)
    d.text((M, 22), 'Turok: Rage Wars - matching decompilation', fill=TXT, font=font(32, True))
    d.text((M, 66), f'game code of the N64 cartridge, by instructions  -  {time.strftime("%Y-%m-%d")}', fill=DIM, font=font(17))
    y = 112
    d.text((M, y), 'US v1.1 - the build this repository reproduces byte for byte', fill=TXT, font=font(21, True)); y += 40
    rows = [('Main image', tot['main']), ('Overlay A', tot['ovl']), ('All game code', allt)]
    TEAL_ = (64, 164, 190); AMBER = (230, 150, 70)
    for nm, t in rows:
        done = t[3] + t[4]; pct = 100 * done / t[1]
        d.text((M, y + 18), nm, fill=DIM, font=font(18), anchor='lm')
        bx, bw = M + 170, W - 2 * M - 170 - 120
        d.rounded_rectangle((bx, y, bx + bw, y + 36), 6, fill=GRID)
        xx = bx
        for v, col in ((t[3], GREEN), (t[4], TEAL_), (t[5], AMBER)):
            w = bw * v / t[1]
            if w > 0: d.rounded_rectangle((xx, y, xx + max(6, w), y + 36), 6, fill=col)
            xx += w
        txt = f'{t[3]:,} of {t[1]:,} instructions in C   -   {t[2]:,} of {t[0]:,} functions'
        d.text((bx + 12, y + 18), txt, fill=(8, 22, 14), font=font(16), anchor='lm')
        d.text((bx + bw + 14, y + 18), f'{pct:.1f}%', fill=TXT, font=font(26, True), anchor='lm')
        y += 54
    # hand-written assembly / placeholders of the game code, and the SDK libraries
    note = []
    if allt[4]: note.append(f'{allt[4]:,} insns are hand-written assembly of the original game (boot, exception handler, cache / TLB routines: kept as .s, counted as done)')
    if allt[5]: note.append(f'{allt[5]:,} insns are C-origin code that is still assembler (Controller Pak library): counted as not done')
    for s in note: d.text((M + 170, y - 6), s, fill=DIM, font=font(14), anchor='lm'); y += 20
    lut = lu['c'] + lu['hand'] + lu['asm']
    if lut:
        y += 6
        d.text((M, y + 18), 'libultra / libaudio', fill=DIM, font=font(18), anchor='lm')
        bx, bw = M + 170, W - 2 * M - 170 - 120
        d.rounded_rectangle((bx, y, bx + bw, y + 36), 6, fill=GRID)
        xx = bx
        for v, col in ((lu['c'], GREEN), (lu['hand'], TEAL_), (lu['asm'], AMBER)):
            w = bw * v / lut
            if w > 0: d.rounded_rectangle((xx, y, xx + max(6, w), y + 36), 6, fill=col)
            xx += w
        d.text((bx + 12, y + 18), f"{lu['c']:,} of {lut:,} instructions in C   -   {lu['hand']:,} SDK assembly, {lu['asm']:,} still assembler", fill=(8, 22, 14), font=font(16), anchor='lm')
        d.text((bx + bw + 14, y + 18), f"{100 * (lu['c'] + lu['hand']) / lut:.1f}%", fill=TXT, font=font(26, True), anchor='lm')
        y += 54
    y += 22
    if hist:
        pts, total = hist
        d.text((M, y), 'Progress over time (share of all game code that is matched C, or assembly written by the original authors)', fill=TXT, font=font(21, True)); y += 38
        x0, x1, y0, y1 = M + 56, W - M - 90, y, y + 210
        d.rounded_rectangle((M, y0 - 8, W - M, y1 + 44), 8, fill=PANEL)
        for p in (0, 25, 50, 75, 100):
            yy = y1 - (y1 - y0) * p / 100
            d.line((x0, yy, x1, yy), fill=GRID, width=1); d.text((x0 - 10, yy), f'{p}%', fill=DIM, font=font(14), anchor='rm')
        t0, t1 = pts[0][0], pts[-1][0]
        span = max(1, t1 - t0)
        xy = [(x0 + (x1 - x0) * (t - t0) / span, y1 - (y1 - y0) * min(1.0, m / total)) for t, m in pts]
        poly = [(x0, y1)] + xy + [(xy[-1][0], y1)]
        d.polygon(poly, fill=(46, 96, 70)); d.line(xy, fill=GREEN, width=3)
        d.ellipse((xy[-1][0] - 5, xy[-1][1] - 5, xy[-1][0] + 5, xy[-1][1] + 5), fill=GREEN)
        d.text((xy[-1][0] + 12, xy[-1][1]), f'{100 * pts[-1][1] / total:.1f}%', fill=TXT, font=font(20, True), anchor='lm')
        lt = time.localtime(t0); first = int(time.mktime((lt.tm_year, lt.tm_mon, lt.tm_mday + 1, 0, 0, 0, 0, 0, -1)))
        for tt in range(first, t1 + 1, 86400):
            xx = x0 + (x1 - x0) * (tt - t0) / span
            d.line((xx, y1, xx, y1 + 6), fill=DIM); d.text((xx, y1 + 10), time.strftime('%b %d', time.localtime(tt)), fill=DIM, font=font(14), anchor='mt')
        y = y1 + 70
    if covers:
        d.text((M, y), 'The other releases: how much of the US v1.1 game code carries over', fill=TXT, font=font(21, True)); y += 34
        d.text((M, y), 'same functions found through the other public decompilation\'s symbol tables (same names in every release), code compared byte for byte (relocations ignored)', fill=DIM, font=font(14)); y += 30
        order = [('us-rev1', 'US v1.1'), ('us', 'US v1.0'), ('eu', 'Europe'), ('de', 'Germany')]
        for key, nm in order:
            c = covers.get(key)
            if not c: continue
            d.text((M, y + 20), nm, fill=TXT, font=font(19, True), anchor='lm')
            d.text((M, y + 44), STATUS.get(key, ''), fill=DIM, font=font(13), anchor='lm')
            bx, bw = M + 170, W - 2 * M - 170 - 250
            d.rounded_rectangle((bx, y, bx + bw, y + 40), 6, fill=GREY)
            total = c['total']
            if key == 'us-rev1':
                segs = [(c['matched'], GREEN)]
                txt = f"{100 * c['matched'] / total:.1f}% matched C"; txt2 = 'the reference build'
            else:
                cl = c['classes']
                same_m = cl['exact'][0] + cl['reloc'][0]; same_u = cl['exact'][1] + cl['reloc'][1]
                diff = cl['diff'][0] + cl['diff'][1]
                segs = [(same_m, GREEN), (same_u, TEAL), (diff, ORANGE)]
                txt = f"{100 * same_m / total:.1f}% reusable now"; txt2 = f"{100 * (same_m + same_u) / total:.1f}% identical code"
            xx = bx
            for v, col in segs:
                w = bw * v / total
                if w > 0: d.rounded_rectangle((xx, y, xx + max(3, w), y + 40), 6, fill=col)
                xx += w
            d.text((bx + bw + 16, y + 10), txt, fill=TXT, font=font(17, True), anchor='lm'); d.text((bx + bw + 16, y + 31), txt2, fill=DIM, font=font(14), anchor='lm')
            y += 66
        lx = M + 170
        for col, label in ((GREEN, 'matched C that builds this release'), (TEAL, 'identical code, not matched yet'), (ORANGE, 'different in this release'), (GREY, 'absent / not covered')):
            d.rounded_rectangle((lx, y + 8, lx + 18, y + 26), 4, fill=col); d.text((lx + 26, y + 17), label, fill=DIM, font=font(14), anchor='lm'); lx += 36 + int(d.textlength(label, font=font(14))) + 24
        y += 40
    im.crop((0, 0, W, y + 16)).save(out)
    print([(n, round(100 * (t[3] + t[4]) / t[1], 1), round(100 * t[3] / t[1], 1)) for n, t in rows], 'libultra', lu, out)

if __name__ == '__main__':
    main()
