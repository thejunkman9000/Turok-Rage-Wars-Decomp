"""Print m2c skeletons for a ROM range, without the extern declaration noise. usage: python tools/show_m2c.py <lo> <hi>"""
import sys, glob, os, re
lo, hi = int(sys.argv[1], 0), int(sys.argv[2], 0)
for p in sorted(glob.glob('m2c_out/*.c')):
    rom = int(os.path.basename(p).split('_')[0], 16)
    if not (lo <= rom < hi): continue
    t = open(p, encoding='utf-8').read().split('\n')
    body = [l for l in t if not re.match(r'^(extern |\? \w+\(|[\w\*\s]+ \w+\(.*\);\s*/\* extern \*/)', l)]
    print('=' * 60); print('\n'.join(body).strip())
