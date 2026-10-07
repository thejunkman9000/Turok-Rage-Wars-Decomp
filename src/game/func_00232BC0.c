#include "b07_types.h"

extern f32 D_800C810C;

s32 func_00222A80(Actor *actor, s32 weapon);

s32 func_00232BC0(Actor *a, s32 unused, Actor *c)
{
    if (AT(f32, c, 0x11D8) > D_800C810C) {
        return 1;
    }
    if ((a->flags & 0x300000) && c->unk1450 != 0) {
        Brain *b = c->brain;
        s32 t = b->unk23C;

        b->unk23C = 0;
        return t == 0;
    }
    if (AT(u32, c, 0x6AC) & 0x2000) {
        if (AT(s32, c, 0x11B4) != 0) {
            return 1;
        }
        return func_00222A80(c, AT(s16, c, 0x62E)) == 0;
    }
    return 1;
}
