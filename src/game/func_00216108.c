#include "b03_types.h"

extern GameFlagsC D_801468A0[];
s32 func_0024E914(void);

s32 func_00216108(ActorB *a) {
    s32 v = func_0024E914();

    switch (v) {
    case 1:
    case 2:
        return 0;
    case 3:
    case 4:
        return 1;
    case 5:
    case 6:
        return 2;
    case 7:
    case 8:
        return 3;
    case 9:
    case 10:
    case 0x64:
    case 0x66:
    case 0x460:
    case 0x461:
    case 0x462:
    case 0x463:
    case 0x466:
        if (a->type == 1) {
            if (a->flags & 0x300000) {
                if (a->unk122C & 0x18400) {
                    return 9;
                }
                if (D_801468A0->unk98 != 0) {
                    if (a->stats->unk80 == 0xB) {
                        if (D_801468A0->unkA0 > 0) {
                            return 9;
                        }
                    }
                }
            }
        }
        return 4;
    case 11:
    case 12:
        return 5;
    case 13:
    case 14:
        return 6;
    case 15:
    case 16:
        return 7;
    case 17:
    case 18:
        return 8;
    case 19:
    case 20:
    case 0x67:
        return 9;
    default:
        return 3;
    }
}
