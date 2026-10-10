#include "b19_types.h"
extern f32 D_800C9F58;
extern f32 D_800C9F5C;
extern f32 D_800C9F60;
extern f32 D_800C9F64;
extern f32 D_800C9F68;
extern f32 D_800C9F6C;
extern f32 D_800C9F70;
extern f32 D_800C9F74;
extern f32 D_800C9F78;
static inline f32 Ramp2(B19Parent *par, f32 xin) {
    register f32 x asm("$f4") = xin;
    f32 d;
    f32 k;
    d = x - D_800C9F58;
    k = !(d < 0.0f) ? (!(D_800C9F60 < d * D_800C9F5C) ? (!(d < 0.0f) ? d * D_800C9F64 : 0.0f) : D_800C9F60) : 0.0f;
    {
        register f32 fb asm("$f2") = par->pf->b;
        register f32 fa asm("$f3") = par->pf->a;
        x = x * (fa + (fb - fa) * k) * D_800C9F68;
    }
    return x;
}
f32 func_00284064(B19Obj *o, f32 px, B19Q2 *q) {
    B19Parent *par = o->parent;
    register f32 x asm("$f5") = px;
    f32 t;
    if (par->flags & 4) {
        t = Ramp2(par, x);
    } else {
        t = D_800C9F6C;
    }
    {
        f32 m = q->f6C;
        return t * D_800C9F78 * (m + (D_800C9F70 - m) * D_800C9F74);
    }
}