#include "b19_types.h"
extern u8 D_80104030[];
B19Box *func_002392DC(B19Obj *);
s32 func_00243A80(B19Box *, f32, f32, f32, void *);
s32 func_00284C1C(B19Box *a, B19Obj *o) {
    B19Box save;
    B19Box *t = func_002392DC(o);
    s32 r;
    if (t != 0 && *(s32 *)((u8 *)o + 0x24) == 0) {
        save = *t;
        t->pos = *(B19Vec3 *)&o->unk128;
        r = func_00243A80(t, a->pos.x, a->pos.y, a->pos.z, D_80104030);
        *t = save;
    } else {
        save = *a;
        save.pos = *(B19Vec3 *)&o->unk128;
        r = func_00243A80(&save, a->pos.x, a->pos.y, a->pos.z, D_80104030);
    }
    return r == 0;
}
