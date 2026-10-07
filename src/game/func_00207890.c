#include "b01_types.h"

extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, B01Actor *actor);
void func_00214178(B01Actor *actor, B01State *state, s32 event);

void func_00207890(B01Actor *actor, B01State *state) {
    state->unk37 = 0;
    func_00214178(actor, state, 0);
    if (state->unk94 == 1) {
        state->unk98 = state->unk96;
        func_00214178(actor, state, 4);
    }
    if (func_00285F28(D_8011FE88, actor) == 0) {
        actor->flags &= ~0x100;
    }
}
