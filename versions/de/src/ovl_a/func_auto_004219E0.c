#include "o03_types.h"
extern O3Pm *D_800E4400;
void func_0029A73C();
void func_004217EC();
void func_0041A4B0(O3B60 *o, s32 v);
s32 func_0041A4F0(O3B60 *o);
void func_00421158();
s32 func_auto_004219E0(void) {
    func_0029A73C();
    if (func_0041A4F0(D_800E4400->bar) != 3) {
        return 0;
    }
    if (D_800E4400->f34 == 0) {
        func_004217EC();
    } else {
        func_0041A4B0(D_800E4400->bar, 2);
        func_00421158();
    }
    return 0;
}
