#include "b01_types.h"

void func_00262CA8(void);

void func_00203C08(Actor *actor, ActorState *state) {
    if (state->unkCB != 0 && (actor->flags & 0x80000)) {
        func_00262CA8();
    }
}
