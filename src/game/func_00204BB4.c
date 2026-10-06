#include "b01_types.h"

extern u8 D_800CD5D0[];
void func_00204C34(Actor *actor, ActorState *state);

void func_00204BB4(Actor *actor, ActorState *state) {
    state->table = D_800CD5D0;
    state->fn108 = func_00204C34;
}
