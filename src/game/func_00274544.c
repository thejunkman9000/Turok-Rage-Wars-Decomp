#include "b16_types.h"

extern u32 D_80115DE4;

s32 func_00274544(void) {
    u32 s;
    s = D_80115DE4 * 0xA84A5B53 + 0x58348C2D;
    D_80115DE4 = s;
    return ((s << 16) | (s >> 16)) & 0x7FFFFFFF;
}
