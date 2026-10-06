#include "b08_types.h"

void func_00214178(Actor *actor, ActorState *state, s32 id);

void func_00233534(Actor *actor, ActorState *state) {
    if (state->unkCB != 0) {
        func_00214178(actor, state, 2);
    }
}
