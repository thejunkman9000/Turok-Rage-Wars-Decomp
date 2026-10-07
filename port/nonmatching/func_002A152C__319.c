#include "b23_types.h"

u8 *func_002A152C(u8 *s, u8 *t) {
    s32 v, c0, hv, w;
    u8 *q;

    v = *s;
    if (v == 0) {
        goto ret0;
    }
    c0 = *t;
scan:
    if (v == c0) {
        goto found;
    }
    s++;
    v = *s;
    if (v != 0) {
        goto scan;
    }
found:
    q = t;
    if (c0 == 0) {
        goto retS;
    }
cmp:
    hv = *s;
    w = *q;
    q++;
    if (w != hv) {
        goto mism;
    }
    w = *q;
    s++;
    if (w != 0) {
        goto cmp;
    }
    __asm__ __volatile__("" : : : "memory");
    w = *q;
mism:
    if (w != 0) {
        goto cont;
    }
retS:
    return s;
cont:
    v = *s;
    if (v != 0) {
        goto scan;
    }
ret0:
    return 0;
}
