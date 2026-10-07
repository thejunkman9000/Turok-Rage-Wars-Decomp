import re,bisect,sys
syms=[];base=None
for l in open('port/build/turok.map',errors='replace'):
    m=re.match(r'\s*Preferred load address is ([0-9a-f]+)',l)
    if m: base=int(m.group(1),16)
    m=re.match(r'\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})',l)
    if m and base and int(m.group(2),16)>=base: syms.append((int(m.group(2),16)-base,m.group(1)))
syms.sort();k=[s[0] for s in syms]
def w(r):
    i=bisect.bisect_right(k,r)-1;return syms[i][1].lstrip('_')
lines=open('port_log.txt').read().split('\n')
for i,l in enumerate(lines):
    if l.startswith('UNIMPLEMENTED') and i+1<len(lines) and 'trace' in lines[i+1]:
        items=lines[i+1].split(':',1)[1].split()
        print(l, '<-', ' > '.join(w(int(b,16)-1) for a,b in (x.split(':') for x in items)))
