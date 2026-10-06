#include "b07_types.h"

void func_44ACCC(Actor *actor);
void func_002227D0(Actor *actor, Actor *state, s32 kind);

void func_00232DE4(Actor *actor)
{
    Actor *owner = actor->owner;

    func_44ACCC(owner);
    if (AT(s16, owner, 0x650) == 0x27) {
        func_002227D0(owner, owner, 2);
    }
}
