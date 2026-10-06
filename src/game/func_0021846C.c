#include "b04_types.h"
extern f32 D_800D2988;
typedef struct { u8 pad0[4]; f32 unk4; u8 pad8[0x374]; s32 unk37C; } B04Obj;
s32 func_0021846C(B04Obj *o, B04Act *p) {
    if (o->unk4 > 0.0f) {
        o->unk4 = o->unk4 - D_800D2988;
        return 0;
    }
    if (p->wpn->flagsB0 & 0x8000)
        return 0;
    o->unk37C = -1;
    return 1;
}
