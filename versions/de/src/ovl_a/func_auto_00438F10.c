#include "o05_types.h"

typedef struct { void *f0; void *f4; void *f8; void *fC; s32 f10; s32 f14; s32 f18; } O05M58A0;
extern O05M58A0 *D_800E58A0;
extern u8 D_801462E0[];
void *func_00252FFC(s32 n);
void *func_0041A300(s32 a, s32 b);
void *func_0041A600(s32 a, s32 b, s32 c);
void func_0041A76C(void *w, s32 a);
void func_0041B190(s32 a);
void *func_00419ED4(s32 a, s32 b);

s32 func_auto_00438F10(void) {
    D_800E58A0 = func_00252FFC(0x1C);
    D_800E58A0->f0 = func_0041A300(0x6A, 0x6B);
    D_800E58A0->f8 = func_0041A600(0x6D, 0x6E, 0xFF);
    func_0041A76C(D_800E58A0->f8, D_801462E0[0]);
    D_800E58A0->fC = func_0041A600(0x6F, 0x70, 0xFF);
    func_0041A76C(D_800E58A0->fC, D_801462E0[1]);
    func_0041B190(0x71);
    D_800E58A0->f4 = func_00419ED4(0x6C, 0x6E);
    D_800E58A0->f18 = 3;
    D_800E58A0->f14 = -1;
    return 0;
}
