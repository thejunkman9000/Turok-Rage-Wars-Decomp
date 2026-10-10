#include "b17_types.h"

s32 func_00277CC4();
void *func_0028FD94();
s32 func_002508E0();

s32 func_00278090(Box3 *q, s32 *h, WRec **out, s32 *cnt, u8 *ctx) {
    WTab *tab;
    WRec *rec;
    s32 n, ret, i, hit, j, target, v;
    s32 *t3;
    WRec **op;
    u16 *lst;
    u16 cnt16;
    s16 *sp;

    n = 0;
    ret = 0;
    if (h == 0) {
        return func_00277CC4(q, out, cnt);
    }
    tab = func_0028FD94(h, 2);
    i = tab->count;
    i--;
    if (i != -1) {
        rec = tab->r;
        do {
            if (q->mx.x > rec->box.mn.x && q->mn.x < rec->box.mx.x
                && q->mx.z > rec->box.mn.z && q->mn.z < rec->box.mx.z
                && q->mx.y > rec->box.mn.y && q->mn.y < rec->box.mx.y) {
                if (rec->bBD != 0 && (hit = 0, *ctx != 1)) {
                    t3 = func_0028FD94(h, 3);
                    if (*t3 > 0) {
                        sp = func_0028FD94(t3, i);
                        cnt16 = *(u16 *)sp;
                        sp = sp + 1;
                        target = func_002508E0(ctx, h);
                        asm("" : "+r"(hit));
                        if (hit < (s16)cnt16) {
                        j = 0;
                        do {
                            v = *sp;
                            if (v >= 0x1770) {
                                v -= 0x1770;
                            } else if (v >= 0xFA0) {
                                v -= 0xFA0;
                            } else if (v >= 0x7D0) {
                                v -= 0x7D0;
                            }
                            if (v == target) {
                                hit = 1;
                                break;
                            }
                            j++; sp++;
                        } while (j < (s16)cnt16);
                        }
                    }
                } else {
                    hit = 1;
                }
                if (hit) {
                    out[n] = rec;
                    n++;
                    if (rec->bBA != 0) {
                        ret = 1;
                    }
                    if (n == 0x40) {
                        break;
                    }
                }
            }
            rec++;
            i--;
        } while (i != -1);
    }
    *cnt = n;
    return ret;
}