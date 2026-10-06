#include "b04_types.h"
extern f32 D_800C733C;
extern f32 D_800CE38C;
typedef struct { f32 f28; s32 z2C; f32 f30; s32 pad34[3]; } B04Ent2;
typedef struct { s32 w0, w4, w8, wC; s32 w10; s32 w14; s32 w18; u8 pad1C[0xC]; B04Ent2 ent[36]; s32 w388; s32 w38C; s32 w390; } B04Set3;
#define W(o, off) (*(s32 *)((u8 *)(o) + (off)))
void func_0021836C(B04Set3 *o) {
    s32 i;
    f32 a = D_800C733C;
    f32 b = D_800CE38C;
    o->w0 = 0; o->w4 = 0; o->w8 = 0; o->wC = 0; o->w14 = 0;
    W(o, 0x37C) = -1;
    W(o, 0x380) = 1;
    o->w388 = -1;
    o->w18 = 0;
    o->w38C = 0;
    o->w390 = -1;
    for (i = 0; i < 36; i++) {
        o->ent[i].z2C = 0;
        o->ent[i].f30 = b;
        o->ent[i].f28 = -(i * a);
    }
}
