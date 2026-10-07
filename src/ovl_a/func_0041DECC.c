#include "o03_types.h"
typedef struct { u8 pad[0xD8]; s32 fD8; s32 fDC; } O3X;
extern O3X *D_800E3590;
void func_0029A73C(void);
s32 func_0041DECC(void) {
    func_0029A73C();
    D_800E3590->fD8 = 5;
    D_800E3590->fDC = 4;
    return 0;
}
