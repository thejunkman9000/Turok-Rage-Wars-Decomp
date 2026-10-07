#include "b15_types.h"

typedef struct B15O {
    u8 pad0[8];
    Vec3f pos;
    u8 pad14[0x61A];
    s16 unk62E;
} B15O;

void func_00272038(Vec3f *p, f32 f, Vec3f *a, Vec3f *b);
f32 func_0024D274(B15O *o);
extern f32 D_800C9520;

s32 func_0026745C(Actor *act, Vec3f *pos) {
    Vec3f a;
    Vec3f b;
    B15O *o;
    s32 r;

    r = 0;
    if (*(u8 *)act == 1 && (act->flags & 0x300000)) {
        o = (B15O *)act->owner;
        if ((u8 *)act == (u8 *)o + 0x2E8 && (o->unk62E == 0 || o->unk62E == 0x11 || o->unk62E == 0x10)) {
            a = *pos;
            b = o->pos;
            func_00272038(pos, 0.75f, &a, &b);
            pos->y = pos->y + func_0024D274(o) * D_800C9520;
            r = 1;
        }
    }
    return r;
}
