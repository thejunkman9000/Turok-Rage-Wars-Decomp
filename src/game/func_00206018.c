#include "b01_types.h"

extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, Actor *actor);

void func_00206018(Actor *actor, ActorState *state) {
    if ((func_00285F28(D_8011FE88, actor) ^ 1) == 0) {
        if (state->link != NULL) {
            if (state->link->cb != NULL) {
                state->link->cb(actor, state);
            }
        }
    }
}
