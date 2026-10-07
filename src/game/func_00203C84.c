#include "b01_types.h"

extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, B01Actor *actor);
void func_00203C40(B01Actor *actor, B01State *state, s32 arg);
void func_00214178(B01Actor *actor, B01State *state, s32 event);

void func_00203C84(B01Actor *actor, B01State *state, s32 arg) {
    if (func_00285F28(D_8011FE88, actor) == 0 && state->unk34 == 0) {
        func_00203C40(actor, state, arg);
        func_00214178(actor, state, 1);
    }
}
