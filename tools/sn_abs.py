#!/usr/bin/env python3
"""usage: sn_abs.py <normalised.s> [ro_va [ro_size]]   (stdout = assembly ready for tools/as.sh)

Takes the n64link-normalised SN64 assembly of a ported function and
  1. turns every `.align N` inside an `.rdata` block into an explicit `.space` (gas raises the section alignment and then rounds the
     section size up to it, which would make the object's rodata longer than the original assembler's - the pad amounts are measured
     with one assembling pass, so the data layout is unchanged),
  2. makes the rodata label references absolute (gas_compat.finalize_rodata: the real rodata lives in KSEG0, the splat segment VA differs)."""
import sys, os, re
sys.path.insert(0, os.path.dirname(__file__))
import gas_compat
text = re.sub(r'\.section\s+\.rdata', '.section .rodata', open(sys.argv[1]).read())
ro_va = int(sys.argv[2], 0) if len(sys.argv) > 2 and sys.argv[2] else None
ro_size = int(sys.argv[3]) if len(sys.argv) > 3 and sys.argv[3] else None
lines = text.split('\n')
sec = '.text'; marks = []
for i, l in enumerate(lines):
    st = l.strip()
    m = re.match(r'\.section\s+(\S+)', st)
    if m: sec = m.group(1).rstrip(',')
    elif st in ('.text', '.data', '.rodata', '.sdata', '.bss'): sec = st
    elif re.match(r'\.(align|balign|p2align)\b', st) and sec == '.rodata': marks.append(i)
if marks:
    pads = {}
    for i in marks:       # one assembling pass per alignment: the label sits right before a data byte, so its offset is the real position
        m = re.match(r'\.(align|balign|p2align)\s+(\d+)', lines[i].strip())
        unit = (1 << int(m.group(2))) if m.group(1) != 'balign' else int(m.group(2))
        probe = []
        for j, l in enumerate(lines):
            if j == i: probe.append('__B_:\n\t.byte 0')
            elif j in pads: probe.append(f'\t.space\t{pads[j]}' if pads[j] > 0 else '')
            elif j in marks and j > i: probe.append('')
            else: probe.append(l)
        offs = gas_compat.rodata_labels('\n'.join(probe))
        pads[i] = (-offs['__B_']) % unit
    for i in marks:
        lines[i] = f'\t.space\t{pads[i]}' if pads[i] > 0 else ''
        # a label written right before the `.align` belongs AFTER the padding (the SN assembler aligns the block, then defines the label)
        j = i - 1; moved = []
        while j >= 0 and (re.match(r'^[A-Za-z_.$][\w.$]*:\s*$', lines[j]) or not lines[j].strip()):
            if lines[j].strip(): moved.append(lines[j]); lines[j] = ''
            j -= 1
        if moved: lines[i] = lines[i] + '\n' + '\n'.join(reversed(moved))
text = '\n'.join(lines)
if ro_va is None:
    sys.stdout.write(text)
else:
    sys.stdout.write(gas_compat.finalize_rodata(text.split('\n'), gas_compat.Pool(), ro_va, ro_size))
