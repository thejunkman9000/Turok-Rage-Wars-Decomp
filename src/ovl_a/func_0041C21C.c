#include "o03_types.h"
extern O3Pg *D_800E3518;
void func_00404E28(s32 i);
s32 func_00404F04(s32 i);
void func_0041C21C(void) {
    s32 i;
    s32 r;
    D_800E3518->f1C = 0;
    for (i = 0; i < 4; i++) {
        func_00404E28(i);
        r = func_00404F04(i);
        if (r == -1) { D_800E3518->f1C = 1; return; }
        if (r >= 0) { if (r == 0) { D_800E3518->f1C = 1; return; } }
        else if (r < -2) { if (r >= -4) { D_800E3518->f1C = 1; return; } }
    }
}
