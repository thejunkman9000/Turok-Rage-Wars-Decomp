#include "m04_types.h"

extern u8 D_800C92A0[];
void func_0025F58C();
s32 func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, void *f, void (*g)(), void *h, s32 i);
void *func_002604BC(M04Anim *a);
s32 func_002624F8(M04Anim *a);
M04Pair16 *func_0028FD94(void *n, s32 i);
s32 func_0028FE1C(void *a, void *b, s32 id, s32 *out);

void func_00261690(M04Anim *st, void *p1, void *p2, s32 flag, s32 *result, M04Anim *bak) {
    s32 cur;
    s32 nxt;
    M04Anim old;
    s32 sp40;
    s32 sp44;
    s32 sp48;
    s32 ok;
    s32 r;
    s32 a3;
    void *n;
    cur = st->f4;
    nxt = st->f6;
    if (nxt != cur && flag != 0) {
        st->fB = 1;
        old = *st;
        if (nxt == -1) {
            st->f10 = 0;
            ok = 0;
        } else {
            r = func_0028FE1C(p1, p2, nxt, &sp40);
            st->f10 = func_002518DC(0, r, r, sp40, 4, st, func_0025F58C, D_800C92A0, 0);
            if (func_002624F8(st) != 0) {
                n = func_002604BC(st);
                st->f4 = nxt;
                st->f8 = func_0028FD94(n, 0)->w6;
                st->fC = func_0028FD94(func_0028FD94(n, 3), 0)->w2;
                ok = 1;
            } else {
                ok = 0;
            }
        }
        if (ok != 0) {
            if (bak != 0) {
                *bak = old;
                bak->f4 = cur;
                bak->f6 = cur;
                bak->fB = 1;
            }
            st->f4 = nxt;
            st->f6 = nxt;
            st->f0 = 0;
            st->fA = 0;
            st->fB = 1;
            if (result != 0) {
                *result = 1;
            }
        } else {
            if (result != 0) {
                *result = 0;
            }
            if (cur != -1) {
                r = func_0028FE1C(p1, p2, cur, &sp44);
                a3 = sp44;
                goto blk20;
            }
            goto clear;
        }
    } else {
        if (result != 0) {
            *result = 0;
        }
        if (cur == -1) {
clear:
            st->f10 = 0;
            return;
        }
        r = func_0028FE1C(p1, p2, cur, &sp48);
        a3 = sp48;
blk20:
        st->f10 = func_002518DC(0, r, r, a3, 4, st, func_0025F58C, D_800C92A0, 0);
        if (func_002624F8(st) != 0) {
            n = func_002604BC(st);
            st->f4 = cur;
            st->f8 = func_0028FD94(n, 0)->w6;
            st->fC = func_0028FD94(func_0028FD94(n, 3), 0)->w2;
        }
    }
}
