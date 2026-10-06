#!/usr/bin/env python3
"""Quick variant search for one function.  usage: python tools/vq.py <spec.json>
spec: {"header": "#include ...\nprotos", "name": "fn", "rom": "0xB7558", "sig": "s32 fn(...)", "bodies": ["body variant 1", ...],
       "keep": true}   (a body is the text between the braces; variants of the whole body, tried with tools/vtry.py)"""
import json, subprocess, sys
spec = json.load(open(sys.argv[1]))
tpl = spec.get('header', '#include "libaudio.h"') + '\n\n' + spec['sig'] + ' {\n    @@body@@\n}\n'
open('wip/_vq_t.c', 'w').write(tpl)
json.dump({'body': spec['bodies']}, open('wip/_vq_v.json', 'w'))
r = subprocess.run([sys.executable, 'tools/vtry.py', 'wip/_vq_t.c', spec['name'], spec['rom'], 'wip/_vq_v.json', '--keep'], capture_output=True, text=True)
print('\n'.join(r.stdout.strip().split('\n')[-3:]) or r.stderr[-800:])
