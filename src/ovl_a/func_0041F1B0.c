#include "o03_types.h"
extern O3Row D_800E3A50[17];
s32 func_0041F1B0(s32 key) {
    s32 i, found, res;
    res = 0;
    found = 0;
    for (i = 0; i < 17 && found == 0; i++) {
        if (D_800E3A50[i].f4 == key) {
            found = 1;
            res = i;
        }
    }
    return res;
}
