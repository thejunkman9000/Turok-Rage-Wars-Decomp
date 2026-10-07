#include "m01_types.h"

void func_00214178(M1Actor *a, M1State *s, s32 n);

void func_00205094(M1Actor *actor, M1State *state, M1Ev *ev) {
    M1Info *info;
    s32 ok = 0;
    s32 best;
    s32 rem;
    s32 i;
    u32 v;
    u8 lim;
    f32 f;
    info = &actor->def->info;
    best = 0;
    if (info->flags & 1) {
        ok = ((ev->flags >> 9) ^ 1) & 1;
    }
    if (info->flags & 2) {
        if (ev->flags & 0x200) ok = 1;
    }
    if (ok != 0) {
        rem = state->unk4 - ev->unk4;
        if (rem < 0) rem = 0;
        f = (f32)rem / (f32)state->unk8 * 100.0f;
        lim = 100;
        state->unk4 = rem;
        v = (u32)f;
        for (i = 0; i < 4; i++) {
            u8 b = info->b50[i];
            if (b < lim && b != 0 && (u8)v < b) {
                lim = b;
                best = i;
            }
        }
        state->unk124.i = info->unk48.b[best];
        state->unk128.i = info->unk4C.b[best];
        actor->unk1 = info->unk48.b[best];
        if (state->unk4 == 0) {
            func_00214178(actor, state, (actor->def->info.flags & 0x40) ? 2 : 1);
        }
    }
}
