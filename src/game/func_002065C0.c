#include "p1_types.h"
void func_0024B690(Actor *actor, s32 a, s32 b);
void func_002472E0(Actor *actor);
void func_002065C0(Actor *actor, ActorState *state, s32 arg2) {
    state->unk35 = -1;
    state->unkCB = 0;
    state->unk124 = arg2;
    func_0024B690(actor, arg2, 1);
    func_002472E0(actor);
}
