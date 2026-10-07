#include "b07_types.h"

extern f32 D_800D2988;

f32 func_00274810(f32 a, f32 b);
void func_002748E0(void *p, f32 a, f32 b);

void func_00231464(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;
    u8 *p;
    f32 t;
    f32 y;

    if (AT(s8, state, 0x34) != 4) {
        if (AT(f32, state, 0x128) > 0) {
            AT(f32, state, 0x128) = func_00274810(AT(f32, state, 0x128), 0.013613569f);
        } else {
            y = AT(f32, state, 0x124);
            AT(f32, state, 0x128) = 0;
            while (y >= 6.2831855f) {
                y = y - 6.2831855f;
                AT(f32, state, 0x124) = y;
            }
            if (AT(f32, state, 0x124) < 1.0471976f) {
                func_002748E0((u8 *)state + 0x124, 0.0f, 0.125f);
            } else if (AT(f32, state, 0x124) < 3.1415927f) {
                func_002748E0((u8 *)state + 0x124, 2.0943952f, 0.125f);
            } else if (AT(f32, state, 0x124) < 5.2359877f) {
                func_002748E0((u8 *)state + 0x124, 4.1887903f, 0.125f);
            } else {
                func_002748E0((u8 *)state + 0x124, 6.2831855f, 0.125f);
            }
        }
    }
    t = AT(f32, state, 0x128) * D_800D2988;
    AT(f32, state, 0x124) = AT(f32, state, 0x124) + (t + t);
    p = AT(u8 *, owner, 0x698);
    if (AT(f32, state, 0x128) < 0) {
        if (1.0f < -AT(f32, state, 0x128) * 1.7904929f) {
            goto big;
        }
    } else {
        if (1.0f < AT(f32, state, 0x128) * 1.7904929f) {
            goto big;
        }
    }
    if (AT(f32, state, 0x128) < 0) {
        AT(f32, p, 0x168) = -AT(f32, state, 0x128) * 1.7904929f;
    } else {
        AT(f32, p, 0x168) = AT(f32, state, 0x128) * 1.7904929f;
    }
    return;
big:
    AT(f32, p, 0x168) = 1.0f;
}
