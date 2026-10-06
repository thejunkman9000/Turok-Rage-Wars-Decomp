#include "b08_types.h"

void func_0022AF64(Actor *actor, s32 id);

void func_0023355C(Actor *actor) {
    actor = actor->owner;
    if (actor->unk11C0 == 0) {
        func_0022AF64(actor, 0x80C);
    }
}
