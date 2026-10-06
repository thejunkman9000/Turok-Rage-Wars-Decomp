#include "b01_types.h"

void func_002055EC(Actor *actor, ActorState *state) {
    B01Def *def = B01_DEF(actor);
    if (state->unkCB != 0 && (def->flags14 & 0x20)) {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
}
