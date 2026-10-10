#!/usr/bin/env bash
# side.sh <file.c rel> <fn> <rom hex> [n=count] : side-by-side (ours @SN | ROM), mark differing lines with '|' ; xflags via env XF (e.g. -fno-builtin)
f=$1; fn=$2; rom=$3
R=$HOME/trw_s704; SN=$HOME/sn
cd $R; rsync -a /mnt/d/Projects/ws/s704/include/ include/; rsync -a --exclude='_v_*' /mnt/d/Projects/ws/s704/wip/ wip/
tmp=$(mktemp -d)
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $f > $tmp/s.i
$SN/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 ${XF:-} $tmp/s.i -o $tmp/s.s || exit 1
$SN/n64link asn64 $tmp/s.s | grep -v '[.]include' > $tmp/n.s
bash tools/as.sh $tmp/n.s $tmp/s.o
mips-linux-gnu-objdump -dr -M no-aliases,reg-names=32 $tmp/s.o > $tmp/ours.txt
python3 - $tmp $fn $rom <<'PY'
import sys,re,subprocess
tmp,fn,rom=sys.argv[1],sys.argv[2],int(sys.argv[3],16)
L=open(tmp+'/ours.txt').read().split('\n')
# find function
out=[];on=False
for l in L:
    if re.match(r'[0-9a-f]+ <'+fn+r'>:',l): on=True;continue
    if on and re.match(r'[0-9a-f]+ <.*>:',l): break
    if on and l.strip(): out.append(l)
ours=[];
for l in out:
    m=re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)',l)
    if m: ours.append([m.group(2),m.group(3).strip()])
    elif 'R_MIPS' in l and ours: ours[-1][1]+='   ; '+l.split()[-2]+' '+l.split()[-1]
n=len(ours)
d=open('/mnt/d/Projects/ws/s704/baserom.us.v11.z64','rb').read()
# find ROM insn count from funcs: assume same count or given by env
import os
cnt=int(os.environ.get('N') or n)
open(tmp+'/rom.bin','wb').write(d[rom:rom+cnt*4])
r=subprocess.run(['mips-linux-gnu-objdump','-D','-EB','-b','binary','-m','mips:4300','-M','no-aliases,reg-names=32',tmp+'/rom.bin'],capture_output=True,text=True).stdout.split('\n')
rm=[]
for l in r:
    m=re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)',l)
    if m: rm.append([m.group(2),m.group(3).strip()])
for i in range(max(len(ours),len(rm))):
    a=ours[i] if i<len(ours) else ['','']
    b=rm[i] if i<len(rm) else ['','']
    w1=a[0]; w2=b[0]
    if ';' in a[1] and w1 and w2:
        k=int(w1,16); k2=int(w2,16)
        if 'R_MIPS_26' in a[1]: m=0xFC000000
        else: m=0xFFFF0000
        same=(k&m)==(k2&m)
    else: same=(w1==w2)
    mark=' ' if same else '#'
    aa=a[1].split(';')[0].strip()
    print(f'{i:4d} {mark} {aa:44s} | {b[1]}')
PY
rm -rf $tmp
