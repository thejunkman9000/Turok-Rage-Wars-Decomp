import re
OP=r'(?:[A-Za-z_]\w*(?:(?:->|\.)\w+)*(?:\[[^\[\]]*\])*|-?\d+(?:\.\d+)?[fF]?|0x[0-9A-Fa-f]+)'
FLIP={'<':'>','>':'<','<=':'>=','>=':'<=','==':'==','!=':'!='}
def gen_flips(src, lo=0, hi=None):
    hi=hi or len(src)
    V=[]
    for m in re.finditer(r'('+OP+r')\s*(<=|>=|==|!=|<|>)\s*('+OP+r')',src[lo:hi]):
        a,op,b=m.group(1),m.group(2),m.group(3)
        s=lo+m.start(); e=lo+m.end()
        if a in ('if','while','return') : continue
        V.append(src[:s]+b+' '+FLIP[op]+' '+a+src[e:])
    return V
def gen_commute(src, lo=0, hi=None):
    hi=hi or len(src)
    V=[]
    for m in re.finditer(r'('+OP+r')\s*([+*|&^])\s*('+OP+r')',src[lo:hi]):
        a,op,b=m.group(1),m.group(2),m.group(3)
        if a==b: continue
        s=lo+m.start(); e=lo+m.end()
        # avoid unary/ptr contexts: previous char must not be * or & or identifier char
        pre=src[s-1] if s>0 else ' '
        if pre in '*&.>' or pre.isalnum() or pre=='_': continue
        V.append(src[:s]+b+' '+op+' '+a+src[e:])
    return V

def gen_array_toggle(src, lo, hi):
    V=[]
    for m in re.finditer(r'^extern ((?:const )?[A-Za-z_]\w*(?: \*+|\s+\**)?)(D_[0-9A-F]+);',src,flags=re.M):
        ty,name=m.group(1),m.group(2)
        body=src[lo:hi]
        if not re.search(r'\b'+name+r'\b',body): continue
        decl='extern %s%s[];'%(ty,name)
        t=src[:m.start()]+decl+src[m.end():]
        shift=len(decl)-(m.end()-m.start())
        lo2,hi2=lo+shift,hi+shift
        body2=re.sub(r'\b'+name+r'\b(?!\[)',name+'[0]',t[lo2:hi2])
        V.append(t[:lo2]+body2+t[hi2:])
    return V
def gen_arr_back(src, lo, hi):
    V=[]
    for m in re.finditer(r'^extern ((?:const )?[A-Za-z_]\w*(?: \*+|\s+\**)?)(D_[0-9A-F]+)\[\];',src,flags=re.M):
        ty,name=m.group(1),m.group(2)
        decl='extern %s%s;'%(ty,name)
        t=src[:m.start()]+decl+src[m.end():]
        shift=len(decl)-(m.end()-m.start())
        lo2,hi2=lo+shift,hi+shift
        body2=t[lo2:hi2].replace(name+'[0]',name)
        V.append(t[:lo2]+body2+t[hi2:])
    return V
