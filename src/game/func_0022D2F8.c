#include "b07_types.h"
extern u8 D_800CED30[];
extern f32 D_800D2988;
extern f32 D_800C7EA4;
extern B07Game D_801468A0[];
void func_002227D0(Actor *actor, Actor *state, s32 kind);
void func_0022D2F8(Actor *actor)
{
    f32 t, k;
    s32 kind;
    actor->flags &= ~0x800000;
    AT(s32, actor, 0x1C) = 0;
    AT(s32, actor, 0x20) = 0;
    AT(s32, actor, 0x24) = 0;
    AT(s32, actor, 0x11D8) = 0;
    AT(s32, actor, 0x11FC) = 0;
    actor->flags |= 0x1000000;
    if (AT(u8 *, actor, 0x13B4) == D_800CED30) {
        AT(s32, actor, 0x86C) = 0x5E24;
    } else {
        AT(s32, actor, 0x86C) = 1;
    }
    t = AT(f32, actor, 0x860) + D_800D2988;
    k = D_800C7EA4;
    AT(f32, actor, 0x860) = t;
    if (k < t || (D_801468A0->unk28 != 0 && D_801468A0->unk1C != 0)) {
        if (D_801468A0->unk28 != 0) {
            if (D_801468A0->unk1C == 0) {
                func_002227D0(actor, actor, 0x14);
            } else {
                func_002227D0(actor, actor, 0x13);
            }
        } else {
            func_002227D0(actor, actor, 0x13);
        }
    }
}
