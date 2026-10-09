/* port (passthru_fix.py): func_00217388 needs a0 a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "m01_types.h"

extern f32 D_800D2988;
void func_00217388(u32, u32);
void func_00213CF8(M1Actor *a, M1State *s);
void func_00213ED4(M1Actor *a, M1State *s);

void func_002164A8(M1Actor *actor, M1State *state) {
    if (state->unkFC != NULL && state->unkFC->unkC == -1) {
        func_00217388(actor, state);
    }
    if (state->unkCD != 0) {
        state->unkCD--;
        D_800D2988 = 0.0f;
        return;
    }
    if (actor->unk19C != 0 && actor->def != NULL) {
        if (actor->def->kind == 2) {
            state->v48 = actor->pos;
            state->f60 = actor->f6C;
        }
        state->v54 = actor->pos;
        state->f40 = state->f40 + D_800D2988;
        if (actor->flags & 0x10000) {
            func_00213CF8(actor, state);
        }
        if (state->fn108 != NULL) {
            state->fn108(actor, state);
        }
        func_00213ED4(actor, state);
        if (actor->def->kind != 2) {
            state->v48 = actor->pos;
            state->f60 = actor->f6C;
        }
    }
}
