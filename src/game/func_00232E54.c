#include "b07_types.h"

extern f32 D_800D2988;
extern f32 D_800C8114;
extern f32 D_800C8118;
extern f32 D_800C811C;
extern f32 D_800C8120;
extern f32 D_800C8124;
extern f32 D_800C8128;
extern f32 D_800C812C;

s32 func_002301E4(Actor *actor, ActorState *state);
void func_0022AFFC(Actor *owner);

void func_00232E54(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;
    u8 *p;
    f32 t;
    s32 c;

    t = AT(f32, state, 0x128) * D_800D2988;
    AT(f32, state, 0x124) = AT(f32, state, 0x124) + (t + t);
    p = AT(u8 *, owner, 0x698);
    if (AT(f32, state, 0x128) < 0) {
        if (D_800C8118 < -AT(f32, state, 0x128) * D_800C8114) {
            goto big;
        }
    } else {
        if (D_800C8120 < AT(f32, state, 0x128) * D_800C811C) {
            goto big;
        }
    }
    if (AT(f32, state, 0x128) < 0) {
        AT(f32, p, 0x168) = -AT(f32, state, 0x128) * D_800C8124;
    } else {
        AT(f32, p, 0x168) = AT(f32, state, 0x128) * D_800C8128;
    }
    goto done;
big:
    AT(f32, p, 0x168) = D_800C812C;
done:
    if (state->unkCB != 0) {
        AT(s32, state, 0x13C) = 2;
        if (func_002301E4(actor, state) != 0) {
            AT(s32, state, 0x13C) = 1;
            func_0022AFFC(owner);
        }
    }
}
