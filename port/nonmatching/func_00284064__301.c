
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
    f32 t, d, k;
    if (par->flags & 4) {
        t = x;
        d = t - D_800C9F58;
        k = 0.0f;
        if (!(d < 0.0f)) {
            k = D_800C9F60;
            if (!(D_800C9F60 < d * D_800C9F5C)) {
                k = 0.0f;
                if (!(d < 0.0f)) k = d * D_800C9F64;
            }
        }
        t = t * (par->pf->a + (par->pf->b - par->pf->a) * k) * D_800C9F68;
    } else {
        t = D_800C9F6C;
    }
    return t * D_800C9F78 * (q->f6C + (D_800C9F70 - q->f6C) * D_800C9F74);
}
