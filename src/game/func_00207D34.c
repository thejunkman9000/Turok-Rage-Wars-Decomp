#include "b02_types.h"

void func_00278DE8(B2Actor *a, s32 mask, B2Actor *b);

void func_00207D34(B2Actor *actor, B2State *state) {
    B2Info *info = &actor->def->info;

    func_00278DE8(actor, 0x20000, actor);
    if ((info->flags24 & 0x80) == 0) {
        state->flags &= ~0x20000;
    }
}
