#include "o03_types.h"
extern O3Words *D_800E4518;
extern O3Cfg D_801462C8[];
s32 func_0041A760(s32 a);
s32 func_0041AD84(s32 a);
void func_00423370(void) {
    D_801462C8->f1B = func_0041AD84(D_800E4518->w[0x15]);
    D_801462C8->f580 = func_0041AD84(D_800E4518->w[0x16]);
    D_801462C8->f10 = func_0041A760(D_800E4518->w[0x14]);
}
