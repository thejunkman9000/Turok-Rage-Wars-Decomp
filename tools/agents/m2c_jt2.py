"""m2c for a function with several jump tables: python tools/m2c_jt2.py <fn> <va>:<count> [<va>:<count> ...]  (output to stdout, tmp file wip/m2c_jt_tmp.s)"""
import sys, re, glob, struct, subprocess
name = sys.argv[1]
tabs = [(int(a.split(':')[0], 0), int(a.split(':')[1])) for a in sys.argv[2:]]
rom = open('baserom.us.v11.z64', 'rb').read()
tt = []
for tbl, count in tabs:
    base = (tbl & 0x1FFFFFFF) + 0xC00
    tt.append((tbl, [struct.unpack_from('>I', rom, base + 4 * i)[0] for i in range(count)]))
labels = set(t for _, ts in tt for t in ts)
src = None
for p in glob.glob('asm/*.s'):
    t = open(p, encoding='utf-8').read()
    m = re.search(rf'glabel {re.escape(name)}\n.*?endlabel {re.escape(name)}\n', t, re.S)
    if m: src = m.group(0); break
out = []
for line in src.split('\n'):
    m = re.match(r'\s*/\*\s*[0-9A-F]+\s+([0-9A-F]+)\s', line)
    if m and int(m.group(1), 16) in labels: out.append(f'.L{int(m.group(1), 16):08X}:')
    out.append(line)
text = '.include "macro.inc"\n.set noat\n.set noreorder\n.section .text\n' + '\n'.join(out)
text += '\n.section .rodata\n'
for tbl, ts in tt:
    text += f'glabel jtbl_{tbl:08X}\n' + ''.join(f'    .word .L{t:08X}\n' for t in ts)
open('wip/m2c_jt_tmp.s', 'w').write(text)
r = subprocess.run([sys.executable, 'tools/m2c/m2c.py', '--target', 'mips-gcc-c', '-f', name, 'wip/m2c_jt_tmp.s'], capture_output=True, text=True)
print(r.stdout if r.stdout.strip() else r.stderr)
