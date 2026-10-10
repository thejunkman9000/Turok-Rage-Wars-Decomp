import sys,re,subprocess,os
o,vram,out=sys.argv[1:4]
R=os.path.expanduser('~/trw_s705')
S={}
for f in ('symbol_addrs.txt','undefined_syms_auto.txt','undefined_funcs_auto.txt','hardware_regs.ld','extra_syms.ld','their_syms.ld'):
    try:
        for l in open(f'{R}/{f}',errors='replace'):
            m=re.match(r'\s*(?:PROVIDE\()?(\w+)\s*=\s*(0x[0-9A-Fa-f]+)',l)
            if m: S[m.group(1)]=int(m.group(2),16)
    except OSError: pass
def addr(n):
    m=re.fullmatch(r'(?:D|func|jtbl)_([0-9A-Fa-f]{8})',n)
    if n in S and not (m and S[n]==int(n[-8:],16)): return S[n]
    if m: return int(m.group(1),16)
    return S.get(n)
OV=int(vram,16)<0x80000000
und=subprocess.run(['mips-linux-gnu-nm','-u',o],capture_output=True,text=True).stdout.split()
und=[x for x in und if x!='U']
args=[]
for n in und:
    a=addr(n)
    if a is None: a=0x80000000
    elif OV:
        if 0x80200000<=a<0x80300000: a&=0x0FFFFFFF
    elif a<0x80000000: a|=0x80000000
    args+=['--defsym',f'{n}=0x{a:X}']
# rodata/data placed far away
r=subprocess.run(['mips-linux-gnu-ld','-EB','-Ttext=0x'+vram,'-Trodata=0x90000000','-Tdata=0x91000000','-Tbss=0x92000000','--no-warn-mismatch','-e','0']+args+[o,'-o',out],capture_output=True,text=True)
if r.returncode: sys.stderr.write(r.stderr); sys.exit(1)
