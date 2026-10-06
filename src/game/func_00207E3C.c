#include "b02_types.h"

void func_00214178(B2Actor *actor, B2State *state, s32 evt);

void func_00207E3C(B2Actor *actor, B2State *state) {
    actor->flags |= 0x2100;
    state->flags |= 0x10000;
    func_00214178(actor, state, 1);
}
