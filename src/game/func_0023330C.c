#include "b07_types.h"

extern f32 D_800C8140;

void func_00214178(Actor *actor, ActorState *state, s32 id);

void func_0023330C(Actor *actor, ActorState *state)
{
    AT(f32, state, 0x148) = D_800C8140;
    func_00214178(actor, state, 8);
}
