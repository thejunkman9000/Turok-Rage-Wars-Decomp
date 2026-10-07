#include "o03_types.h"
extern O3Plr D_80153F80[3];
s32 func_0041EC2C(void) {
    s32 total, pts, i;
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
    return total;
}
