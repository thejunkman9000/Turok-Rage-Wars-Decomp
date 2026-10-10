import os,glob
def _sidefile(fn):
    c=glob.glob(f'wip/side/*__{fn}.txt')
    if not c: return f'wip/side/{fn}.txt'
    return max(c,key=os.path.getmtime)
import sys,difflib,rabbitizer,re,collections
a,b=[l.split() for l in open(_sidefile(sys.argv[1]))]
a=[int(x,16) for x in a]; b=[int(x,16) for x in b][:len(a)+8]
d=lambda w,i:rabbitizer.Instruction(w,0x80000000+4*i).disassemble()
A=[d(w,i) for i,w in enumerate(a)]; B=[d(w,i) for i,w in enumerate(b)]
def norm(s): return re.sub(r'\$\w+','R',re.sub(r'\. \+ 4 \+ \(.*?\)','L',re.sub(r'func_[0-9A-F]+','F',re.sub(r'0x[0-9A-Fa-f]+|-0x[0-9A-Fa-f]+','N',s))))
sm=difflib.SequenceMatcher(None,[norm(x) for x in A],[norm(x) for x in B],autojunk=False)
cnt=collections.Counter()
for t,i1,i2,j1,j2 in sm.get_opcodes():
    if t!='equal': continue
    for k in range(i2-i1):
        ra=re.findall(r'\$\w+',A[i1+k]); rb=re.findall(r'\$\w+',B[j1+k])
        for x,y in zip(ra,rb):
            if x!=y: cnt[(x,y)]+=1
for (x,y),c in sorted(cnt.items(),key=lambda t:-t[1])[:40]: print(f'ours {x:6s} -> rom {y:6s} x{c}')
