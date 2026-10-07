#include "o03_types.h"
typedef struct { u8 pad[0x20]; s32 f20; } O3Q24;
extern O3Q24 *D_800E44A0;
void func_0029A73C();
s32 func_004223FC(s32 a0, s32 a1, u32 a2, s32 a3) {
    if ((a2 >> 16) == 3 && a3 == 0xB) {
        func_0029A73C();
        D_800E44A0->f20 = 1;
    }
    return 0;
}
