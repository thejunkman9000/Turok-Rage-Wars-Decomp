#include "b01_types.h"

extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, Actor *actor);

void func_00203C40(Actor *actor, void *state, s32 arg) {
    if (func_00285F28(D_8011FE88, actor) == 0) {
        actor->flags |= 0x2100;
    }
}
