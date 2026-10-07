#include "b07_types.h"

extern f32 D_800C7E7C;
extern f32 D_800C7E80;

void func_002227D0(Actor *actor, ActorState *state, s32 kind);
void func_0022CE68(Actor *actor, ActorState *state);

void func_0022CDAC(Actor *actor, ActorState *state)
{
    f32 y = AT(f32, actor, 0x6C4);

    if ((y < 0 && AT(f32, actor, 0x6A4) >= 0) ||
        (y > 0 && AT(f32, actor, 0x6A4) <= 0) ||
        AT(f32, actor, 0x658) >= D_800C7E7C) {
        func_002227D0(actor, state, 8);
    } else {
        AT(f32, state, 0x20) = D_800C7E80;
    }
    func_0022CE68(actor, state);
}
