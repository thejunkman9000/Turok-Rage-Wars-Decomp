#include "b01_types.h"

void func_00214178(Actor *actor, ActorState *state, s32 event);

void func_002061D8(Actor *actor, ActorState *state) {
    if (state->unkCB != 0) {
        func_00214178(actor, state, 0);
    }
}
