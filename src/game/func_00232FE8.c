#include "b07_types.h"

typedef struct B07Row24 {
    s16 unk0;
    u8 pad2[0x16];
} B07Row24;

extern B07Row24 D_800CE8DC[];

s32 func_00222A80(Actor *actor, s32 weapon);
s32 func_0022F95C(Actor *actor);
s32 func_002301E4(Actor *actor, ActorState *state);
void func_00214178(Actor *actor, ActorState *state, s32 id);

void func_00232FE8(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;
    s32 kind = D_800CE8DC[AT(s16, owner, 0x650)].unk0;

    if (func_00222A80(owner, AT(s16, owner, 0x62E)) == 0) {
        AT(s16, owner, 0x770) = func_0022F95C(owner);
    } else {
        AT(s32, state, 0x13C) = 1;
        if (func_002301E4(actor, state) == 0 && !(actor->flags & 0x400)) {
            func_00214178(actor, state, kind);
        }
    }
}
