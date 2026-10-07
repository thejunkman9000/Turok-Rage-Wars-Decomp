#include "o03_types.h"
extern O3Pl4 D_80146398[4];
s32 func_0041EB34(void) {
    s32 i, n, r;
    O3Pl4 *p = D_80146398;
    n = 0;
    for (i = 0; i < 4; i++) {
        if (p->f78 == 1) {
            n++;
        }
        p++;
    }
    r = 0;
    switch (n) {
    case 1:
        r = 3;
        break;
    case 2:
        r = 2;
        break;
    case 3:
        r = 1;
        break;
    }
    return r;
}
