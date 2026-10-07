#include "b07_types.h"

extern s32 D_8013B29C;
extern u32 D_801462C8;

s32 func_00245774(void);
s32 func_0022C450(Actor *actor);

void func_0022BEF4(Actor *actor, s32 unused, s32 n, s32 kind)
{
    s32 v;

    if (func_00245774() != 0) {
        return;
    }
    if (func_0022C450(actor) != 0) {
        return;
    }
    if (D_8013B29C != 0) {
        return;
    }
    if (D_801462C8 & 1) {
        return;
    }
    if (AT(u16, actor, 0x650) < 2) {
        return;
    }
    if (AT(s32, actor, 0x80C) != 0) {
        n = n / 5;
    }
    if (AT(f32, actor, 0x670) > 0) {
        if (kind != 0x20) {
            return;
        }
    }
    AT(s32, actor, 0x84C) = (AT(s32, actor, 0x84C) + 1) % n;
    if (AT(s32, actor, 0x84C) != 0) {
        return;
    }
    AT(s16, actor, 0x5F4) = AT(s16, actor, 0x5F4) - 1 < 0 ? 0 : AT(s16, actor, 0x5F4) - 1;
    AT(s16, actor, 0x5F6) = AT(s16, actor, 0x5F6) - 1 < 0 ? 0 : AT(s16, actor, 0x5F6) - 1;
    AT(s16, actor, 0x5F8) = AT(s16, actor, 0x5F8) - 1 < 0 ? 0 : AT(s16, actor, 0x5F8) - 1;
}
