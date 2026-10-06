#include "p1_types.h"
extern f32 D_800C6B38;
extern f32 D_800D2988;
void func_00214178(Actor *actor, ActorState *state, s32 arg2);
void func_002039F8(Actor *actor, ActorState *state) {
    if (state->link != NULL && state->link->cb != NULL) {
        state->link->cb();
    }
    if (actor->unkE4 == 0x40C) {
        state->unk13C += D_800D2988;
        if (state->unk13C > D_800C6B38 || state->unk12C.i <= 0) {
            func_00214178(actor, state, 0x40);
        }
    }
}
