#include "b07_types.h"

extern f32 D_800C7E4C;

void func_002227D0(Actor *actor, ActorState *state, s32 kind);

s32 func_0022C7E8(Actor *actor, ActorState *state)
{
    if (AT(s32, actor, 0x7E8) != 0) {
        return 0;
    }
    if (AT(f32, actor, 0x6E4) > D_800C7E4C) {
        return 0;
    }
    if (AT(u32, state, 0x38) & 0xC0000) {
        return 0;
    }
    if (!(AT(u32, AT(u8 *, state, 0x18), 0x14) & 2)) {
        return 0;
    }
    if (!(AT(u32, actor, 0x6B0) & 0x10)) {
        return 0;
    }
    if (AT(f32, actor, 0x11D8) <= 0) {
        func_002227D0(actor, state, 5);
        return 1;
    }
    return 0;
}
