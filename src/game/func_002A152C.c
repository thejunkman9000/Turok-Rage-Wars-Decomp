

#include "common.h"
typedef unsigned char uc;
uc *func_002A152C(uc *s, uc *t)
{
    s32 v, c0, w;
    register s32 hv asm("$3");
    uc *q;
    v = *s;
    if (v == 0) goto ret0;
    c0 = *t;
scan:
    if (v == c0) goto found;
    s++;
    v = *s;
    if (v != 0) goto scan;
found:
    q = t;
    if (c0 == 0) goto retS;
cmp:
    hv = *s;
    __asm__ __volatile__("" : "+r"(hv));
    w = *q; q++;
    if (hv != w) goto mism;
    s++; if (*(volatile uc *)q != 0) goto cmp;
    w = *q;
mism:
    if (w != 0) goto cont;
retS:
    return s;
cont:
    v = *s;
    if (v != 0) goto scan;
ret0:
    return 0;
}

