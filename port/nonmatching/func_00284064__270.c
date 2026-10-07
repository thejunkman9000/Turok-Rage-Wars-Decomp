
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
f32 func_00284064(B19Obj *o, f32 x, B19Q2 *q) {
    B19Parent *par = o->parent;
    register f32 xx asm("$f5");
    register f32 t asm("$f4");
    register f32 d asm("$f1");
    register f32 k asm("$f0");
    register f32 z asm("$f3");
    register f32 p asm("$f2");
    register f32 m asm("$f0");
    if (par->flags & 4) {
        xx = x;
        __asm__("" : "+f"(xx));
        t = xx;
        d = t - D_800C9F58;
        z = 0.0f;
        k = z;
        if (!(d < z)) {
            p = D_800C9F60;
            k = p;
            m = d * D_800C9F5C;
            if (!(p < m)) {
                k = z;
                if (!(d < z)) k = d * D_800C9F64;
            }
        }
        t = t * (par->pf->a + (par->pf->b - par->pf->a) * k) * D_800C9F68;
    } else {
        t = D_800C9F6C;
    }
    return t * D_800C9F78 * (q->f6C + (D_800C9F70 - q->f6C) * D_800C9F74);
}
