#include "o04_types.h"
extern O04ModeS53C0 *D_800E53C0;
extern s32 D_800D15E0;
extern f32 D_800D15F0[];
extern f32 D_800E1B3C;
extern f32 D_800E1B40;
void func_004399D0(void *p);
void func_0042D46C(void) {
    if (D_800E53C0->unk32C != -1 && D_800E53C0->unk328 != 0) {
        D_800D15E0 = 1;
        D_800D15F0[0] = D_800E1B3C;
        func_004399D0(D_800E53C0->unk20);
        D_800D15F0[0] = D_800E1B40;
        D_800D15E0 = 0;
    }
}
