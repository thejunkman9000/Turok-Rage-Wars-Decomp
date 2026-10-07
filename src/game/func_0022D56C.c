#include "b07_types.h"

extern f32 D_800C7EB4;

void func_002748E0(void *p, f32 a, f32 b);
void func_44A4C0(Actor *actor);

void func_0022D56C(Actor *actor)
{
    if (AT(s32, actor, 0x850) == 0) {
        if (!(AT(u32, actor, 0x664) & 0x8000)) {
            func_002748E0((u8 *)actor + 0x72C, 1.3089970f, 0.25f);
        }
        if (AT(f32, actor, 0x658) > D_800C7EB4) {
            func_44A4C0(actor);
        }
    }
}
