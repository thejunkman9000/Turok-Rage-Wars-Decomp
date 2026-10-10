#!/bin/bash
# regmap.sh <file.c> : after dump.sh, show for each pseudo: hard reg (first greg pass), refs/length stats
f=$1; n=$(basename $f .c)
bash /mnt/d/Projects/ws/s705/tools/dump.sh $f >/dev/null
d=/tmp/dd_$n
python3 - $d <<'PY'
import re,sys
d=sys.argv[1]
g=open(d+'/a.i.greg').read()
l=open(d+'/a.i.lreg').read()
disp={}
m=re.search(r'Register dispositions:\n(.*?)\n\n',g,re.S)
if m:
    for a,b in re.findall(r'(\d+) in (\d+)',m.group(1)): disp[int(a)]=int(b)
order=re.search(r'regs to allocate: ([\d ]+)',g)
print('alloc order:',order.group(1) if order else None)
stats={}
for m in re.finditer(r'Register (\d+) used (\d+) times across (\d+) insns(?: in block (\d+))?(.*)',l):
    stats[int(m.group(1))]=(int(m.group(2)),int(m.group(3)),m.group(5)[:50])
names={16:'s0',17:'s1',18:'s2',19:'s3',20:'s4',21:'s5',22:'s6',23:'s7',30:'fp',2:'v0',3:'v1',4:'a0',5:'a1'}
for p in sorted(stats):
    if stats[p][2] and 'block' in str(stats[p]): continue
    r=disp.get(p)
    print(p,'->',names.get(r,r),stats[p])
PY
