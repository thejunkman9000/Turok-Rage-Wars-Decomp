#include "o03_types.h"
extern O3Row D_800E3A50[17];
s32 func_0041F248(s32 key) {
    s32 i, found, res;
    res = 0;
    found = 0;
    for (i = 0; i < 17 && found == 0; i++) {
        if (D_800E3A50[i].f0 == key) {
            found = 1;
            res = D_800E3A50[i].f4;
        }
    }
    return res;
}
