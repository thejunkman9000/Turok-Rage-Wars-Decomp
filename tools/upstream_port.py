#!/usr/bin/env python3
"""Prepare the functions that the other decompilation (melalawi/ragewars-decomp) matches for US v1.1 and that we do not cover yet for the checker, then
add the confirmed ones to our manifests (tools/port_their.py).

usage: python tools/upstream_port.py prepare            writes wip/their_new/<name>.c (their source with the `/* their2 */` marker: compiled against
                                                        include/their2, the headers of their current tree), wip/their_new/list.txt (checker list) and
                                                        %TEMP%/their_extra.json (name -> address/size for port_their.py)
       powershell -File tools/chk.ps1 wip/their_new/list.txt > wip/their_new/result.txt        (@SN: their toolchain; EXACT lines are what counts)
       python tools/port_their.py wip/their_new/result.txt --their2 [--subsume] [--dry]       manifest lines + sources (marker kept)
Candidates are the rows of tools/upstream_check.py whose source is published; `--only name,name` restricts the list."""
import json, os, re, subprocess, sys
REPO = 'D:/Projects/ext/ragewars-decomp'
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
MARK = '/* their2: ported from the newer headers of the other decompilation (include/their2) */\n'

def candidates():
    cover = []
    for fn in ('funcs.txt', 'funcs_a.txt'):
        for l in open(fn):
            f = l.split('#')[0].split()
            if len(f) >= 3 and not f[0].startswith('pad_'):
                try: s = int(f[1], 16); cover.append((s, s + 4 * int(f[2])))
                except ValueError: pass
    def covered(a, b):
        return sum(max(0, min(b, e) - max(a, s)) for s, e in cover if s < b and e > a) * 4 >= (b - a) * 3
    uni = []
    for l in open('docs/game_funcs.txt'):
        f = l.split()
        if len(f) >= 3 and f[1].startswith('func_'): uni.append((int(f[1][5:], 16) | 0x80000000, int(f[0], 16), int(f[2]), f[1]))
    addr = {}
    for l in open(REPO + '/versions/us-rev1/symbol_addrs.txt'):
        m = re.match(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+);', l)
        if m: addr[m.group(1)] = int(m.group(2), 16)
    out = []
    for u in json.load(open(REPO + '/versions/us-rev1/report.json'))['units']:
        for f in u.get('functions', []):
            if float(f.get('fuzzy_match_percent') or 0) < 99.99 or f['name'] not in addr: continue
            a = addr[f['name']]; size = int(f.get('size') or 0)
            if size <= 0 or not any(a <= x[0] < a + size and not covered(x[1], x[1] + 4 * x[2]) for x in uni): continue
            src = REPO + '/src/%s.c' % f['name']
            if os.path.exists(src): out.append((f['name'], a, size, src))
    return sorted(out, key=lambda r: r[1])

def main():
    if len(sys.argv) < 2 or sys.argv[1] != 'prepare': print(__doc__); return
    only = set(sys.argv[sys.argv.index('--only') + 1].split(',')) if '--only' in sys.argv else None
    os.makedirs('wip/their_new', exist_ok=True)
    extra, lines = {}, []
    for name, a, size, src in candidates():
        if only and name not in only: continue
        va = a & 0xFFFFFF
        rom = va - 0x400000 + 0x16E000 if 0x400000 <= va < 0x500000 else va - 0x1FF400
        open('wip/their_new/%s.c' % name, 'w', newline='\n').write(MARK + open(src, errors='replace').read().replace('\r\n', '\n'))
        lines.append('wip/their_new/%s.c %s 0x%X @SN' % (name, name, rom))
        extra[hex(a)] = [name, 100.0, size]
    open('wip/their_new/list.txt', 'w', newline='\n').write('\n'.join(lines) + '\n')
    json.dump(extra, open(os.environ['TEMP'] + '/their_extra.json', 'w'))
    print(len(lines), 'candidates ->', 'wip/their_new/list.txt')

if __name__ == '__main__':
    main()
