#include "b07_types.h"

extern s32 D_801468F4;
extern u8 D_80121990[];

s32 func_00222A80(Actor *actor, s32 weapon);
s32 func_002831FC(void *tbl, Actor *actor);

s32 func_00230048(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;
    s32 r;
    f32 zero = 0.0f;

    if (AT(f32, state, 0x130) > zero) {
        return 0;
    }
    if (func_00222A80(owner, AT(s16, owner, 0x62E)) == 0) {
        return 0;
    }
    if (AT(u8, owner->stats, 0x8F) == 1) {
        if (D_801468F4 != 0) {
            return 0;
        }
    }
    if (AT(f32, owner, 0x11D8) > zero) {
        return 0;
    }
    if (AT(s32, owner, 0x11B4) != 0) {
        return 0;
    }
    switch (AT(s16, owner, 0x62E)) {
    case 11:
        r = AT(u32, owner, 0x6AC) & 0x4000 ? 0 : 1;
        break;
    case 18:
        r = AT(s32, owner, 0x788) == 2 ? 1 : 0;
        break;
    case 9:
        r = 0;
        if (AT(f32, state, 0x148) > 0) {
            if (AT(s32, state, 0x13C) == 2) {
                break;
            }
        }
        if (AT(s16, owner, 0x5F6) < 50) {
            if (AT(s32, state, 0x13C) == 2) {
                break;
            }
        }
        r = 1;
        if (AT(s16, owner, 0x5F6) < 10) {
            if (AT(s32, state, 0x13C) == 1) {
                r = 0;
            }
        }
        break;
    case 12:
        r = func_002831FC(D_80121990, owner) < 3 ? 1 : 0;
        break;
    case 1:
        r = AT(s32, state, 0x144) == 0 ? 0 : 1;
        break;
    default:
        r = 1;
        break;
    }
    return r;
}
