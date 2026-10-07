#include "b01_types.h"

void func_00214178(B01Actor *actor, B01State *state, s32 event);

void func_0020612C(B01Actor *actor, B01State *state) {
    B01Info *info = B01_INFO(actor->def);
    if (info->unk4 == 0) {
        if (info->unk14 == -1) {
            state->unk40 = 0.0f;
            return;
        }
        if (info->unk16 == -1) {
            state->unk40 = 0.0f;
            return;
        }
    }
    if (state->unk124.i == info->unkA) {
        state->unk40 = 0.0f;
        return;
    }
    if ((info->flags & 1) || state->unk128.i > 0) {
        if ((info->flags & 2) && (actor->flags & 0x200)) {
            state->unk40 = 0.0f;
            return;
        }
        if (state->unk40 >= state->unk64) {
            func_00214178(actor, state, 1);
        }
    }
}
