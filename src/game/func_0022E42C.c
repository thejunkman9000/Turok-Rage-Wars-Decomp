#include "b07_types.h"

extern f32 D_800C7F04;
extern u8 D_80104030[];

f32 func_0024D274(Actor *actor);
void func_00243A80(Actor *actor, f32 x, f32 y, f32 z, void *tbl);

s32 func_0022E42C(Actor *actor, Vec3f *p)
{
    B07Blk50 save;
    s32 moved;

    save = *(B07Blk50 *)actor;
    AT(f32, actor, 0xC) += func_0024D274(actor) * D_800C7F04;
    AT(f32, actor, 0xC) += AT(f32, actor, 0x70);
    func_00243A80(actor, p->x, p->y, p->z, D_80104030);
    moved = p->x != AT(f32, actor, 0x8) || p->y != AT(f32, actor, 0xC) || p->z != AT(f32, actor, 0x10);
    *p = AT(Vec3f, actor, 0x8);
    *(B07Blk50 *)actor = save;
    return moved;
}
