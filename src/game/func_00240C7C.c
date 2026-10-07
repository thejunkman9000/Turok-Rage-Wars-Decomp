#include "b09_types.h"

extern f32 D_800C882C;

void func_00240C7C(u8 *p) {
    f32 g = D_800C882C;
    *(s32 *)(p + 0x0) = 0;
    *(s32 *)(p + 0x54) = 0;
    *(s32 *)(p + 0x58) = -1;
    *(f32 *)(p + 0xCC) = g;
}
