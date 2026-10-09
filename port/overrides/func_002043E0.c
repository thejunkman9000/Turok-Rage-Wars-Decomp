#include "b01_types.h"

/* port: forwards a0..a3 to the link callback (see func_002039F8). */
void func_002043E0(B01Actor *actor, B01State *state, u32 a2, u32 a3) {
    B01Info *info = B01_INFO(actor->def);
    if (state->link != NULL) {
        if (state->link->cb != NULL) {
            ((void (*)(B01Actor *, B01State *, u32, u32))state->link->cb)(actor, state, a2, a3);
        }
    }
    if (state->unk34 == 0) {
        actor->unk1 = info->unkC.b[2];
        actor->unk3 = info->unkC.b[3];
    } else {
        actor->unk1 = info->unk1A;
        actor->unk3 = info->unk1B;
    }
}
