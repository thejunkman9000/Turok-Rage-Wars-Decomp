#include "r01_types.h"

typedef struct R1Seg { u32 hi; s32 flags; } R1Seg;

extern R1Map D_800F6D00[];
extern u32 D_800F7470[];
extern u32 D_800CD398[];
extern R1Seg D_800D05E0[];
u32 func_002023DC(void);

void func_00200610(void) {
    R1Map *e;
    u32 i;
    u32 lo;
    u32 w0;
    u32 asid;
    u32 w2;
    u32 *tp;
    R1Seg *p;
    u32 w3;
    u32 *sp;
    u32 w1;
    u32 hi;
    u32 *src;
    u32 sz;
    R1Map *q;

    asid = func_002023DC() & 0xFF;
    src = D_800F7470;
    for (i = 16; i < 48; i++) {
        D_800F6D00[i].lo = -1;
        D_800F6D00[i].flags = 0;
        w0 = *src++;
        w1 = *src++;
        w2 = *src++;
        w3 = *src++;
        if ((w2 | w3) & 2) {
            w0 &= 0x1FFE000;
            sz = 0x1000;
            tp = D_800CD398;
        top:
            if (*tp != w0) {
                if (*tp & 0x80000000) {
                    sz = 0;
                } else {
                    tp++;
                    sz <<= 2;
                    goto top;
                }
            }
            if (sz != 0) {
                if ((w2 & w3 & 3) != 3) {
                    if ((w2 & 3) == 2 && (w1 & 0xFF) != asid) {
                        w2 &= ~2;
                    }
                    if ((w3 & 3) == 2 && (w1 & 0xFF) != asid) {
                        w3 &= ~2;
                    }
                }
                lo = (w1 | 0x1FFF) ^ 0x1FFF;
                if (w2 & w3 & 2) {
                    sz <<= 1;
                } else if (w3 & 2) {
                    lo += sz;
                }
                D_800F6D00[i].lo = lo;
                D_800F6D00[i].hi = lo + sz - 1;
                D_800F6D00[i].flags = 3;
            }
        }
    }
    p = D_800D05E0;
    if ((s32)p->hi >= 0) {
        p++;
        while (p->hi < 0x80000000) {
            p++;
        }
    }
    lo = 0x80000000;
    i = 0;
    sp = (u32 *)p;
    q = D_800F6D00;
    do {
        q->lo = lo;
        hi = *sp++;
        q->hi = hi;
        q->flags = *sp++;
        lo = hi + 1;
        i++;
        q++;
    } while (lo != 0);
    while (i < 16) {
        D_800F6D00[i].lo = -1;
        D_800F6D00[i].flags = 0;
        i++;
    }
}
