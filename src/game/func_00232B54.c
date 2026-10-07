#include "b07_types.h"

s32 func_002301E4(Actor *actor, ActorState *state);
void func_00214178(Actor *actor, ActorState *state, s32 id);

void func_00232B54(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;

    AT(s32, owner, 0x788) = 1;
    AT(s32, owner, 0x794) = 0;
    AT(s32, owner, 0x78C) = 0;
    AT(s32, state, 0x124) = 0;
    AT(s32, state, 0x128) = 0;
    if (state->unkCB != 0) {
        if (func_002301E4(actor, state) == 0) {
            func_00214178(actor, state, 2);
        }
    }
}
