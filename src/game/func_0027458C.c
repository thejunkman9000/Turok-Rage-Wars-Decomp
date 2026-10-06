#include "b17_types.h"

extern u32 D_80115DE8;

s32 func_0027458C(void) {
    D_80115DE8 = D_80115DE8 * 0xA84A5B53 + 0x58348C2D;
    return ((D_80115DE8 << 16) | (D_80115DE8 >> 16)) & 0x7FFFFFFF;
}
