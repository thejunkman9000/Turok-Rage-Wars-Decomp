#include "b02_types.h"

void func_00214178(B2Actor *actor, B2State *state, s32 evt);
extern f32 D_800C6C90;
extern f32 D_800D2988;

void func_00207BB8(B2Actor *actor, B2State *state) {
    B2Info *info = &actor->def->info;
    u32 f = info->flags24;
    s32 ok = 1;
    u32 t;

    if (f & 0x10000) {
        t = actor->flags38 & 0x40;
        ok = t == 0;
    }
    if ((f & 0x4000) && (actor->flags38 & 0x40) == 0) {
        ok = 0;
    }
    if (actor->flags38 & 8) {
        ok = 0;
    }
    if (ok) {
        state->unk64 = state->unk64 + D_800D2988 / info->unk38;
    }
    if (state->unk64 >= D_800C6C90) {
        func_00214178(actor, state, 2);
    }
}
