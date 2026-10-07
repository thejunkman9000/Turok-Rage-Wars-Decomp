#include "b07_types.h"

extern f32 D_800C8144;

s32 func_00222A80(Actor *actor, s32 weapon);
s32 func_0022F95C(Actor *actor);
s32 func_0022B174(Actor *actor);
void func_0022B974(Actor *actor);
void func_0022B9B4(Actor *actor);
s32 func_002301E4(Actor *actor, ActorState *state);
void func_00214178(Actor *actor, ActorState *state, s32 id);

void func_0023333C(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;

    AT(s32, state, 0x13C) = 2;
    if (func_00222A80(owner, AT(s16, owner, 0x62E)) == 0) {
        AT(s16, owner, 0x770) = func_0022F95C(owner);
        return;
    }
    if (AT(f32, actor, 0x104) >= D_800C8144) {
        if (func_0022B174(owner) == 0) {
            func_0022B974(owner);
        }
    }
    if (!(AT(u32, owner, 0x6AC) & 0x4000) || owner->unk5E4 == 0) {
        func_00214178(actor, state, 2);
        func_0022B9B4(owner);
        AT(s32, state, 0x13C) = 1;
    }
    if (func_002301E4(actor, state) != 0) {
        func_0022B9B4(owner);
    }
}
