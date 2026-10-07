#include "b01_types.h"
extern u8 D_801462E5[];
extern u8 D_801462E6;
f32 func_00274B00(f32 a, f32 b);
void func_00214178(B01Actor *actor, B01State *state, s32 event);


void func_00205F18(B01Actor *actor, B01State *state) {
    B01Info *info;
    if (!(actor->def->flags14 & 0x10) || (D_801462E5[0] != 0 && D_801462E5[1] == 1)) {
        info = B01_INFO(actor->def);
        state->unk64 = func_00274B00(45.0f, 60.0f);
        state->unk124.i = 0;
        state->unk128.i = info->unk8;
        if (actor->unkE4 == 0x644 || (info->flags & 8)) {
            actor->flags &= ~0x2000;
        }
        func_00214178(actor, state, 0);
        if ((info->flags & 0x10) && D_801462E6 != 1) {
            goto clear;
        }
    } else {
clear:
        actor->flags &= ~0x100;
    }
}
