"""Register EXACT results from tools/chk.py (chk_ok.txt) in funcs.txt and symbol_addrs.txt.
usage: python tools/accept.py [chk_ok.txt]"""
import sys, re

src = sys.argv[1] if len(sys.argv) > 1 else 'chk_ok.txt'
funcs = open('funcs.txt', newline='').read().replace('\r\n', '\n')
syms = open('symbol_addrs.txt', newline='').read().replace('\r\n', '\n')
have_rom = set()
for l in funcs.split('\n'):
    f = l.split('#')[0].split()
    if len(f) >= 4:
        have_rom.add(int(f[1], 16))
n = 0
for line in open(src):
    f = line.split()
    if len(f) < 4:
        continue
    name, rom, cnt, sub = f[0], int(f[1], 16), f[2], f[3]
    if rom in have_rom:
        continue
    funcs += (f"{name} 0x{rom:X} {cnt} {sub} {' '.join(f[4:])}").rstrip() + '\n'
    if not re.search(rf'^{re.escape(name)} = ', syms, re.M):
        syms += f"{name} = 0x{rom + 0x1FF400:08X}; // type:func\n"
    n += 1
open('funcs.txt', 'w', newline='\n').write(funcs)
open('symbol_addrs.txt', 'w', newline='\n').write(syms)
print(n, 'functions accepted')
