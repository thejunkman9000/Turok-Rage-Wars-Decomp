/* Low code region (ROM 0x1210): builds the 48-entry mapping table D_800F6D00 (lo, hi, flags): entries 16..47 from the TLB-style records at D_800F7470,
 * entries 0..15 from the segment table D_800D05E0, the rest unused (-1).  Built with `-O2 -mcpu=r4000 -msplit-addresses` (mode sn+sa+r4k+epi).
 * Two register pins in the second loop (`hi` = $2, `lo` = $5) fix the allocation order that the original source got from its own variable layout. */
#include "r01_types.h"

typedef struct R1Seg { u32 hi; s32 flags; } R1Seg;

extern R1Map D_800F6D00[];
extern u32 D_800F7470[];
extern u32 D_800CD398[];
extern R1Seg D_800D05E0[];
u32 func_002023DC(void);

void func_00200610(void) {
    u32 asid;
    u32 w0, w1, w2, w3;
    u32 sz;
    register u32 hi __asm__("$2");
    u32 fl;
    register u32 lo __asm__("$5");
    u32 *src, *tp, *sp;
    R1Map *m;
    R1Seg *p;
    u32 i, k;
    int new_var;

    sz = func_002023DC() & 0xFF;
    asid = sz;
    src = D_800F7470;
    for (k = 16; k < 48; k++) {
        D_800F6D00[k].lo = -1;
        D_800F6D00[k].flags = 0;
        w0 = *src++;
        w1 = *src++;
        w2 = *src++;
        w3 = *src++;
        if ((w2 | w3) & 2) {
            w0 &= 0x1FFE000;
            tp = D_800CD398;
            sz = 0x1000;
            for (;;) {
                if (*tp == w0) goto found;
                if (*tp & 0x80000000) break;
                tp++;
                sz <<= 2;
            }
            sz = 0;
        found:
            if (sz != 0) {
                if ((w2 & w3 & 3) != 3) {
                    if ((w2 & 3) == 2 && (w1 & 0xFF) != asid) {
                        w2 &= ~2;
                    }
                    if ((w3 & 3) == 2 && (w1 & 0xFF) != asid) {
                        w3 &= ~2;
                    }
                }
                w0 = w1 & ~0x1FFF;
                if (w2 & w3 & 2) {
                    sz <<= 1;
                } else if (w3 & 2) {
                    w0 += sz;
                }
                D_800F6D00[k].lo = w0;
                D_800F6D00[k].hi = w0 + sz - 1;
                D_800F6D00[k].flags = 3;
            }
        }
    }
    p = D_800D05E0;
    lo = 0x80000000;
    if ((s32)p->hi >= 0) {
        do {
            p++;
        } while (p->hi < lo);
    }
    i = 0;
    sp = (u32 *)p;
    do {
        D_800F6D00[i].lo = lo;
        hi = *sp++;
        D_800F6D00[i].hi = hi;
        fl = *sp++;
        D_800F6D00[i].flags = fl;
        lo = hi + 1;
        i++;
    } while (lo != 0);
    new_var = -1;
    while (i < 16) {
        D_800F6D00[i].lo = new_var;
        D_800F6D00[i].flags = 0;
        i++;
    }
}
