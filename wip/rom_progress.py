import os, re, json
ROMS = [('US v1.1', 'D:/Projects/TurokRageWars', None, 0xC76B0, 0x16E000, 0x1BCDA0),
        ('US v1.0', 'D:/Projects/ws/v10', 'us', None, None, None),
        ('Europe', 'D:/Projects/ws/veu', 'eu', None, None, None),
        ('Germany', 'D:/Projects/ws/vde', 'de', None, None, None)]
out = []
for label, ws, ver, mce, os_, oe in ROMS:
    if ver:
        lay = dict(re.findall(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+)', open(f'{ws}/ver_layout.txt').read()))
        mce, os_, oe = int(lay['MAIN_CODE_END'], 16), int(lay['OVL_START'], 16), int(lay['OVL_END'], 16)
        vnames = {l.split()[0] for l in open(f'versions/{ver}/manifest.txt') if l.strip()}
    else: vnames = set()
    total = (mce - 0x1000 + oe - os_) // 4
    shared = spec = hand = pad = 0
    for fn in ('funcs.txt', 'funcs_a.txt'):
        for l in open(f'{ws}/{fn}'):
            f = l.split('#')[0].split()
            if len(f) < 4: continue
            n = int(f[2]); name, seg = f[0], f[3]
            if name.startswith('pad_'): pad += n; continue
            if os.path.exists(f'{ws}/src/{seg}/{name}.s'): hand += n
            elif name in vnames: spec += n
            elif os.path.exists(f'{ws}/src/{seg}/{name}.c'): shared += n
    rest = max(0, total - shared - spec - hand - pad)
    out.append(dict(rom=label, shared=shared, spec=spec, hand=hand + pad, rest=rest, total=total))
print(json.dumps(out, indent=1))
json.dump(out, open('wip/rom_progress.json', 'w'))
