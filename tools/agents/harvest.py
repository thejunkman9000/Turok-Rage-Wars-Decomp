#!/usr/bin/env python3
"""python tools/harvest.py <fn> <work.c> <rom> <flags...>   splice permuter outputs (best scores first) into work.c and chk them"""
import sys,subprocess,os,re
fn,work,rom=sys.argv[1:4]; flags=' '.join(sys.argv[4:])
d=subprocess.run(['wsl','-d','Ubuntu-24.04','--','bash','-c',f'ls -d ~/perm/s702_{fn}/output-* 2>/dev/null; echo ~'],capture_output=True,text=True).stdout.split()
home=d[-1]; outs=d[:-1]
def sc(o): return int(re.match(r'.*output-(\d+)-',o).group(1))
outs.sort(key=sc)[:0] if False else None
outs=sorted(outs,key=sc)[:6]
lines=[];files=[]
for i,o in enumerate(outs):
    subprocess.run(['wsl','-d','Ubuntu-24.04','--','bash','-c',f'cp {o}/source.c /mnt/d/Projects/ws/s702/wip/w/_h{i}.c'])
    r=subprocess.run([sys.executable,'tools/splice.py',work,f'wip/w/_h{i}.c',fn,f'wip/w/_hs{i}.c'],capture_output=True,text=True)
    if r.returncode: print('splice fail',o,r.stderr[-200:]); continue
    lines.append(f'wip/w/_hs{i}.c {fn} {rom} {flags}'); files.append((o,i))
open('wip/_vl.txt','w').write('\n'.join(lines)+'\n')
out=subprocess.run(['powershell','-NoProfile','-File','tools/fchk.ps1','wip/_vl.txt'],capture_output=True,text=True).stdout
recs=[l for l in out.splitlines() if l.startswith('func_')]
for (o,i),r in zip(files,recs): print(os.path.basename(o),f'wip/w/_hs{i}.c',r[28:])
