#include "b19_types.h"
void func_00284FC8(B19Owner *owner, s32 key, B19Vec3 *out) {
    B19Obj *o;
    s32 n = 0;
    out->x = 0;
    out->y = 0;
    out->z = 0;
    for (o = owner->slot[1].head; o != 0; o = o->next) {
        if ((o->id == 0x41E || o->id == 0x3EF) && o->unk12C == key && (o->flags & 0x100)) {
            out->x += o->pos.x;
            out->y += o->pos.y;
            out->z += o->pos.z;
            n++;
        }
    }
    if (n != 0) {
        out->x /= (f32)n;
        out->y /= (f32)n;
        out->z /= (f32)n;
    }
}
