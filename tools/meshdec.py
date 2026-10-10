import struct
def u32(d,o):return struct.unpack('>I',d[o:o+4])[0]
def cont(d):
    n=u32(d,0);o=[u32(d,4+4*i) for i in range(n+1)];return [d[o[i]:o[i+1]] for i in range(n)]
def load_mesh(m,base='D:/Projects/TurokRageWars/assets/meshes'):
    d=open(f'{base}/{m:03d}/part1_rnc10.bin','rb').read();p=cont(d)
    nv=u32(p[0],4);verts=[]
    for i in range(nv):
        r=p[0][8+16*i:24+16*i];x,y,z,fl,s,t=struct.unpack('>hhhHhh',r[:12]);verts.append(dict(p=(x,y,z),uv=(s,t),c=tuple(r[12:16])))
    groups=[]
    if len(p[2])>8:
        for x in cont(p[2]):
            s=cont(x);groups.append((s[0],s[1]))
    return verts,groups
def parse(dat):
    """-> list of ops: ('hdr',v) ('load',n) ('uv',vi,u,v) ('tri',a,b,c) ('unk',pos,byte)"""
    ops=[];i=0
    while i<len(dat):
        b=dat[i]
        if b&0x80:
            w=(dat[i]<<8)|dat[i+1];ops.append(('tri',(w>>10)&31,(w>>5)&31,w&31));i+=2
        elif b&0xE0==0x60 and i+5<=len(dat):
            u,v=struct.unpack('>Hh',dat[i+1:i+5]) if False else struct.unpack('>hh',dat[i+1:i+5]);ops.append(('uv',b&31,u,v));i+=5
        elif b&0xF0==0x40: ops.append(('op40',dat[i]&15,dat[i+1]));i+=2
        elif b&0xF0==0x20: ops.append(('load',dat[i]&15,dat[i+1]));i+=2
        elif b==0 and i+1<len(dat) and dat[i+1]==0: ops.append(('end',));i+=2
        else: ops.append(('unk',i,b));i+=1
    return ops

def run_group(verts,dat,K=1,opmode=0):
    """interpret stream; returns list of tris as 3x position tuples; cache semantic param K"""
    cache=[None]*64;uv={}
    tris=[];dest=0
    for o in parse(dat):
        if o[0]=='op40':
            dest=(o[1]<<8)|o[2]
        elif o[0]=='load':
            w=(0x2000|(o[1]<<8)|o[2]);A=(w>>5)&0xFF;cnt=w&31
            for j in range(cnt):
                if A+j<len(verts) and dest*K+j<64: cache[dest*K+j]=A+j
        elif o[0]=='tri':
            tris.append(tuple(cache[i] for i in o[1:4]))
    return tris
def quality(verts,tris):
    import math
    good=0;tot=0;bb=[(min(v['p'][k] for v in verts),max(v['p'][k] for v in verts)) for k in range(3)]
    diag=math.dist([b[0] for b in bb],[b[1] for b in bb]) or 1
    s=0
    for t in tris:
        if None in t: tot+=1;continue
        P=[verts[i]['p'] for i in t]
        e=max(math.dist(P[a],P[b]) for a,b in((0,1),(1,2),(2,0)))
        s+=e/diag;tot+=1;good+=1
    return good,tot,(s/good if good else 9)
