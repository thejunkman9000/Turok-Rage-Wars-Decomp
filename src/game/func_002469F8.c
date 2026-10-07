#include "b10_types.h"

extern u8 D_800C8954[];
s32 **func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u8 *h, s32 i);
void func_002536F4(s32 a, s32 **p);
B10Nd2 *func_0028FD94(s32 *n, s32 i);
s32 func_00265508(s32 *tab, s32 a, s32 key);
void func_002798CC(B10Lst *l);
void func_002798D4(B10Lst *l, s16 v, s32 a);
s16 func_00279918(B10Lst *l);

s32 func_002469F8(B10Obj *o, s32 key, s32 skip) {
    B10Lst l;
    s32 **r;
    B10Nd2 *node;
    s32 *tab;
    s32 *p;
    s32 cnt;
    s32 i;
    s32 start;
    if (o->flags100 & 0x40000) {
        r = func_002518DC(0, o->fC4, o->fC4, o->fD0, 0, 0, 0, D_800C8954, 1);
        if (r) {
            node = func_0028FD94(*r, 1);
            tab = (s32 *)((u8 *)node + 8);
            cnt = node->cnt;
            i = func_00265508(tab, o->bE6, key);
            if (i != -1) {
                start = i;
                while (i > 0 && tab[i - 1] == key) {
                    i--;
                }
                func_002798CC(&l);
                if (skip == -1) {
                    while (i < cnt && tab[i] == key) {
                        func_002798D4(&l, i++, 10);
                    }
                } else {
                    while (i < cnt && tab[i] == key) {
                        if (skip != i) {
                            func_002798D4(&l, i, 10);
                        }
                        i++;
                    }
                }
                if (l.h0 == 0) {
                    func_002798D4(&l, start, 10);
                }
                i = func_00279918(&l);
            }
            func_002536F4(0, r);
            return i;
        }
        return -1;
    }
    return -1;
}
