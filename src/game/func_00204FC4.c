#include "b01_types.h"

s32 func_00204FC4(B01Actor *actor, B01State *state, f32 scale) {
    if (actor->unkE6 == 1) {
        return 1;
    }
    if (actor->unk108 != (s8)state->unkCA) {
        goto zero;
    }
    if (actor->unk10A != (s8)state->unkCA) {
        goto zero;
    }
    if (state->unkCB != 0 && !(actor->flags & 0x400)) {
        return 1;
    }
    if (actor->unk10C < 3 && (actor->flags & 0x400)) {
        if ((f32)actor->unk12C * scale <= actor->unk134) return 1;
        return 0;
    }
    if ((f32)actor->unk10C * scale <= actor->unk104) return 1;
zero:
    return 0;
}
