#include "b01_types.h"
extern u8 D_801462E5[];
extern u8 D_801462E6;
f32 func_00274B00(f32 a, f32 b);
void func_00214178(B01Actor *actor, B01State *state, s32 event);

void func_00205F18(B01Actor *actor, B01State *state) {
    B01Actor *a2;
    B01Info *new_var;
    B01Info *info;

    a2 = actor;
    new_var = (B01Info *)(((u8 *)a2->def) + 0x14);
    if (!(a2->def->flags14 & 0x10) || (D_801462E5[0] != 0 && D_801462E5[1] == 1)) {
        if (state) {
            state->unk64 = func_00274B00(45.0f, 60.0f);
            info = new_var;
            state->unk124.i = 0;
            state->unk128.i = info->unk8;
        } else {
            info = new_var;
            state->unk64 = func_00274B00(45.0f, 60.0f);
            state->unk124.i = 0;
            state->unk128.i = info->unk8;
        }
        if (a2->unkE4 == 0x644 || (info->flags & 8)) {
            a2->flags &= ~0x2000;
        }
        func_00214178(a2, state, 0);
        if ((info->flags & 0x10) && D_801462E6 != 1) {
            goto clear;
        }
    } else {
clear:
        a2->flags &= ~0x100;
    }
}
