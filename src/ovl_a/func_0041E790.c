#include "o03_types.h"
extern O3Plr D_80153F80[3];
extern s32 D_800E37B8[][5];
s32 func_0041E790(void) {
    s32 total, pts, i, n, res, j, k;
    total = 0;
    pts = 0;
    for (i = 0; i < 3; i++) {
        if (D_80153F80[i].id >= 0) {
            switch (D_80153F80[i].type) {
            case 0:
                pts = 5;
                break;
            case 1:
                pts = 10;
                break;
            case 2:
                pts = 20;
                break;
            }
            total += pts;
        }
    }
    n = 0;
    for (j = 0; j < 3; j++) {
        if (D_80153F80[j].id >= 0) {
            n++;
        }
    }
    res = 4;
    if (n <= 0) {
        return 0;
    }
    for (k = 0; k < 5; k++) {
        if (D_800E37B8[k][n - 1] >= total) {
            res = k;
            break;
        }
    }
    return res;
}
