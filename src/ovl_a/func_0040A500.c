#include "o01_types.h"

extern O01Cfg *D_800E28BC;
extern O01Text D_800D77D4;
extern O01Text D_800D77D8;
extern O01Text D_800D77DC;

s32 func_0040A500(O01Item *item) {
    switch (D_800E28BC->unk90) {
    default:
    case 0:
        item->unk14 = &D_800D77D4;
        break;
    case 16:
        item->unk14 = &D_800D77D8;
        break;
    case 32:
        item->unk14 = &D_800D77DC;
        break;
    }
    return 0;
}
