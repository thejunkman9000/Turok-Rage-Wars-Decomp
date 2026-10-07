#include "b07_types.h"

void func_0025DE74(s32 id, f32 x, f32 y, f32 z, void *src, s32 a5);
s32 func_002301E4(Actor *actor, ActorState *state);
void func_0022AFFC(Actor *owner);
void func_0022B180(Actor *owner);
void func_00214178(Actor *actor, ActorState *state, s32 id);

void func_00232CDC(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;

    if (state->unkCB != 0) {
        if (func_002301E4(actor, state) != 0) {
            state->unkCB = 0;
            state->unk35 = -1;
        } else {
            switch (AT(s16, owner, 0x62E)) {
            case 8:
                func_0025DE74(0xA3E, AT(f32, owner, 0x8), AT(f32, owner, 0xC), AT(f32, owner, 0x10),
                              (u8 *)owner + 8, -1);
            case 0:
            case 0xE:
                func_0022AFFC(owner);
            default:
                func_00214178(actor, state, 2);
                break;
            }
        }
        AT(s32, owner, 0x788) = 1;
        AT(s32, owner, 0x78C) = 0;
    } else {
        if (AT(s16, owner, 0x62E) == 0xC && (AT(u32, owner, 0x6AC) & 0x4000)) {
            func_0022B180(owner);
        }
    }
}
