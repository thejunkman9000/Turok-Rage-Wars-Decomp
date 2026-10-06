#include "b02_types.h"

void func_00207C68(B2Actor *actor, B2State *state) {
    if ((actor->def->info.flags24 & 0x80) == 0) {
        state->flags &= ~0x20000;
    }
}
