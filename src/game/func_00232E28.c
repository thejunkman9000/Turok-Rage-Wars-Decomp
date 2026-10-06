#include "b07_types.h"

void func_0022AF64(Actor *actor, s32 a1);

void func_00232E28(Actor *actor)
{
    Actor *owner = actor->owner;

    if (owner->unk11C0 == 0) {
        func_0022AF64(owner, 0x9E2);
    }
}
