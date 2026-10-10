import sys, re
sys.path.insert(0, '/mnt/d/Projects/TurokRageWars/tools')
import gas_compat
text = re.sub(r'\.section\s+\.rdata', '.section .rodata', open(sys.argv[1]).read())
lines = text.split('\n'); sec = '.text'; marks = []
for i, l in enumerate(lines):
    st = l.strip()
    m = re.match(r'\.section\s+(\S+)', st)
    if m: sec = m.group(1).rstrip(',')
    elif st in ('.text', '.data', '.rodata'): sec = st
    elif re.match(r'\.(align|balign|p2align)\b', st) and sec == '.rodata': marks.append(i)
print('marks', len(marks))
labeled = list(lines)
for i in marks: labeled[i] = f'__ALB_{i}:\n{lines[i]}\n__ALA_{i}:'
offs = gas_compat.rodata_labels('\n'.join(labeled))
print({k: v for k, v in sorted(offs.items(), key=lambda kv: kv[1])})
