#include "b07_types.h"
extern u8 D_801462E5[];
extern u8 D_801462D5[];
extern ActorRow400 D_80102B00[];
extern u8 *D_800E4680;
u8 func_0022F444(void *row, s32 idx);
void func_0022C100(Actor *actor)
{
    s16 r;
    if (D_801462E5[0] != 0) {
        if (*(D_801462E5 - 0x10) == 1 && actor->unk1450 == 0) {
            AT(s32, actor, 0x133C) =
                (func_0022F444(&D_80102B00[actor->unk5D4], actor->stats->unk80) >> 1) + 1;
        }
        if (D_801462D5[0] == 4) {
            if (actor->unk1450 == 0) {
                if (D_800E4680 != NULL) {
                    AT(s32, actor, 0x133C) = AT(u8, D_800E4680, 0x28);
                }
            }
        }
        r = 1;
    } else {
        r = 3;
    }
    AT(s16, actor, 0x5EA) = r;
    AT(s32, actor, 0x13C8) = 0;
}
