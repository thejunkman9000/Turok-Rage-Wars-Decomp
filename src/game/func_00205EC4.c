#include "b01_types.h"

extern u8 D_800CD79C[];
void func_00206018(Actor *actor, ActorState *state);

void func_00205EC4(Actor *actor, ActorState *state) {
    B01Def *def = B01_DEF(actor);
    state->table = D_800CD79C;
    state->fn108 = func_00206018;
    if (actor->unkE4 == 0x644 || (def->flags14 & 8)) {
        actor->flags &= ~0x2000;
    }
}
