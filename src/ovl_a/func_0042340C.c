#include "o03_types.h"
extern O3Words *D_800E4510;
s32 func_0041A4F0(s32 a);
void func_0029A73C();
void func_00299368(s32 a);
void func_0029A8A8();
s32 func_0042340C(void) {
    s32 a;
    switch (func_0041A4F0(D_800E4510->w[0])) {
    case 3:
        break;
    case 4:
        func_0029A73C();
        a = D_800E4510->w[8];
        if (a != -1) {
            func_00299368(a);
        } else {
            func_0029A8A8();
        }
        break;
    }
    return 0;
}
