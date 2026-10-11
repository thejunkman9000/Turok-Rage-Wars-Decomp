#include "s1009_types.h"
extern S10State D_801462C8[];
extern S10Ctrl D_8010F328[];
s32 func_0043E158(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_8010F328[i].active != 0) {
            if (D_801462C8->rec[i].b0 == 0) return 0;
            n++;
        }
    }
    return n;
}
