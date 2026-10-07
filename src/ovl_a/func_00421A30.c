#include "o03_types.h"
extern O3Pm *D_800E4400;
void func_0029A73C();
void func_004217EC();
void func_0041A4B0(O3B60 *o, s32 v);
void func_00421158();
s32 func_00421A30(void) {
    func_0029A73C();
    if (D_800E4400->f34 == 0) {
        func_004217EC(D_800E4400);
    } else {
        func_0041A4B0(D_800E4400->bar, 2);
        func_00421158();
    }
    return 0;
}
