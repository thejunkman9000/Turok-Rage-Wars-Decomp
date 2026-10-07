#include "b01_types.h"

extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, B01Actor *actor);
void func_00214178(B01Actor *actor, B01State *state, s32 event);

void func_0020524C(B01Actor *actor, B01State *state) {
    if (func_00285F28(D_8011FE88, actor) == 1) {
        func_00214178(actor, state, 1);
    } else {
        func_00214178(actor, state, 0);
        actor->flags |= 0x10000;
    }
}
