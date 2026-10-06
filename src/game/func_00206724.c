#include "b01_types.h"

void func_00206724(Actor *actor, ActorState *state) {
    if (state->link != NULL) {
        if (state->link->cb != NULL) {
            state->link->cb();
        }
    }
}
