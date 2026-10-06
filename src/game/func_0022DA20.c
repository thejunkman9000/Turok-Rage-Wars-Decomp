#include "b07_types.h"

void func_00225F20(Actor *actor, ActorState *state);
void func_002227D0(Actor *actor, ActorState *state, s32 kind);

void func_0022DA20(Actor *actor, ActorState *state)
{
    func_00225F20(actor, state);
    if (AT(f32, actor, 0x6C0) != 0) {
        func_002227D0(actor, state, 0x25);
    }
}
