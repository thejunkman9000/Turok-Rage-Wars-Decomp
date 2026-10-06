#!/usr/bin/env python3
"""Compare each object's .text size in the link map with the ROM range splat gave it (run in ~/trw)."""
import re, sys
ld = open('turok_ragewars.ld').read()
m = open('build/turok_ragewars.map').read()
sizes = {}
for mo in re.finditer(r'^ \.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+) (build/\S+\.o)', m, re.M):
    sizes[mo.group(3)] = (int(mo.group(1), 16), int(mo.group(2), 16))
# expected: from yaml subsegment offsets in file order
import yaml
y = yaml.safe_load(open('turok_ragewars.yaml'))
segs = y['segments']
main = next(s for s in segs if isinstance(s, dict) and s.get('name') == 'main')
subs = main['subsegments']
starts = [s[0] for s in subs] + [0xC7010]
bad = 0
for i, s in enumerate(subs[:-1]):
    start, kind = s[0], s[1]
    nm = s[2] if len(s) > 2 else f'{start:X}'
    path = f'build/src/{nm}.o' if kind == 'c' else f'build/asm/{nm}.o'
    exp = starts[i + 1] - start
    got = sizes.get(path, (0, None))[1]
    flag = '' if got == exp else f'   <-- +{(got or 0) - exp:#x}'
    if flag: bad += 1
    print(f'{path:48s} expect 0x{exp:X} got {hex(got) if got is not None else "-"}{flag}')
print('mismatched objects:', bad)
