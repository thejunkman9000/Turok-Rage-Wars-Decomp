#include "o03_types.h"
extern O3Chr D_800E381C[][17];
s32 func_0041ECB4(s32 row, s32 ch) {
    s32 i;
    for (i = 0; i < 17; i++) {
        if (D_800E381C[row][i].ch == ch) {
            return i;
        }
    }
    return 0;
}
