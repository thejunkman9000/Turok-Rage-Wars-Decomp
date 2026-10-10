import os,glob
def _sidefile(fn):
    c=glob.glob(f'wip/side/*__{fn}.txt')
    if not c: return f'wip/side/{fn}.txt'
    return max(c,key=os.path.getmtime)
import sys,difflib,rabbitizer
a,b=[l.split() for l in open(_sidefile(sys.argv[1]))]
a=[int(x,16) for x in a]; b=[int(x,16) for x in b][:len(a)+8]
d=lambda w,i:rabbitizer.Instruction(w,0x80000000+4*i).disassemble()
A=[d(w,i) for i,w in enumerate(a)]; B=[d(w,i) for i,w in enumerate(b)]
key=lambda s:s.split()[0] if s.split() else ''
sm=difflib.SequenceMatcher(None,[key(x) for x in A],[key(x) for x in B],autojunk=False)
for t,i1,i2,j1,j2 in sm.get_opcodes():
    n=max(i2-i1,j2-j1)
    for k in range(n):
        x=A[i1+k] if i1+k<i2 else ''; y=B[j1+k] if j1+k<j2 else ''
        ia=i1+k if i1+k<i2 else -1; jb=j1+k if j1+k<j2 else -1
        print(f'{ia:4d} {x:40s}{"  " if x==y else "!="} {jb:4d} {y}')
