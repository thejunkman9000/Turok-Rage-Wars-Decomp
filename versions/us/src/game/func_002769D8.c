#include "b17_types.h"

#define MX(a, b) ((a) > (b) ? (a) : (b))
#define MN(a, b) ((a) < (b) ? (a) : (b))

void func_002769D8(u8 a, u8 r, u8 g, u8 b, u8 *outr, u8 *outg, u8 *outb) {
    s32 m, k;

    if (a != 0) {
        k = 100 - a;
        m = MX(r, MX(g, b));
        *outr = (u32)((f32)(r * k + m * a) * 0.01f);
        *outg = (u32)((f32)(g * k + m * a) * 0.01f);
        *outb = (u32)((f32)(b * k + m * a) * 0.01f);
    } else {
        *outr = r;
        *outg = g;
        *outb = b;
    }
}
