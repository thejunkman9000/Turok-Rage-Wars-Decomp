#include "b17_types.h"

extern u32 D_80115DE4;
extern f32 D_800C9A38;

f32 func_002745D4(f32 a) {
    u32 r = D_80115DE4 * 0xA84A5B53 + 0x58348C2D;
    u32 v = (r >> 16) & 0x7FFF;
    D_80115DE4 = r;
    return (f32)v * a * D_800C9A38;
}
