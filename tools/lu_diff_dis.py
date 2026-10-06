"""Read lu_diff.py output on stdin; print ours vs ROM disassembly, marking differences."""
import sys, re, rabbitizer
row = re.compile(r'^\s*(\d+)\s+(!=)?\s*([0-9A-F]{8})\s+([0-9A-F]{8})\s*$')
for line in sys.stdin:
    line = line.strip()
    m = row.match(line)
    if not m:
        if line: print(line)
        continue
    i, bad, a, b = m.groups()
    da = rabbitizer.Instruction(int(a, 16)).disassemble()
    db = rabbitizer.Instruction(int(b, 16)).disassemble()
    print(f'{int(i):>3} != {da:38s} | {db}' if bad else f'{int(i):>3}    {da}')
