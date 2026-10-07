#include "b01_types.h"
void func_00214178(B01Actor *actor, B01State *state, s32 event);


void func_00207ABC(B01Actor *actor, B01State *state) {
    B01Info *info = B01_INFO(actor->def);
    s32 ok = 1;
    if (info->flags24 & 0x10) {
        u32 f = state->flags & 0x10000;
        ok = f != 0;
    }
    if (info->flags24 & 0x100) {
        if (!(actor->flags38 & 0x40)) {
            ok = 0;
        }
    }
    if (info->flags24 & 0x400) {
        if (actor->flags38 & 0x40) {
            ok = 0;
        }
    }
    if (ok != 0) {
        if (state->unk40 >= info->unk4C) {
            func_00214178(actor, state, 1);
        }
    } else {
        state->unk40 = 0.0f;
    }
}
