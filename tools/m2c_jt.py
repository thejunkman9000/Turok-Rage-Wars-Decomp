"""Run m2c on one function that contains a switch jump table.

usage: python tools/m2c_jt.py <function-name> <jump-table VA, e.g. 0x800CCB80> <entry count>
Reads the table entries from the ROM (KSEG0 VA -> ROM = VA - 0x80000000 + 0xC00), writes a temporary .s with
`.L<addr>` labels inserted at each case target and the table as .rodata, then runs m2c on it.
"""
import sys, re, glob, struct, subprocess, os

name = sys.argv[1]
tbl = int(sys.argv[2], 0)
count = int(sys.argv[3])
rom = open('baserom.us.v11.z64', 'rb').read()
base = (tbl & 0x1FFFFFFF) + 0xC00
targets = [struct.unpack_from('>I', rom, base + 4 * i)[0] for i in range(count)]

src = None
for p in glob.glob('asm/*.s') + glob.glob('asm/nonmatchings/**/*.s', recursive=True):
    t = open(p, encoding='utf-8').read()
    m = re.search(rf'glabel {re.escape(name)}\n.*?endlabel {re.escape(name)}\n', t, re.S)
    if m:
        src = m.group(0)
        break
if src is None:
    sys.exit(f'function {name} not found in asm/')

out = []
labels = set(targets)
for line in src.split('\n'):
    m = re.match(r'\s*/\*\s*[0-9A-F]+\s+([0-9A-F]+)\s', line)
    if m and int(m.group(1), 16) in labels:
        out.append(f'.L{int(m.group(1), 16):08X}:')
    out.append(line)
text = '.include "macro.inc"\n.set noat\n.set noreorder\n.section .text\n' + '\n'.join(out)
text += '\n.section .rodata\nglabel jtbl_' + f'{tbl:08X}\n'
for t in targets:
    text += f'    .word .L{t:08X}\n'
open('m2c_jt_tmp.s', 'w').write(text)
r = subprocess.run([sys.executable, 'tools/m2c/m2c.py', '--target', 'mips-gcc-c', '-f', name, 'm2c_jt_tmp.s'],
                   capture_output=True, text=True)
print(r.stdout if r.stdout.strip() else r.stderr)
