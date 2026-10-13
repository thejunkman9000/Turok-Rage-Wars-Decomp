#include "veu3n10_types.h"

extern u8 D_auto_80152235, D_auto_800E3EA4[], D_auto_800E3EB4[];
extern u8 D_auto_80152236, D_auto_800E3EC4[], D_auto_800E3ED4[];
extern u8 D_auto_80152237, D_auto_800E3EE4[], D_auto_800E3EF4[];
extern u8 D_auto_80152238, D_auto_800E3F04[], D_auto_800E3F14[];
extern u8 D_auto_80152239, D_auto_800E3F24[], D_auto_800E3F34[];
extern u8 D_auto_8015223A, D_auto_800E3F44[], D_auto_800E3F54[];
extern u8 D_auto_8015223B, D_auto_800E3F64[], D_auto_800E3F74[];
extern u8 D_auto_8015223D, D_auto_800E3F84[], D_auto_800E3F94[];

s32 func_auto_0043EA40(VeuItem *a) {
    switch (a->state) {
    default:
    case 2:
        if (D_auto_80152235) a->txt = D_auto_800E3EA4; else a->txt = D_auto_800E3EB4;
        break;
    case 3:
        if (D_auto_80152236) a->txt = D_auto_800E3EC4; else a->txt = D_auto_800E3ED4;
        break;
    case 4:
        if (D_auto_80152237) a->txt = D_auto_800E3EE4; else a->txt = D_auto_800E3EF4;
        break;
    case 5:
        if (D_auto_80152238) a->txt = D_auto_800E3F04; else a->txt = D_auto_800E3F14;
        break;
    case 6:
        if (D_auto_80152239) a->txt = D_auto_800E3F24; else a->txt = D_auto_800E3F34;
        break;
    case 7:
        if (D_auto_8015223A) a->txt = D_auto_800E3F44; else a->txt = D_auto_800E3F54;
        break;
    case 8:
        if (D_auto_8015223B) a->txt = D_auto_800E3F64; else a->txt = D_auto_800E3F74;
        break;
    case 9:
        if (D_auto_8015223D) a->txt = D_auto_800E3F84; else a->txt = D_auto_800E3F94;
        break;
    }
    return 0;
}
