#include "b21_types.h"

extern DlCmd *D_80110634;
void func_0026925C(s32 a);
void func_00268CE0(s32 a);

void func_00293100(B21Game *g, u8 *col, s32 ulx, s32 uly, s32 lrx, s32 lry) {
    DlCmd *d, *d1, *d2;
    s32 x1, y1, x0, y0;
    u32 w, t, w2;
    if (col[3] != 0) {
        d1 = D_80110634++;
        d1->w0 = 0xE7000000;
        d1->w1 = 0;
        d2 = D_80110634++;
        d2->w0 = 0xE3000A01;
        d2->w1 = 0;
        func_0026925C(0x13);
        func_00268CE0(0x19);
        d = D_80110634++;
        d->w0 = 0xFA00FFFF;
        d->w1 = (col[0] << 24) | (col[1] << 16) | (col[2] << 8) | col[3];
        d = D_80110634++;
        x1 = lrx;
        if (x1 < 0) x1 = 0;
        y1 = lry;
        w = (x1 & 0x3FF) << 14;
        if (y1 < 0) y1 = 0;
        t = ((y1 & 0x3FF) << 2) | 0xF6000000;
        d->w0 = w | t;
        x0 = ulx;
        if (x0 < 0) x0 = 0;
        y0 = uly;
        w2 = (x0 & 0x3FF) << 14;
        if (y0 < 0) y0 = 0;
        d->w1 = w2 | ((y0 & 0x3FF) << 2);
    }
}
