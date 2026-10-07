#include "b07_types.h"
extern u8 D_800CED30[];
void func_44ACCC(Actor *actor);
void func_0022D280(Actor *actor)
{
    AT(s32, actor, 0x860) = 0;
    func_44ACCC(actor);
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
}
