#include "o03_types.h"
extern O3Pm *D_800E4400;
extern O3Cfg D_801462C8[];
s32 func_0041AD84(s32 a);
void func_00421158(void) {
    if (func_0041AD84(D_800E4400->fC) == 0) {
        D_801462C8->flags &= 0xF7FFFFFF;
    } else {
        D_801462C8->flags |= 0x08000000;
    }
    if (func_0041AD84(D_800E4400->f10) == 0) {
        D_801462C8->flags &= 0xEFFFFFFF;
    } else {
        D_801462C8->flags |= 0x10000000;
    }
    if (func_0041AD84(D_800E4400->f14) == 0) {
        D_801462C8->flags &= ~8;
    } else {
        D_801462C8->flags |= 8;
    }
    if (func_0041AD84(D_800E4400->f18) == 0) {
        D_801462C8->flags &= 0xDFFFFFFF;
        return;
    }
    D_801462C8->flags |= 0x20000000;
}
