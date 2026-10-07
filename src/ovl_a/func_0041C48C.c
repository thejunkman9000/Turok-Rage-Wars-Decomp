#include "o03_types.h"
extern O3Pg *D_800E3518;
extern s32 D_800E28E0;
void func_002A3358();
void func_0041C2C4();
s32 func_0041C48C(void) {
    s32 a;
    s32 n;
    if (D_800E28E0 < 2) {
        a = D_800E3518->f18;
        n = D_800E3518->f14 + 1;
        D_800E3518->f14 = n;
        if (a == 0) {
            if (n < 6) return 0;
            func_002A3358();
            func_0041C2C4();
        }
    }
    return 0;
}