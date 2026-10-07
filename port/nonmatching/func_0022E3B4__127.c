#include "b07_types.h"
extern u8 *D_800D052C[];
extern s32 D_801450B8;
s32 func_0022E3B4(Actor *actor, s32 weapon, s32 id)
{
    u8 *w = D_800D052C[weapon];
    u8 **tbl;
    u8 **p;
    s32 i;
    if (actor->unk1450 == 0 && D_801450B8 == 1) {
        tbl = (u8 **)(w + 0x20);
    } else {
        tbl = (u8 **)(w + 0x2C);
    }
    for (i = 0, p = tbl; i < 3; i++, p++) {
        if (*p != NULL) {
            if (AT(s16, *p, 4) == id) {
                return 1;
            }
        } else {
            return 0;
        }
    }
    return 0;
}
