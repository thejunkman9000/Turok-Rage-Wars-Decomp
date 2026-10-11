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
STATUS = {'us-rev1': 'byte-identical', 'us': 'on hold', 'eu': 'on hold', 'de': 'on hold'}     # state of the per-release ROM builds (other releases wait until US v1.1 is completely done)

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

def hasm_names(committed=False):
    """names of the universe functions that a hand-written asm source (a non-pad `.s` unit of the manifests: boot code, exception handler, cache / SR routines) covers:
    they reproduce the bytes but are not C and never will be (the original authors wrote them in assembler)"""
    if committed:
        files = set(subprocess.run(['git', 'ls-tree', '-r', '--name-only', 'HEAD', 'src'], capture_output=True, text=True).stdout.split())
        exists = lambda p: p in files
        def read(fn):
            r = subprocess.run(['git', 'show', f'HEAD:{fn}'], capture_output=True, text=True, errors='replace')
            return r.stdout if r.returncode == 0 else ''
    else:
        exists = os.path.exists
        read = lambda fn: open(fn).read() if os.path.exists(fn) else ''
    cov = []
    for fn in ('funcs.txt', 'funcs_a.txt'):
        for l in read(fn).splitlines():
            f = l.split('#')[0].split()
            if len(f) >= 4 and f[3] in ('game', 'ovl_a', 'libultra') and not f[0].startswith('pad_') and exists(f'src/{f[3]}/{f[0]}.s'):
                try: a = int(f[1], 16); cov.append((a, a + 4 * int(f[2])))
                except ValueError: pass
    return matched(sorted(cov), universe())

def current(committed=False):
    uni = universe(); done = matched_now(committed); hasm = hasm_names(committed)
    tot = {'main': [0, 0, 0, 0, 0], 'ovl': [0, 0, 0, 0, 0]}                # matched functions, functions, matched insns, insns, of the matched: hand-written asm insns
    for n, i, _ in uni:
        k = 'ovl' if 0x400000 <= int(n[5:], 16) < 0x500000 else 'main'
        t = tot[k]; t[1] += 1; t[3] += i
        if n in done:
            t[0] += 1; t[2] += i
            if n in hasm: t[4] += i
    return tot

def history():
    """[(commit time, matched insns of all game code)] over the commits that changed the manifests"""
    uni = universe(); total = sum(i for _, i, _ in uni)
    out = subprocess.run(['git', 'log', '--reverse', '--format=%H %ct', '--', 'funcs.txt', 'funcs_a.txt'], capture_output=True, text=True).stdout.splitlines()
    pts = []
    for l in out:
        f = l.split()
        if len(f) != 2: continue
        def show(fn):
            r = subprocess.run(['git', 'show', f'{f[0]}:{fn}'], capture_output=True, text=True, errors='replace')
            return r.stdout if r.returncode == 0 else ''
        done = matched(manifests(show), uni)
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
    allt = [a + b for a, b in zip(tot['main'], tot['ovl'])]
    W, M = 1280, 40
    covers = None
    try:
        import ver_cover
        covers = ver_cover.compute(done_names=matched_now('--committed' in sys.argv))
    except Exception as e:
        print('release comparison skipped:', e)
    hist = None if '--no-history' in sys.argv else history()
    H = 112 + 3 * 74 + 56 + (300 if hist else 0) + ((72 + 4 * 66 + 90) if covers else 0) + 40
    im = Image.new('RGB', (W, H), BG); d = ImageDraw.Draw(im)
    d.text((M, 22), 'Turok: Rage Wars - matching decompilation', fill=TXT, font=font(32, True))
    d.text((M, 66), f'game code of the N64 cartridge, by instructions  -  {time.strftime("%Y-%m-%d")}', fill=DIM, font=font(17))
    y = 112
    d.text((M, y), 'US v1.1 - the build this repository reproduces byte for byte', fill=TXT, font=font(21, True)); y += 40
    rows = [('Main image', tot['main']), ('Overlay A', tot['ovl']), ('All game code', allt)]
    for nm, t in rows:
        pct = 100 * t[2] / t[3]
        d.text((M, y + 18), nm, fill=DIM, font=font(18), anchor='lm')
        bar(d, M + 170, y, W - 2 * M - 170 - 120, 36, t[2] / t[3], GREEN, f'{t[2]:,} of {t[3]:,} instructions   -   {t[0]:,} of {t[1]:,} functions' + (f'   ({t[4]:,} insns hand-written asm)' if t[4] else ''), f'{pct:.1f}%', font(16), font(26, True))
        y += 54
    y += 22
    if hist:
        pts, total = hist
        d.text((M, y), 'Progress over time (share of all game code that is matched: C, plus the original hand-written asm once its units exist)', fill=TXT, font=font(21, True)); y += 38
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
    print([(n, round(100 * t[2] / t[3], 1)) for n, t in rows], out)

if __name__ == '__main__':
    main()
