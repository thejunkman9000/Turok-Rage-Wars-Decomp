#include "b01_types.h"

s32 func_00204620(Actor *actor) {
    s32 v = B01_DEF(actor)->unk28;
    if (v != 0) {
        actor->flags |= 0x2000;
    } else {
        actor->flags &= ~0x2000;
        actor->flags &= ~0x100;
    }
    return v;
}
