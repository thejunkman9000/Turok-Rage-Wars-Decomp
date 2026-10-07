#include "b07_types.h"

extern f32 D_800C7ED0;
extern f32 D_800C7ED4;
extern f32 D_800C7ED8;
extern f32 D_800C7EDC;
extern f32 D_800C7EE0;
extern f32 D_800C7EE4;

void func_002227D0(Actor *actor, ActorState *state, s32 kind);
void func_002748E0(void *p, f32 a, f32 b);

void func_0022DC34(Actor *actor, ActorState *state, s32 unused, u32 *flags)
{
    s32 s1;
    f32 v;
    f32 cur;
    f32 d;
    f32 r;

    s1 = (AT(u32, state, 0x38) & 0xC0000) != 0;
    if (AT(s32, actor, 0x71C) != 0) {
        s1 = 1;
        if (AT(s16, actor, 0x650) != 4) {
            func_002227D0(actor, state, 4);
        }
    }
    v = 0;
    if (s1) {
        v = D_800C7ED0;
    }
    cur = AT(f32, actor, 0x718);
    func_002748E0(&cur, v, 0.25f);
    d = cur - AT(f32, actor, 0x718);
    if (d < 0) {
        if (-d < D_800C7ED4) {
            goto zero;
        }
    } else if (d < D_800C7ED8) {
zero:
        d = 0;
    }
    cur = AT(f32, actor, 0x718) + d;
    r = D_800C7EDC - cur;
    AT(f32, actor, 0x718) = cur;
    if (D_800C7EE0 <= r && r <= D_800C7EE4) {
        *flags |= 0x80;
    } else {
        *flags &= ~0x80;
    }
}
