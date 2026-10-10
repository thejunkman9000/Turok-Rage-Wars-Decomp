import os,glob
def _sidefile(fn):
    c=glob.glob(f'wip/side/*__{fn}.txt')
    if not c: return f'wip/side/{fn}.txt'
    return max(c,key=os.path.getmtime)
import sys,difflib,rabbitizer,re
a,b=[l.split() for l in open(_sidefile(sys.argv[1]))]
a=[int(x,16) for x in a]; b=[int(x,16) for x in b][:len(a)+4]
d=lambda w,i:rabbitizer.Instruction(w,0x80000000+4*i).disassemble()
def norm(s):
    s=re.sub(r'\$\w+','R',s); s=re.sub(r'\. \+ 4 \+ \(.*?\)','L',s); s=re.sub(r'func_[0-9A-F]+','F',s)
    s=re.sub(r'0x[0-9A-Fa-f]+|-0x[0-9A-Fa-f]+','N',s) if len(sys.argv)>2 else s
    return s
A=[d(w,i) for i,w in enumerate(a)]; B=[d(w,i) for i,w in enumerate(b)]
na=[norm(x) for x in A]; nb=[norm(x) for x in B]
sm=difflib.SequenceMatcher(None,na,nb,autojunk=False)
for t,i1,i2,j1,j2 in sm.get_opcodes():
    if t=='equal': continue
    print(f'--- {t} ours[{i1}:{i2}] rom[{j1}:{j2}]')
    for k in range(i1,i2): print('   O',k,A[k])
    for k in range(j1,j2): print('   R',k,B[k])
