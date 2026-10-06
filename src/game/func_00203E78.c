#include "p1_types.h"
void func_00214178(Actor *actor, ActorState *state, s32 arg2);
void func_00203E78(Actor *actor, ActorState *a, ActorState *b) {
    s32 v = a->unk4 - b->unk4;
    if (v < 0) {
        v = 0;
    }
    a->unk4 = v;
    if (v == 0) {
        func_00214178(actor, a, 0x40);
    }
}
