#include "b01_types.h"

extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, Actor *actor);
void func_00214178(Actor *actor, ActorState *state, s32 event);

void func_00204BD0(Actor *actor, ActorState *state) {
    if ((func_00285F28(D_8011FE88, actor) ^ 1) == 0) {
        func_00214178(actor, state, 0);
    } else {
        func_00214178(actor, state, 1);
    }
}
