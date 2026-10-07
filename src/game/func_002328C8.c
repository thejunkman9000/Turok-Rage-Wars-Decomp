#include "b07_types.h"

extern u8 *D_800D052C[];
extern f32 D_800C8104;

void func_0022AF64(Actor *actor, s32 a1);

void func_002328C8(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;

    AT(f32, state, 0x130) = AT(f32, D_800D052C[AT(s16, owner, 0x62E)], 0x18) * D_800C8104;
    if (AT(s16, owner, 0x62E) == 5 && owner->unk11C0 == 0) {
        func_0022AF64(owner, 0x46A);
    }
}
