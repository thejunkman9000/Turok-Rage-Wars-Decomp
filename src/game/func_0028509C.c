#include "b19_types.h"
extern f32 D_800C9F90;
f32 func_0027272C(B19Vec3 *, B19Vec3 *);
void func_0028509C(B19Owner *owner, B19Obj *obj, f32 *out) {
    B19Obj *o;
    f32 d;
    *out = D_800C9F90;
    for (o = owner->lb.head; o != 0; o = o->next2) {
        if (o->unk12C != (s32)obj && (o->flags & 0x100)) {
            d = func_0027272C(&o->pos, &obj->pos);
            if (d < *out) *out = d;
        }
    }
}
