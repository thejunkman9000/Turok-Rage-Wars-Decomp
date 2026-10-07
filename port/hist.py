import re,bisect,collections,sys
syms=[];base=None
for l in open('port/build/turok.map',errors='replace'):
    m=re.match(r'\s*Preferred load address is ([0-9a-f]+)',l)
    if m: base=int(m.group(1),16)
    m=re.match(r'\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})',l)
    if m and base and int(m.group(2),16)>=base: syms.append((int(m.group(2),16)-base,m.group(1)))
syms.sort();k=[s[0] for s in syms]
def w(r):
    i=bisect.bisect_right(k,r)-1;return syms[i][1].lstrip('_')
t=open('port_log.txt').read()
ms=re.findall(r'trace \(oldest first\): (.*)',t)
items=[i.split(':') for i in max(ms,key=len).split()]
c=collections.Counter(w(int(b,16)-1) for a,b in items)
print(len(items),'entries'); print(c.most_common(int(sys.argv[1]) if len(sys.argv)>1 else 40))
# one iteration of the main loop (between two calls of func_0029382C)
seq=[(a,w(int(b,16)-1)) for a,b in items]
idx=[i for i,(a,n) in enumerate(seq) if n=='func_0029382C']
if len(idx)>2:
    s=seq[idx[-2]:idx[-1]]
    print('ONE LOOP:',' > '.join(f"{n}" for a,n in s))
