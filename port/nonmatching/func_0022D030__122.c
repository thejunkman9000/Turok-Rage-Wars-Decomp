#include "b07_types.h"

extern u8 D_800CE88C[];
extern u8 D_800CE8A4[];
extern u32 D_800CE47C;
extern f32 D_800C7E94;
extern f32 D_800C7E98;
extern f32 D_800C7E9C;

void func_002231B0(Actor *actor, ActorState *state, void *tbl);
void func_002238BC(Actor *actor, ActorState *state, void *tbl);
void func_002227D0(Actor *actor, ActorState *state, s32 kind);

void func_0022D030(Actor *actor, ActorState *state)
{
    s32 c;
    s32 r;
    f32 x;

    AT(s16, actor, 0x650) = 0xD;
    if (AT(f32, actor, 0x6C8) != 0) {
        AT(s16, actor, 0x650) = 0xE;
    }
    func_002231B0(actor, state, D_800CE88C);
    func_002238BC(actor, state, D_800CE8A4);
    c = 0;
    if (AT(s32, actor, 0x86C) == 0x1144) {
        c = AT(s8, actor, 0x10E) == 0;
    }
    if (actor->unkE4 == D_800CE47C) {
        AT(s32, actor, 0x86C) = 0x8A2;
    } else if (c == 0) {
        x = AT(f32, actor, 0x6C0);
        if (D_800C7E94 <= x) {
            AT(s32, actor, 0x86C) = 0x8A2;
        } else if (!(x <= D_800C7E98)) {
            AT(s32, actor, 0x86C) = 0x14;
        } else {
            AT(s32, actor, 0x86C) = 0x8A7;
        }
    }
    if (!(AT(u32, state, 0x38) & 0x20000)) {
        if (AT(f32, actor, 0x658) > D_800C7E9C) {
            func_002227D0(actor, state, 3);
        }
    }
}
