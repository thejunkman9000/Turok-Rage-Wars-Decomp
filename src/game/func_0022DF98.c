#include "b07_types.h"

extern u8 *D_800D052C[];
extern s32 D_801468F4;
extern f32 D_800C7EF4;
extern f32 D_800C7EF8;

void func_00219480(void *p, Actor *actor);
void func_002748E0(void *p, f32 a, f32 b);

void func_0022DF98(Actor *actor)
{
    f32 f = 0.0f;
    u8 *q;

    if (AT(s16, D_800D052C[AT(s16, actor, 0x62E)], 0x8) > 0 && AT(s32, actor, 0x7E8) != 0 &&
        (D_801468F4 == 0 || AT(u8, actor->stats, 0x8F) == 0)) {
    } else {
        q = (u8 *)actor + 0x878;
        AT(s32, actor, 0x7E8) = 0;
        if (AT(s32, q, 0xB4) != 0 && AT(s32, q, 0xB4) != 3) {
            AT(s32, q, 0xB4) = 3;
        }
    }
    if (actor->unk5E4 != 0) {
        if (AT(s32, actor, 0x7E8) != 0) {
            f = D_800C7EF4;
            AT(s32, actor, 0x7E8) = 1;
        }
    }
    AT(f32, actor, 0x7F0) = f;
    func_00219480((u8 *)actor + 0x878, actor);
    func_002748E0((u8 *)actor + 0x7EC, f, 0.5f);
    if (f == 0.0f) {
        if (AT(f32, actor, 0x7EC) < D_800C7EF8) {
            AT(f32, actor, 0x7EC) = 0.0f;
        }
    }
}
