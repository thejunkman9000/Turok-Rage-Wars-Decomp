#include "b04_types.h"
extern f32 D_800C73B4;
extern f32 D_800CE3CC;
typedef struct { s32 idx; s32 one; f32 f24; s32 zero; f32 f2C; } B04Ent;
typedef struct { u8 pad0[0x1C]; B04Ent ent[4]; } B04Set;
void func_00219124(B04Set *o) {
    s32 i;
    f32 a = D_800C73B4;
    f32 b = D_800CE3CC;
    *(s32*)((u8*)o + 0x6C) = -1;
    for (i = 0; i < 4; i++) {
        o->ent[i].idx = i;
        o->ent[i].one = 1;
        o->ent[i].zero = 0;
        o->ent[i].f24 = i * a;
        o->ent[i].f2C = b;
    }
}
