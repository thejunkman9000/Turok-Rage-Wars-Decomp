#include "b01_types.h"

void func_00205494(Actor *actor, ActorState *state) {
    B01Def *def = B01_DEF(actor);
    if (state->unkCB != 0 && (def->flags14 & 4)) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
}
