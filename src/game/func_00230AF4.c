#include "b07_types.h"
extern f32 D_800C8004;
s32 func_0022AB10(Actor *owner, s32 weapon);
void func_00214178(Actor *actor, ActorState *state, s32 id);
void func_00230AF4(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;
    s32 w;
    if (!(AT(u32, owner, 0x6AC) & 0x2000)) {
        w = AT(s16, owner, 0x62E);
        switch (w) {
        case 2:
            if (AT(s32, state, 0x13C) == 1) {
                func_00214178(actor, state, 5);
            } else if (AT(s32, state, 0x13C) == 2) {
                func_00214178(actor, state, 9);
            } else {
                goto zero;
            }
            break;
        case 0:
zero:
            if (AT(f32, state, 0x40) > D_800C8004) {
                func_00214178(actor, state, 5);
            } else {
                func_00214178(actor, state, 9);
            }
            break;
        default:
            if (func_0022AB10(owner, w) == 1) {
                func_00214178(actor, state, 7);
            } else {
                func_00214178(actor, state, 5);
            }
            break;
        }
    }
}
