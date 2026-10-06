import struct, collections, re
rom = open('baserom.us.v11.z64','rb').read()
def w(o): return struct.unpack_from('>I', rom, o)[0]
regions = {'main':(0x1000,0xC7010), 'ovl_a':(0x16E000,0x1BCDA0)}
for name,(lo,hi) in regions.items():
    c = collections.Counter()
    for o in range(lo,hi,4):
        x = w(o)
        op, rs, rt, rd, sh, fn = x>>26, (x>>21)&31, (x>>16)&31, (x>>11)&31, (x>>6)&31, x&63
        if op==0 and rt==0 and sh==0 and rd!=0 and rs!=0:
            if fn==0x21: c['move=addu rd,rs,$zero (GCC style)']+=1
            if fn==0x25: c['move=or   rd,rs,$zero (IDO style)']+=1
            if fn==0x20: c['move=add  rd,rs,$zero']+=1
        if op==0 and rs==0 and rt!=0 and sh==0 and rd!=0 and fn==0x21: c['move=addu rd,$zero,rt']+=1
        if op==0 and rs==0 and rt!=0 and sh==0 and rd!=0 and fn==0x25: c['move=or   rd,$zero,rt']+=1
        if op==0x0f and rt==1: c['lui $at']+=1
    print(f"== {name}"); [print(f"   {v:7d}  {k}") for k,v in sorted(c.items())]

# frame analysis: function = addiu sp,sp,-F ; find 'sw ra,off(sp)' within next 12 insns
hist = collections.Counter(); tot=0
for name,(lo,hi) in regions.items():
    for o in range(lo,hi,4):
        x=w(o)
        if x>>16==0x27BD and x&0x8000:
            F = 0x10000-(x&0xFFFF)
            for k in range(1,14):
                y=w(o+4*k)
                if y>>16==0xAFBF: # sw ra, off(sp)
                    off=y&0xFFFF; hist[(F,off,'top' if off==F-4 else 'not-top')]+=1; tot+=1; break
top=sum(v for (F,off,t),v in hist.items() if t=='top')
print(f"\nframes with sw ra found: {tot}; ra in top slot (IDO-style): {top} ({100*top/tot:.1f}%)")
for (F,off,t),v in sorted(hist.items(), key=lambda kv:-kv[1])[:12]: print(f"   F=0x{F:X} ra@0x{off:X} {t:8s} x{v}")
# leaf-ness / noreorder markers: frames > 0x18 with ra not top
