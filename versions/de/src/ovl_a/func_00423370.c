#include "o03_types.h"
extern O3Words *D_auto_800E04C0;
extern O3Cfg D_801462C8[];
s32 func_0041A760(s32 a);
s32 func_0041AD84(s32 a);
void func_00423370(void) {
    D_801462C8->f1F = func_0041AD84(D_auto_800E04C0->w[0x4]);
    D_801462C8->f580 = func_0041AD84(D_auto_800E04C0->w[0x5]);
    D_801462C8->f10 = func_0041A760(D_auto_800E04C0->w[0x2]);
}
