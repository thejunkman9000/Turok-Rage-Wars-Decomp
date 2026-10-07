#include "b01_types.h"

extern s32 D_8011FE88[];
void func_00278DE8(B01Actor *actor, s32 flags, B01Actor *actor2);
void func_00216288(B01Actor *actor, s32 id, Vec3f pos, s32 flag);
void func_0025DE74(s32 id, f32 x, f32 y, f32 z, s32 a, s32 b);
void func_002170A0(B01Actor *actor, B01State *state, s32 kind, s32 a, s32 b);

void func_002054E0(B01Actor *actor, B01State *state) {
    B01Info *info = B01_INFO(actor->def);
    actor->flags &= 0xFFFEFFFF;
    func_00278DE8(actor, 0x40000, actor);
    if (info->unk2C == 0) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
    if (D_8011FE88[0] == 4) {
        if (info->unk34.i != -1) {
            func_0025DE74(info->unk34.h[1], actor->pos.x, actor->pos.y, actor->pos.z, 0, -1);
        }
        if (info->unk30 != -1) {
            func_00216288(actor, info->unk30, actor->pos, 0);
        }
        func_002170A0(actor, state, 8, info->unk38, info->unk3C);
    }
}
