#include "b01_types.h"

s32 func_002034A4(Actor *actor, ActorState *state);
void func_00214178(Actor *actor, ActorState *state, s32 event);

void func_00203AD8(Actor *actor, ActorState *state) {
    if (func_002034A4(actor, state) != 0) {
        func_00214178(actor, state, 0x3F);
    }
}
