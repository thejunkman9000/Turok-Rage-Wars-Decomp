#include "p1_types.h"
extern u8 D_800CD4C4[];
void func_002043E0();
void func_00204468(Actor *actor, ActorState *state) {
    state->table = D_800CD4C4;
    state->fn108 = func_002043E0;
    state->unk124 = 0;
    state->unk128.i = 0;
    state->unk12C.i = 0;
    if (actor->def->info.flags & 1) {
        actor->flags |= 0x10000;
    } else {
        actor->flags &= ~0x10000;
    }
}
