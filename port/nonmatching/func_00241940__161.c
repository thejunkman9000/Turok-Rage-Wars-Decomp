#include "b09_types.h"

extern f32 D_800C8840;
extern f32 D_800C8844;
extern f32 D_80115DEC;
f32 cosf(f32);
f32 sinf(f32);
f32 func_0024D274(s32);
f32 func_0024D388(s32);
f32 func_0024E410(s32);
void func_0026F690(u8 *, u8 *, u8 *);
void func_002729B4(u8 *, f32 *, f32 *, s32);
void func_002734B8(u8 *, s32, s32, s32);
void func_002736B8(u8 *, s32);
void func_00274108(u8 *, u8 *, u8 *);
void func_002742B4(u8 *, u8 *);

void func_00241940(B09XObj *o, f32 *out, B09YObj *p, s32 h) {
    B09XDef *d = (B09XDef *)(o->def18 + 0x14);
    u8 *w = o->w170;
    u8 m10[0x40];
    u8 m50[0x40];
    u8 m90[0x40];
    s32 rot[4];
    u8 mE0[0x10];
    f32 a;
    f32 b;
    f32 c;
    f32 ft1;
    f32 ft1f;
    f32 ft2;
    f32 ylo;
    f32 x0;
    f32 yhi;
    f32 zhi;
    f32 x1;
    f32 zlo;
    f32 k;
    f32 k2;
    f32 sn;

    if (h != 0) {
        a = func_0024D388(h);
        b = func_0024D274(h);
        c = func_0024E410(h);
    } else {
        b = 0.0f;
        a = b;
        c = b;
    }
    ylo = c - b;
    if (d->mode != 1) {
        k = D_800C8840;
        ft2 = d->f10 + c;
        ft1 = d->fC * k + a * k;
        ft1f = d->f14 * k + a * k;
    } else {
        ft1f = d->f8 + a;
        ft2 = d->f10 + c;
        ft1 = ft1f;
    }
    ylo = d->f1C + ylo;
    x0 = d->f18 - ft1;
    yhi = d->f1C + ft2;
    zhi = d->f20 + ft1f;
    x1 = d->f18 + ft1;
    zlo = d->f20 - ft1f;
    out[0] = x0;
    out[1] = yhi;
    out[2] = zhi;
    out[3] = x1;
    out[4] = yhi;
    out[5] = zhi;
    out[6] = x1;
    out[7] = yhi;
    out[8] = zlo;
    out[9] = x0;
    out[10] = yhi;
    out[11] = zlo;
    out[12] = x0;
    out[13] = ylo;
    out[14] = zhi;
    out[15] = x1;
    out[16] = ylo;
    out[17] = zhi;
    out[18] = x1;
    out[19] = ylo;
    out[20] = zlo;
    out[21] = x0;
    out[22] = ylo;
    out[23] = zlo;
    func_002736B8(m50, *(s32 *)(w + 0x134));
    k2 = D_800C8844;
    sn = sinf(o->f6C * k2);
    rot[0] = 0;
    ((f32 *)rot)[1] = sn;
    rot[2] = 0;
    D_80115DEC = sn;
    ((f32 *)rot)[3] = cosf(o->f6C * k2);
    func_00274108(mE0, (u8 *)rot, o->v5C);
    func_002742B4(mE0, m90);
    func_0026F690(m10, m50, m90);
    func_002734B8(m10, o->w8, o->wC, o->w10);
    func_002729B4(m10, out, out, 8);
    if (d->flags & 1) {
        ylo = p->f54 - p->f10;
        out[13] = ylo;
        out[16] = ylo;
        out[19] = ylo;
        out[22] = ylo;
    }
}
