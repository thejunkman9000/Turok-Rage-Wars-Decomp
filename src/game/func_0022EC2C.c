#include "b07_types.h"

extern f32 D_800C7F78;
extern f32 D_800C7F7C;
extern u32 D_800CE47C;

void func_0022EC2C(Actor *actor)
{
    s32 c = 0;
    f32 x;

    if (AT(s32, actor, 0x86C) == 0x1144) {
        c = AT(s8, actor, 0x10E) == 0;
    }
    if (actor->unkE4 == D_800CE47C) {
        AT(s32, actor, 0x86C) = 0x8A2;
        return;
    }
    if (c == 0) {
        x = AT(f32, actor, 0x6C0);
        if (D_800C7F78 <= x) {
            AT(s32, actor, 0x86C) = 0x8A2;
        } else if (x <= D_800C7F7C) {
            AT(s32, actor, 0x86C) = 0x8A7;
        } else {
            AT(s32, actor, 0x86C) = 0x14;
        }
    }
}
