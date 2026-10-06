#include "b04_types.h"
extern f32 D_800C739C;
extern f32 D_800CE3CC;
typedef struct { s32 idx; s32 one; f32 f24; s32 zero; f32 f2C; } B04Ent;
typedef struct { s32 w0, w4, w8, wC; s32 w10; s32 w14; s32 w18; B04Ent ent[4]; s32 w6C; s32 w70; } B04Set;
void func_00218E98(B04Set *o) {
    s32 i;
    f32 a = D_800C739C;
    f32 b = D_800CE3CC;
    o->w0 = 0; o->w4 = 0; o->w8 = 0; o->wC = 0; o->w14 = 0;
    o->w6C = -1;
    o->w18 = 4;
    o->w70 = -1;
    for (i = 0; i < 4; i++) {
        o->ent[i].zero = 0;
        o->ent[i].f2C = b;
        o->ent[i].f24 = -(i * a);
    }
}
