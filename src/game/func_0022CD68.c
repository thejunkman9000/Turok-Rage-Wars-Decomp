#include "b07_types.h"

extern f32 D_800C7E70;
extern f32 D_800C7E74;
extern f32 D_800C7E78;

void func_0022CD68(Actor *actor, ActorState *state)
{
    if (AT(f32, actor, 0x6A4) < 0) {
        AT(f32, actor, 0x6C4) = D_800C7E70;
    } else {
        AT(f32, actor, 0x6C4) = D_800C7E74;
    }
    AT(f32, state, 0x20) = D_800C7E78;
}
