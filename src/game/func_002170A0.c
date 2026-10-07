#include "b04_types.h"
f32 func_00274B00(f32, f32);
void func_0024DBB0(void *, s32, s32, s32, s32, f32);
extern f32 D_800C72C8, D_800C72CC, D_800C72D0, D_800C72D4;
typedef struct { u32 mask; s32 val; } B04Ent;
extern B04Ent D_800CE240[];
extern B04Ent D_800CE348[];
typedef struct { u8 pad0[8]; s32 x, y, z; } B04O;
void func_002170A0(B04O *o, u32 *flags, u32 bit, u32 m1, u32 m2) {
    B04Ent *e;
    if (!(*flags & bit)) {
        *flags |= bit;
        for (e = D_800CE240; e->mask != 0; e++) {
            if (m1 & e->mask)
                func_0024DBB0(o, o->x, o->y, o->z, e->val, func_00274B00(D_800C72C8, D_800C72CC));
        }
        for (e = D_800CE348; e->mask != 0; e++) {
            if (m2 & e->mask)
                func_0024DBB0(o, o->x, o->y, o->z, e->val, func_00274B00(D_800C72D0, D_800C72D4));
        }
    }
}
