#include "b23_types.h"

extern s32 D_800D2B70;

s32 func_002A11E8(void) {
    D_800D2B70 = D_800D2B70 * 0x343FD + 0x269EC3;
    return (D_800D2B70 >> 16) & 0x7FFF;
}
