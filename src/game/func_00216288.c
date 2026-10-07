#include "b04_types.h"
extern f32 D_800C72B4;
extern u8 D_80121990[];
typedef struct { u8 type; u8 pad1[0x1B]; Vec3f pos; u8 pad28[0xBC]; u16 unkE4; u8 padE6[0x10A]; s32 unk1F0; u8 pad1F4[0xA8]; s32 unk29C; } B04Ent;
void func_0024E78C(void *, Vec3f, void *, void *, s32, s32);
void func_0024795C(B04Vec4 *, B04Ent *);
s32 func_0024BE70(B04Ent *);
void func_0024F468(B04Vec4 *, B04Ent *);
void func_00280094(u8 *, B04Ent *, B04Ent *, s32, s32, s32, Vec3f, B04Vec4, Vec3f, s32, s32, s32);
void func_00216288(B04Ent *o, s32 a1, Vec3f p) {
    Vec3f sp50;
    Vec3f sp60;
    B04Vec4 sp70;
    u8 sp80[8];
    B04Ent *e = NULL;
    s32 mode = 1;
    s32 extra = 0;
    func_0024E78C(o, p, &sp50, sp80, 0, 1);
    switch (o->type) {
    case 2:
    case 0:
        sp60.x = sp60.y = sp60.z = 0.0f;
        sp70.x = sp70.y = sp70.z = 0.0f;
        sp70.w = D_800C72B4;
        break;
    case 1:
        e = o;
        sp60 = e->pos;
        func_0024795C(&sp70, e);
        extra = e->unk1F0;
        if (func_0024BE70(e) == 5)
            mode = 3;
        break;
    case 3:
        sp60 = o->pos;
        func_0024F468(&sp70, o);
        break;
    }
    func_00280094(D_80121990, o, o, 0, extra, a1, sp60, sp70, sp50, 0, -1, mode);
    if (o->type == 1 && e->unkE4 == 0x40C) {
        s32 v = e->unk29C - 1;
        if (v < 0) v = 0;
        e->unk29C = v;
    }
}
