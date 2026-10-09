#include "b10_types.h"

extern f32 D_800C8A14;
extern f32 D_800C8A18;
extern f32 D_800C8A1C;
extern f32 D_800C8A20;
extern f32 D_800D2988;
s32 func_0024E61C();
void func_0024D860(f32 *loc, B10Obj *o);
s32 func_0024E28C(B10Obj *o);
void func_002743F0(f32 *a, f32 *loc);
void func_00270D40(f32 *a, f32 t, f32 *b, f32 *loc);

void func_00246FF4(B10Obj *o) {
    f32 loc[4];
    u32 fl;
    u32 mask;
    s32 r;
    s32 s;
    register f32 t __asm__("$f0");
    f32 k;
    fl = o->flags100;
    mask = fl & 0x300000;
    if (fl & 1) {
        return;
    }
    r = func_0024E61C();
    if (o->p14 == 0) {
        return;
    }
    func_0024D860(loc, o);
    s = o->p14->h2 & 1;
    if (func_0024E28C(o) == 0) {
        return;
    }
    if (s) {
        loc[0] = loc[1] = loc[2] = 0.0f;
        loc[3] = D_800C8A14;
    }
    if (mask) {
        if ((!(o->flags100 & 0x1000) && r) || s) {
            func_002743F0(&o->f5C, loc);
        }
    } else {
        if (r && !(o->flags100 & 0x1000)) {
            t = D_800D2988;
            t *= D_800C8A18;
        } else {
            t = D_800D2988;
            t *= D_800C8A1C;
        }
        func_00270D40(&o->f5C, (D_800C8A20 < t) ? D_800C8A20 : t, &o->f5C, loc);
    }
}