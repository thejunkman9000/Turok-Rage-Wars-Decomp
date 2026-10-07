#include "b07_types.h"
extern u8 *D_800D052C[];
extern s32 D_801450B8;
s32 func_0022E3B4(Actor *actor, s32 weapon, s32 id)
{
    u8 *w = D_800D052C[weapon];
    u8 **tbl;
    s32 i;
    if (actor->unk1450 == 0 && D_801450B8 == 1) {
        tbl = (u8 **)(w + 0x20);
    } else {
        tbl = (u8 **)(w + 0x2C);
    }
    for (i = 0; i < 3; i++, tbl++) {
        if (*tbl == NULL) {
            return 0;
        }
        if (AT(s16, *tbl, 4) == id) {
            return 1;
        }
    }
    return 0;
}
