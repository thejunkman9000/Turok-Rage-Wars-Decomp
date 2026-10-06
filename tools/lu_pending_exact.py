"""List exact-match libreultra functions (from scan_all.txt) whose ROM address is not already in funcs.txt."""
import re
done = set()
for l in open('funcs.txt'):
    l = l.split('#')[0].split()
    if len(l) >= 3: done.add(int(l[1], 16))
for l in open('scan_all.txt', encoding='utf-8-sig'):
    m = re.match(r'(\S+)\s+(\d+) insns\s+EXACT\s+ROM 0x([0-9A-F]+) \((\w+)\)', l)
    if not m: continue
    name, n, rom, reg = m.group(1), int(m.group(2)), int(m.group(3), 16), m.group(4)
    flag = '' if rom not in done else '(done)'
    print(f'{rom:06X} {n:4d} insns {name:28s} {reg} {flag}')
