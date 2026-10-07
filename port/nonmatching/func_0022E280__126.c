#include "b07_types.h"

extern u8 D_8010EEB8[];
extern u8 D_8010F328[];
extern f32 D_800C7F00;

typedef struct B07Blk224 {
    u8 b[0x224];
} B07Blk224;

void func_0026369C(void *dst, void *src);
f32 func_0022ADAC(Actor *actor);

void func_0022E280(Actor *actor)
{
    void *src;
    Vec3f *v;
    void *dst;
    f32 t;

    dst = (u8 *)actor + 0x688;
    if (actor->unk1450 != 0) {
        src = D_8010EEB8;
    } else {
        src = &((B07Blk224 *)D_8010F328)[actor->unk5D4];
    }
    func_0026369C(dst, src);
    AT(s32, actor, 0x6C0) = 0;
    AT(s32, actor, 0x6C4) = 0;
    AT(s32, actor, 0x6C8) = 0;
    AT(s32, actor, 0x6CC) = 0;
    AT(s32, actor, 0x6D0) = 1;
    AT(s32, actor, 0x6D4) = 0;
    AT(s32, actor, 0x6D8) = 0;
    AT(s32, actor, 0x6DC) = 0;
    AT(s32, actor, 0x6E4) = 0;
    AT(s32, actor, 0x758) = 0;
    AT(s32, actor, 0x75C) = 0;
    AT(s32, actor, 0x11B4) = 0;
    AT(s32, actor, 0x11B8) = 0;
    AT(s32, actor, 0x708) = 0;
    AT(s32, actor, 0x70C) = 0;
    AT(s32, actor, 0x710) = 0;
    AT(s32, actor, 0x714) = 0;
    AT(s32, actor, 0x724) = 0;
    AT(s32, actor, 0x728) = 0;
    AT(s32, actor, 0x72C) = 0;
    AT(s32, actor, 0x730) = 0;
    AT(s32, actor, 0x734) = 0;
    AT(s32, actor, 0x738) = 0;
    AT(s32, actor, 0x73C) = 0;
    AT(f32, actor, 0x740) = func_0022ADAC(actor);
    AT(s32, actor, 0x744) = 0;
    v = (Vec3f *)((u8 *)actor + 0x748);
    t = AT(f32, actor, 0x744);
    v->x = v->y = v->z = t;
    AT(f32, actor, 0x754) = D_800C7F00;
    AT(f32, actor, 0x780) = t;
    AT(f32, actor, 0x784) = D_800C7F00;
    AT(Vec3f, actor, 0x6E8) = AT(Vec3f, actor, 0x8);
    AT(Vec3f, actor, 0x6F8) = AT(Vec3f, actor, 0x8);
}
