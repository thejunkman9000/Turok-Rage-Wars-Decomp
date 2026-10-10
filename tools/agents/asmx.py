import sys,re
# usage: python wip/asmx.py <file.s> [start_label]  -> compact asm of the file (all functions) 
f=sys.argv[1]
out=[]
for l in open(f,encoding='utf-8'):
    l=l.rstrip('\n')
    m=re.match(r'\s*/\* ([0-9A-F]+) ([0-9A-F]+) ([0-9A-F]{8}) \*/\s+(.*)',l)
    if m:
        s=re.sub(r'\s+',' ',m.group(4)).replace('$','')
        out.append(s)
    elif re.match(r'\s*(glabel|alabel|endlabel|\.L)',l) or l.strip().startswith('.L'):
        out.append(l.strip())
print('\n'.join(out))
