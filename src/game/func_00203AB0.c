#include "p1_types.h"
void func_00214178(Actor *actor, ActorState *state, s32 arg2);
void func_00203AB0(Actor *actor, ActorState *state) {
    if (state->unkCB != 0) {
        func_00214178(actor, state, 0x3E);
    }
}
