#include "b08_types.h"

void func_00214178(Actor *actor, ActorState *state, s32 id);
f32 func_00274878(f32 a, f32 b, s32 c);

extern f32 D_800C8168;
extern s32 D_800CF9E0;

void func_0023370C(Actor *actor, ActorState *state) {
    f32 lim;
    f32 v;

    lim = D_800C8168;
    v = func_00274878(*(f32 *)&state->unk124, lim, D_800CF9E0);
    *(f32 *)&state->unk124 = v;
    if (lim <= v) {
        func_00214178(actor, state, 2);
    }
}
