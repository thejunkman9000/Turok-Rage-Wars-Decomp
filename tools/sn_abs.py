#!/usr/bin/env python3
"""usage: sn_abs.py [--pads-only] <normalised.s> [ro_va [ro_size]]   (stdout = assembly ready for tools/as.sh)

Takes the n64link-normalised SN64 assembly of a ported function and
  1. turns every `.align N` inside an `.rdata` block into an explicit `.space` (gas raises the section alignment and then rounds the
     section size up to it, which would make the object's rodata longer than the original assembler's - the pad amounts are measured
     with one assembling pass, so the data layout is unchanged),
  2. makes the rodata label references absolute (gas_compat.finalize_rodata: the real rodata lives in KSEG0, the splat segment VA differs)."""
import sys, os, re
sys.path.insert(0, os.path.dirname(__file__))
import gas_compat
args = [a for a in sys.argv[1:] if a != '--pads-only']
pads_only = '--pads-only' in sys.argv      # only the `.align` -> `.space` step (tools/chk.py: it needs the relocations against .rodata, which step 2 removes)
text = re.sub(r'\.section\s+\.rdata', '.section .rodata', open(args[0]).read())
ro_va = int(args[1], 0) if len(args) > 1 and args[1] else None
ro_size = int(args[2]) if len(args) > 2 and args[2] else None
ro_real = int(args[3]) if len(args) > 3 and args[3] else None      # bytes of the piece that are the object's own data (the rest, up to ro_size, is an alignment tail the ROM supplies)
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
        pads[i] = (-(offs['__B_'] + (ro_va or 0))) % unit      # alignment is of the ABSOLUTE address: the original rodata of a translation unit started 8-aligned, so a double
                                                                # inside a piece that starts at 4 mod 8 gets its pad where the ROM has it
    for i in marks:
        lines[i] = f'\t.space\t{pads[i]}' if pads[i] > 0 else ''
        # a label written right before the `.align` belongs AFTER the padding (the SN assembler aligns the block, then defines the label)
        j = i - 1; moved = []
        while j >= 0 and (re.match(r'^[A-Za-z_.$][\w.$]*:\s*$', lines[j]) or not lines[j].strip()):
            if lines[j].strip(): moved.append(lines[j]); lines[j] = ''
            j -= 1
        if moved: lines[i] = lines[i] + '\n' + '\n'.join(reversed(moved))
text = '\n'.join(lines)
if ro_va is None or pads_only:
    sys.stdout.write(text)
else:
    out = gas_compat.finalize_rodata(text.split('\n'), gas_compat.Pool(), ro_va, ro_size)
    if ro_size:
        # the piece is longer than the compiled data (the alignment tail of the original object: stray bytes the linker left there, not always zero, or a dead constant):
        # fill the rest of the piece with the ROM's own bytes, as gas_compat's main does for the old (lu) path
        have = ro_real if ro_real else gas_compat.rodata_size(out)
        if have < ro_size:
            off = (ro_va - 0x400000 + int(os.environ.get('OVL_START', '0x16E000'), 0)) if ro_va < 0x80000000 else (ro_va - 0x80000000 + 0xC00)
            mk = re.search(r'BASEROM\s*:=\s*(\S+)', open('Makefile').read()) if os.path.exists('Makefile') else None      # a release workspace builds against its own ROM
            rom = open(mk.group(1) if mk else 'baserom.us.v11.z64', 'rb').read()
            out += '\n\t.section\t.rodata\n' + '\n'.join(f'\t.byte\t{b}' for b in rom[off + have:off + ro_size]) + '\n\t.text\n'
    sys.stdout.write(out)
