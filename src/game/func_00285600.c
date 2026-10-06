#include "b19_types.h"
extern u32 D_80115DE4;
extern f32 D_800C9FA8;
f32 func_00285600(B19Pair p) {
    s32 t0 = p.a << 16;
    s32 t1;
    u32 r;
    if (p.b == 0) return *(f32 *)&t0;
    t1 = p.b << 16;
    D_80115DE4 = D_80115DE4 * 0xA84A5B53 + 0x58348C2D;
    r = (D_80115DE4 >> 16) & 0x7FFF;
    return *(f32 *)&t0 + (f32)r * *(f32 *)&t1 * D_800C9FA8;
}
