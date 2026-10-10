import sys,re,subprocess
tmp,fn,rom,cnt,romf=sys.argv[1],sys.argv[2],int(sys.argv[3]),int(sys.argv[4]),sys.argv[5]
txt=subprocess.run(['mips-linux-gnu-objdump','-dr','-M','no-aliases,reg-names=32',tmp+'/s.o'],capture_output=True,text=True).stdout.split('\n')
out=[];on=False
for l in txt:
    if re.match(r'[0-9a-f]+ <'+fn+r'>:',l): on=True;continue
    if on and re.match(r'[0-9a-f]+ <.*>:',l): break
    if on and l.strip(): out.append(l)
ours=[]
for l in out:
    m=re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)',l)
    if m: ours.append([m.group(2),m.group(3).strip(),m.group(1)])
    elif 'R_MIPS' in l and ours: ours[-1][1]+='   ; '+l.split()[-2]+' '+l.split()[-1]
d=open(romf,'rb').read()
open(tmp+'/rom.bin','wb').write(d[rom:rom+cnt*4])
r=subprocess.run(['mips-linux-gnu-objdump','-D','-EB','-b','binary','-m','mips:4300','-M','no-aliases,reg-names=32',tmp+'/rom.bin'],capture_output=True,text=True).stdout.split('\n')
rm=[]
for l in r:
    m=re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)',l)
    if m: rm.append([m.group(2),m.group(3).strip()])
import difflib
def key(x):
    t=re.sub(r'<[^>]*>','',x)
    t=re.sub(r'\s+',' ',t).strip()
    return t
for i in range(max(len(ours),len(rm))):
    a=ours[i] if i<len(ours) else ['','','']
    b=rm[i] if i<len(rm) else ['','']
    w1=a[0]; w2=b[0]
    if ';' in a[1] and w1 and w2:
        k=int(w1,16); k2=int(w2,16)
        m=0xFC000000 if 'R_MIPS_26' in a[1] else 0xFFFF0000
        same=(k&m)==(k2&m)
    else: same=(w1==w2)
    mark=' ' if same else '#'
    aa=a[1].split(';')[0].strip()
    print(f'{i:4d} {mark} {aa:46s} | {b[1]}')
