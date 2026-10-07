#include "b01_types.h"

void func_002043E0(B01Actor *actor, B01State *state) {
    B01Info *info = B01_INFO(actor->def);
    if (state->link != NULL) {
        if (state->link->cb != NULL) {
            if (state) { state->link->cb(); } else { state->link->cb(); }
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
