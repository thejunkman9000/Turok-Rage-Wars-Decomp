declre=re.compile(r'^\s*(const |static |struct |register )?[A-Za-z_][A-Za-z0-9_ ]*[ *]+\**[A-Za-z_][A-Za-z0-9_]*(\[[^\]]*\])?( = [^;{}]*)?;\s*$')
def body_range(src,fn):
    m=re.search(r'^[^\n]*\b'+fn+r'\([^;]*?\)\s*\{\n',src,flags=re.M)
    i0=m.end(); d=1;k=i0
    while d:
        c=src[k]
        if c=='{': d+=1
        elif c=='}': d-=1
        k+=1
    return i0,k-1
def spans_of(src,a,b):
    sp=[];s=a;depth=0;i=a
    while i<b:
        ch=src[i]
        if ch=='{': depth+=1
        elif ch=='}':
            depth-=1
            if depth==0:
                rest=src[i+1:b].lstrip()
                if rest.startswith('else') or (rest.startswith('while') and src[s:i+1].lstrip().startswith('do')): pass
                else: sp.append((s,i+1)); s=i+1
        elif ch==';' and depth==0: sp.append((s,i+1)); s=i+1
        i+=1
    return sp
def blocks(src,fn):
    i0,iend=body_range(src,fn)
    out=[(i0,iend)]
    stack=[]
    i=i0
    while i<iend:
        ch=src[i]
        if ch=='{': stack.append(i)
        elif ch=='}':
            a=stack.pop(); out.append((a+1,i))
        i+=1
    return out
def gen_swaps(src,fn):
    V=[]
    for (a,b) in blocks(src,fn):
        sp=spans_of(src,a,b)
        j=0
        while j<len(sp) and declre.match(src[sp[j][0]:sp[j][1]]): j+=1
        n=len(sp)
        for x in range(j,n-1):
            s1,e1=sp[x]; s2,e2=sp[x+1]
            t1=src[s1:e1]; t2=src[s2:e2]
            if '{' in t1 or '{' in t2: continue
            if re.search(r'\breturn\b|\bgoto\b|\bbreak\b|\bcontinue\b|:\s*$',t1) or re.search(r'\breturn\b|\bgoto\b|\bbreak\b|\bcontinue\b',t2): continue
            V.append(src[:s1]+t2+src[e1:s2]+t1+src[e2:])
    return V
def gen_wraps(src,fn,maxlen=3):
    V=[]
    for (a,b) in blocks(src,fn):
        sp=spans_of(src,a,b)
        j=0
        while j<len(sp) and declre.match(src[sp[j][0]:sp[j][1]]): j+=1
        n=len(sp)
        for x in range(j,n):
            for y in range(x+1,min(n,x+maxlen)+1):
                s0=sp[x][0];e0=sp[y-1][1]
                t=src[s0:e0].lstrip()
                if y-x==1 and t.startswith('do'): continue
                if re.match(r'(case|default|\w+:)',t): continue
                if re.search(r'^\s*\w+:',src[s0:e0],flags=re.M): continue
                V.append(src[:s0]+'\n    do {'+src[s0:e0]+'\n    } while (0);'+src[e0:])
    return V
def dedupe(src,V):
    seen=set();R=[]
    for v in V:
        if v not in seen and v!=src: seen.add(v);R.append(v)
    return R
def gen(src,fn):
    i0,i1=body_range(src,fn)
    return dedupe(src,gen_swaps(src,fn)+gen_wraps(src,fn)+mut3.gen_flips(src,i0,i1)+mut3.gen_commute(src,i0,i1)+mut3.gen_array_toggle(src,i0,i1)+mut3.gen_arr_back(src,i0,i1))
