"""Side-by-side full listing from a lu_ud.sh JSON. usage: python tools/lu_side.py build_ud.json <func>"""
import sys, json, rabbitizer
d = {f['name']: f for f in json.load(open(sys.argv[1]))}[sys.argv[2]]
def dis(w, m):
    i = rabbitizer.Instruction(int(w, 16)).disassemble()
    return (i.split()[0] + ' <' + 'reloc>') if m else i
n = len(d['words'])
ours = [dis(w, m) + (f" [{nm}]" if m and nm else '') for w, m, nm in zip(d['words'], d['mask'], d['relnames'])]
rom = [dis(w, 0) for w in d['romwords'][:n + 4]]
for i in range(max(n, len(rom))):
    a = ours[i] if i < n else ''; b = rom[i] if i < len(rom) else ''
    print(f"{i:3d} {'  ' if a.split()[0:1] == b.split()[0:1] else '!='} {a:46s}| {b}")
