#include "b07_types.h"

extern s32 D_801450B8;
extern u8 *D_800D052C[];
extern f32 D_800C8134;

void func_0021A9A4(Actor *owner, s32 id);
void func_0022AE90(Actor *owner, s32 id);
void func_0022AF64(Actor *owner, s32 id);

void func_0023309C(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;
    Actor *o2;

    AT(s32, state, 0x64) = 0;
    if (owner->unk1450 == 0 && D_801450B8 == 1) {
        func_0021A9A4(actor->owner, 0x3F9);
    } else {
        func_0021A9A4(actor->owner, 0x4CB);
    }
    func_0022AE90(owner, 0x78A);
    func_0022AF64(owner, 0x780);
    o2 = actor->owner;
    AT(f32, state, 0x130) = AT(f32, D_800D052C[AT(s16, o2, 0x62E)], 0x18) * D_800C8134;
    if (AT(s16, o2, 0x62E) == 8 && o2->unk11C0 == 0) {
        func_0022AF64(o2, 0xA3C);
    }
}
