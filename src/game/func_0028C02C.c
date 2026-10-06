#include "b20_types.h"

typedef struct { u8 pad0[2]; u16 flags; } Obj;

s32 func_00275B80(Obj *o, f32 x, f32 z);
f32 func_00275E44(Obj *o, f32 x, f32 z);
f32 func_002752CC(Obj *o, f32 x, f32 z);
Obj *func_002866F8(u8 *tbl, Vec3f *p);
extern u8 D_8011FE88[];

Obj *func_0028C02C(Obj *o, Vec3f *p) {
    f32 lo;
    f32 hi;
    if (o != 0 && func_00275B80(o, p->x, p->z) != 0) {
        if (!(o->flags & 0x40)) {
            return o;
        }
        lo = func_00275E44(o, p->x, p->z);
        hi = func_002752CC(o, p->x, p->z);
        if (lo <= p->y && p->y <= hi) {
            return o;
        }
    }
    return func_002866F8(D_8011FE88, p);
}
