#include "b02_types.h"

void func_00207FA0(B2Actor *actor, B2State *state) {
    state->flags |= 0x10000;
    actor->flags |= 0x2100;
    state->unk16C = 0;
}
