#include "b01_types.h"

extern u8 D_8011FE88[];
s32 func_00285F28(void *mgr, B01Actor *actor);
void func_00214178(B01Actor *actor, B01State *state, s32 event);

void func_00203908(B01Actor *actor, B01State *state) {
    B01Info *info = B01_INFO(actor->def);
    if (actor->unkE4 == 0x40C) {
        state->unk124.f = -1.57079649f;
    } else {
        state->unk124.i = 0;
    }
    state->unk128.i = 0;
    state->unk64 = info->unk6C;
    if (func_00285F28(D_8011FE88, actor) == 0) {
        if (info->flags & 0x1000) {
            actor->flags &= ~0x2000;
            actor->flags &= ~0x100;
        }
        if (info->flags & 0x800) {
            actor->flags &= ~0x100;
            func_00214178(actor, state, 0);
        } else {
            func_00214178(actor, state, 1);
        }
    } else {
        func_00214178(actor, state, 0x40);
    }
    state->unk37 = 0;
}
