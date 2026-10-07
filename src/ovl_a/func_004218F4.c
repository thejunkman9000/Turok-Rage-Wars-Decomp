#include "o03_types.h"
extern O3Pm *D_800E4400;
extern s32 D_8010F190;
s32 func_0041A4F0(O3B60 *o);
void func_00421844();
void func_004212A4();
void func_0029A73C();
void func_00299368(s32 a);
s32 func_004218F4(void) {
    switch (func_0041A4F0(D_800E4400->bar)) {
    case 3:
        if (D_800E4400->f34 == 0) {
            func_00421844(D_800E4400);
            return 0;
        }
        if (D_8010F190 == 0x433) {
            D_800E4400->f38 = 1;
            func_004212A4(D_800E4400);
            return 0;
        }
        return 0;
    case 4:
        func_0029A73C();
        func_00299368(3);
        return 0;
    default:
        return 0;
    }
}
