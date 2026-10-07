#include "b17_types.h"

void func_00276BB4(u8 a, u8 r, u8 g, u8 b, u8 *outr, u8 *outg, u8 *outb) {
    s32 k;
    if (a != 0) {
        k = 100 - a;
        *outr = (u32)((f32)r * 0.01f * (f32)k);
        *outg = (u32)((f32)g * 0.01f * (f32)k);
        *outb = (u32)((f32)b * 0.01f * (f32)k);
    } else {
        *outr = r;
        *outg = g;
        *outb = b;
    }
}
