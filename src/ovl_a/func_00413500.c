#include "o02_types.h"
typedef struct { u8 b0; u8 b1; u8 pad2[0xE]; s32 f10; s32 f14; s32 f18; s32 f1C; } S_func_00413500;
void func_00254784(s32 v);
void func_002A1748(void *p, s32 v, s32 n);
void func_002A1724(s32 d, s32 s, s32 n);
s32 func_00252FFC(s32 n);
s32 func_00413728(S_func_00413500 *s);
s32 func_0041371C(S_func_00413500 *s);
s32 func_00413500(S_func_00413500 *d, S_func_00413500 *s) {
    s32 n;
    if (d->b1 & 1) {
        func_00254784(d->f18);
    }
    if (d->b1 & 2) {
        if (d->f10 > 0) {
            func_00254784(d->f14);
        }
    }
    func_002A1748(d, 0, 0x20);
    *d = *s;
    if (d->f10 == 0) d->f14 = 0;
    d->b1 = 1;
    if (d->f14 != 0) d->b1 = 3;
    n = func_00413728(s);
    d->f18 = func_00252FFC(n);
    if (d->f18 == 0) {
        return 1;
    } else {
        func_002A1724(d->f18, s->f18, n);
        if (s->f10 != 0) {
            n = func_0041371C(s);
            d->f14 = func_00252FFC(n);
            if (d->f14 == 0) {
                func_00254784(d->f18);
                func_002A1748(d, 0, 0x20);
                return 1;
            } else {
                func_002A1724(d->f14, s->f14, n);
                return 0;
            }
        }
        return 0;
    }
}
