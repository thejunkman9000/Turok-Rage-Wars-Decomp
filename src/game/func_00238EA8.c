#include "b08_types.h"

typedef struct ObjInit {
    s32 unk0, unk4, unk8, unkC, unk10, unk14, unk18, unk1C;
    union { s32 i; f32 f; } unk20;
    Vec3f v;
    f32 unk30;
    s32 unk34;
    f32 unk38;
    f32 unk3C;
    s32 unk40;
} ObjInit;

extern f32 D_800C8608;
extern f32 D_800C860C;
/* declared as an array: a scalar global would be loaded above the struct stores */
extern s32 D_800D2B40[];

void func_00238EA8(ObjInit *o) {
    Vec3f *p;
    f32 z;

    o->unk20.i = 0;
    z = o->unk20.f;
    o->unk0 = 1;
    o->unk4 = 0;
    o->unk8 = 0;
    o->unkC = 0;
    o->unk10 = 0;
    o->unk14 = 0;
    o->unk18 = 0;
    o->unk1C = 0;
    p = &o->v;
    p->x = p->y = p->z = z;
    o->unk30 = D_800C8608;
    o->unk34 = 0;
    o->unk38 = z;
    o->unk3C = D_800C860C;
    o->unk40 = D_800D2B40[0];
}
