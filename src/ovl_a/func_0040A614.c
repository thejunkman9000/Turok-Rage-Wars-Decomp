#include "o01_types.h"

extern O01Cfg *D_800E28BC;
void LevelIdToWorld(s32 id);

s32 func_0040A614(O01Item *item) {
    LevelIdToWorld(D_800E28BC->unk24);
    return 0;
}
