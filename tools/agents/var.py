#!/usr/bin/env python3
"""python tools/var.py <spec.json>   spec: {"base":"wip/w/x.c","func":"..","rom":"0x..","flags":"@SN -fno-builtin","vars":[[["old","new"],...], ...]}
each variant = list of (old,new) replacements applied to base (old must occur). prints words-differ per variant."""
import json,sys,subprocess,re,os
s=json.load(open(sys.argv[1]))
base=open(s['base']).read()
lines=[];names=[]
for i,v in enumerate(s['vars']):
    t=base;ok=True
    for o,n in v:
        if o not in t: print('variant',i,'missing',o[:40]);ok=False;break
        t=t.replace(o,n,1)
    if not ok: continue
    p=f"wip/w/_v{i}.c";open(p,'w').write(t)
    lines.append(f"{p} {s['func']} {s['rom']} {s['flags']}");names.append(i)
open('wip/_vl.txt','w').write('\n'.join(lines)+'\n')
out=subprocess.run(['powershell','-NoProfile','-File','tools/fchk.ps1','wip/_vl.txt'],capture_output=True,text=True).stdout
recs=[l for l in out.splitlines() if l.startswith('func_')]
for i,r in zip(names,recs): print(i,r[28:])
