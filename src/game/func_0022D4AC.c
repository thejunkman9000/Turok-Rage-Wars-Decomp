#include "b07_types.h"

extern f32 D_800C7EAC;
extern f32 D_800C7EB0;

void func_44A4C0(Actor *actor);
void func_002636D0(void *p);

void func_0022D4AC(Actor *actor)
{
    if (AT(f32, actor, 0x658) > D_800C7EAC) {
        AT(s32, actor, 0x13C8) = 1;
        AT(s32, actor, 0x1238) = -1;
        AT(s32, actor, 0x1230) = 0;
        AT(u32, actor, 0x122C) &= ~0x20;
        func_44A4C0(actor);
        AT(f32, actor, 0x50) = D_800C7EB0;
        AT(f32, actor, 0x54) = D_800C7EB0;
        AT(f32, actor, 0x58) = D_800C7EB0;
    } else {
        func_002636D0((u8 *)actor + 0x688);
        actor->brain->unk23C = 0;
        actor->brain->unk240 = 0;
    }
}
