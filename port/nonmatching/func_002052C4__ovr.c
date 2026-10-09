#include "b01_types.h"

/* port: forwards a0..a3 to the link callback (see func_002039F8). */
void func_002052C4(Actor *actor, ActorState *state, u32 a2, u32 a3) {
    if (state->link != NULL) {
        if (state->link->cb != NULL) {
            ((void (*)(Actor *, ActorState *, u32, u32))state->link->cb)(actor, state, a2, a3);
        }
    }
}
