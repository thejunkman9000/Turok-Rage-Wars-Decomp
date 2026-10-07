#include "b17_types.h"

extern u32 D_80115DE4;
extern f32 D_800C9A88;
extern f32 D_800C9A8C;

f32 func_00274B00(f32 a, f32 b) {
    u32 r;
    s32 v;
    f32 t;

    r = D_80115DE4 * 0xA84A5B53 + 0x58348C2D;
    D_80115DE4 = r;
    v = ((r << 16) | (r >> 16)) & 0x7FFFFFFF;
    t = (f32)(v % 10000) * D_800C9A88;
    return t * a + (D_800C9A8C - t) * b;
}
