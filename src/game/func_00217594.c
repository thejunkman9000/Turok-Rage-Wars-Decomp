#include "b04_types.h"
f32 func_00274B00(f32, f32);
void func_0024DBB0(void *, s32, s32, s32, s32, f32);
extern f32 D_800C72DC;
extern f32 D_800C72E0;
typedef struct { u32 mask; s32 val; } B04Ent;
typedef struct { u8 pad0[8]; s32 x, y, z; } B04O;
void func_00217594(B04O *o, s32 a1, u32 mask, B04Ent *e) {
    for (; e->mask != 0; e++) {
        if (mask & e->mask) {
            func_0024DBB0(o, o->x, o->y, o->z, e->val, func_00274B00(D_800C72DC, D_800C72E0));
        }
    }
}
