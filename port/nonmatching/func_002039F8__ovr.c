#include "p1_types.h"

extern f32 D_800C6B38;
extern f32 D_800D2988;
void func_00214178(Actor *actor, ActorState *state, s32 arg2);
/* port: the MIPS code enters the link callback with a0..a3 exactly as this function received them;
 * forward them so a callback that reads its actor/state does not see x86 stack garbage. */
void func_002039F8(Actor *actor, ActorState *state, u32 a2, u32 a3) {
    if (state->link != NULL && state->link->cb != NULL) {
        ((void (*)(Actor *, ActorState *, u32, u32))state->link->cb)(actor, state, a2, a3);
    }
    if (actor->unkE4 == 0x40C) {
        state->unk13C += D_800D2988;
        if (state->unk13C > D_800C6B38 || state->unk12C.i <= 0) {
            func_00214178(actor, state, 0x40);
        }
    }
}
