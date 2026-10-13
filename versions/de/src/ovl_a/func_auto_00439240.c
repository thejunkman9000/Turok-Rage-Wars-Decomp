#include "o05_types.h"

typedef struct { void *f0; void *f4; } O05M58A4;
extern O05M58A4 *D_800E58A4;
extern u8 D_801462E0[];
void *func_00252FFC(s32 n);
void *func_0041A600(s32 a, s32 b, s32 c);
void func_0041A76C(void *w, s32 a);
void func_0041B190(s32 a);

s32 func_auto_00439240(void) {
    D_800E58A4 = func_00252FFC(8);
    D_800E58A4->f0 = func_0041A600(0x1D1, 0x1D2, 0xFF);
    func_0041A76C(D_800E58A4->f0, D_801462E0[0]);
    D_800E58A4->f4 = func_0041A600(0x1D3, 0x1D4, 0xFF);
    func_0041A76C(D_800E58A4->f4, D_801462E0[1]);
    func_0041B190(0x1CF);
    return 0;
}
