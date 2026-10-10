import sys,re
# psplice.py fn basefile outfile : splice function from wip/perm_<fn>.c (copied by pbest.sh) into basefile
fn,base,out=sys.argv[1:4]
s=open(f'wip/perm_{fn}.c').read()
b=open(base).read()
m=re.search(r'^[A-Za-z_][\w \*]*\b'+fn+r'\s*\(',s,re.M)
j=m.start()
mb=re.search(r'^[A-Za-z_][\w \*]*\b'+fn+r'\s*\(',b,re.M)
i=mb.start()
open(out,'w').write(b[:i]+s[j:])
