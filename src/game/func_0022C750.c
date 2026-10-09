#include "b07_types.h"
void func_002227D0(Actor *actor, ActorState *state, s32 kind);
static inline s32 chk(Actor *actor)
{
    if (AT(s16, actor, 0x650) == 0x15 || AT(s16, actor, 0x650) == 0x13 || AT(s16, actor, 0x650) == 0x14) {
        return 1;
    }
    return 0;
}
s32 func_0022C750(Actor *actor, ActorState *state)
{
    if (chk(actor)) {
        return 0;
    }
    if (!(AT(u32, AT(u8 *, state, 0x18), 0x14) & 1)) {
        goto fail;
    }
    if (AT(s16, actor, 0x650) == 0x26 || (AT(u32, actor, 0x664) & 0x8000)) {
        return 0;
    }
    if (AT(u32, state, 0x38) & 0x80) {
        goto body;
    }
fail:
    return 0;
body:
    AT(u32, state, 0x38) |= 0x100;
    func_002227D0(actor, state, 0xF);
    return 1;
}
