#include "o03_types.h"
extern O3Pm *D_800E4400;
s32 func_0029AA08(void);
void func_0029A73C();
void func_004217EC();
void func_0041A4B0(O3B60 *o, s32 v);
void func_00421158();
void func_0042144C();
s32 func_00421998(void) {
    func_0029A73C();
    if (D_800E4400->f34 == 0) {
        func_004217EC();
    } else {
        switch (func_0029AA08()) {
        case 0x3AC:
            func_0041A4B0(D_800E4400->bar, 2);
            func_00421158();
            break;
        case 0x3B6:
            func_0042144C();
            break;
        }
    }
    return 0;
}
