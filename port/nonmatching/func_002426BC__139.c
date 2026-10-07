#include "b10_types.h"

extern void *D_80103FCC;
extern f32 D_800C8850;
extern u8 D_801040F0[];
f32 func_00241718(B10Dc *w, s32 x, s32 z);
f32 func_0024E454(B10Obj *o);
f32 func_0024D388(B10Obj *o);
f32 func_0024D274(B10Obj *o);
f32 func_0024E410(B10Obj *o);
s32 func_0024490C(B10Obj *o, Vec3f pos, Vec3f p, u8 *ctx, f32 a, f32 b, f32 c, f32 d);

void func_002426BC(B10A *a, s32 arg1, B10Obj *o, B10Dc *w) {
    B10Sc scratch;
    Vec3f p;
    void *saved;
    f32 h, fa, fb, fc, fd;
    saved = D_80103FCC;
    D_80103FCC = &scratch;
    h = func_00241718(w, o->u8, o->u10);
    o->u34 = arg1;
    fa = func_0024E454(o);
    fb = func_0024D388(o);
    fc = func_0024D274(o);
    fd = func_0024E410(o);
    h += D_800C8850;
    p.x = *(f32 *)&o->u8;
    p.y = h;
    p.z = *(f32 *)&o->u10;
    if (func_0024490C(o, *(Vec3f *)&o->u8, p, D_801040F0, fa, fb, fc, fd)) {
        a->dc = *w;
        a->f3C |= 8;
        o->f38 |= 0x10;
    } else {
        o->fC = p.y;
        if (o->v1C.y < 0.0f) {
            o->v1C.y = 0.0f;
        }
        a->f3C |= 0x20;
        if (o->type == 1 && (o->flags100 & 0x300000)) {
            a->f3C |= 0x40;
        }
        o->f38 = (o->f38 & ~3) | 2;
    }
    D_80103FCC = saved;
}
