#!/usr/bin/env python3
"""python tools/var2.py <spec.json>   spec: {"base":"wip/w/x.c","func":"..","rom":"0x..","flags":"@SN","vars":[[["old","new"],...], ...]}
like var.py but prints score.py metrics (pos/struct/opdiff)"""
import json,sys,subprocess,re,os
s=json.load(open(sys.argv[1]))
base=open(s['base']).read()
lines=[];names=[]
for i,v in enumerate(s['vars']):
    t=base;ok=True
    for o,n in v:
        if o not in t: print('variant',i,'missing',o[:50]);ok=False;break
        t=t.replace(o,n,1)
    if not ok: continue
    p=f"wip/w/_v{i}.c";open(p,'w',newline='\n').write(t)
    lines.append(f"{p} {s['func']} {s['rom']} {s['flags']}");names.append(i)
open('wip/_vl2.txt','w',newline='\n').write('\n'.join(lines)+'\n')
out=subprocess.run(['powershell','-NoProfile','-File','tools/score.ps1','wip/_vl2.txt'],capture_output=True,text=True,stdin=subprocess.DEVNULL).stdout
recs=[l for l in out.splitlines() if 'pos=' in l or 'FAIL' in l]
for i,r in zip(names,recs): print(i,r[40:] if 'pos=' in r else r)
