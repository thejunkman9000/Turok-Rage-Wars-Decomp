import re,glob
cur=open('versions/de/syms.ld').read()
have=set(re.findall(r'(\w+)\s*=',cur))|set(re.findall(r'PROVIDE\((\w+)',cur))
add=[]
for f in glob.glob('D:/Projects/ws/vde4*/wip/out/syms.ld'):
    for l in open(f):
        l=l.strip(); m=re.match(r'(\w+)\s*=\s*(\w+);',l)
        if not m or m.group(1) in have: continue
        n=m.group(1); have.add(n)
        add.append(f'PROVIDE({n} = {m.group(2)});' if n.startswith('func_') else l)
open('versions/de/syms.ld','a').write('\n'+'\n'.join(add)+'\n'); print(len(add),'added'); print('\n'.join(add))
