#include "b07_types.h"

extern f32 D_800C7EFC;

void func_00273930(Actor *actor, f32 v);

void func_0022E0A0(Actor *actor, u8 *obj)
{
    u8 *cfg = AT(u8 *, obj, 0x1C);
    s32 v = AT(s32, obj, 0x4);
    Actor *owner;
    f32 x;

    if (v >= AT(s8, cfg, 0x18) && v <= AT(s8, cfg, 0x19)) {
        owner = AT(Actor *, obj, 0x8)->owner;
        x = -AT(f32, owner, 0x724);
        if (AT(s16, owner, 0x650) == 0xF) {
            x += D_800C7EFC;
        }
        x = x / (f32)AT(s8, cfg, 0x1A);
        func_00273930(actor, x);
    }
}
