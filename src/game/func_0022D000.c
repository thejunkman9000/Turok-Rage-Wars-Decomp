#include "b07_types.h"

extern f32 D_800C7E90;

void func_0022D000(Actor *actor, ActorState *state)
{
    AT(f32, actor, 0x6C0) *= D_800C7E90;
    AT(f32, actor, 0x6C4) *= D_800C7E90;
    AT(f32, state, 0x20) *= D_800C7E90;
}
