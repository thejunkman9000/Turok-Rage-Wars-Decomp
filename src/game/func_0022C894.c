#include "b07_types.h"

void func_002227D0(Actor *actor, ActorState *state, s32 kind);

void func_0022C894(Actor *actor, ActorState *state)
{
    if (AT(f32, actor, 0x6C0) != 0 || AT(f32, actor, 0x6C4) != 0) {
        func_002227D0(actor, state, 3);
    }
}
