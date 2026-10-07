#include "o03_types.h"
extern s32 D_800E3510;
extern s32 D_8014ADA0;
void func_002A338C(void);
void func_0029A73C(void);
void func_00299368(s32 a);
void func_0041BF10();
void func_0041C2C4(void) {
    D_800E3510++;
    if (D_800E3510 >= 4) {
        func_002A338C();
        func_0029A73C();
        func_00299368(2);
        D_8014ADA0 = 1;
        return;
    }
    func_0041BF10();
}
