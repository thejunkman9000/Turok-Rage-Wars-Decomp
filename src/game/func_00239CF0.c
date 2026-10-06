#include "b08_types.h"

typedef struct Obj4F {
    s32 unk0;
    f32 unk4;
} Obj4F;

extern f32 D_800C8658;

void func_00239CF0(Obj4F *o, f32 a, s32 b) {
    o->unk4 = a * D_800C8658;
    o->unk0 = b;
}
