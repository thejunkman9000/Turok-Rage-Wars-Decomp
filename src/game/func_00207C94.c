#include "p1_types.h"
void func_00214178(Actor *actor, ActorState *state, s32 arg2);
void func_00207C94(Actor *actor, ActorState *state) {
    ActorInfo *info = &actor->def->info;
    s32 flags = info->flags24;
    s32 ok = 1;
    if (flags & 0x20) {
        u32 f = state->flags & 0x20000;
        ok = f != 0;
    }
    if ((flags & 0x200) && !(actor->flags38 & 0x40)) {
        ok = 0;
    }
    if ((info->flags24 & 0x800) && (actor->flags38 & 0x40)) {
        ok = 0;
    }
    if (ok != 0) {
        if (state->unk40 >= info->unk50) {
            func_00214178(actor, state, 3);
        }
    } else {
        state->unk40 = 0;
    }
}
