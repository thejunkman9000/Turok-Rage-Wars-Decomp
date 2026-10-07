#include "o03_types.h"
extern O3Words *D_800E4514;
extern O3Cfg D_801462C8[];
s32 func_0041A760(s32 a);
s32 func_0041AD84(s32 a);
void func_00423304(void) {
    D_801462C8->f1B = func_0041AD84(D_800E4514->w[1]);
    D_801462C8->f580 = func_0041AD84(D_800E4514->w[2]);
    D_801462C8->f10 = func_0041A760(D_800E4514->w[0]);
}
