#include "b23_types.h"
void *func_002A1748(void *dst, s32 c, u32 n) {
    u8 *p = (u8 *)dst;
    u8 *end = p + n;
    u32 b = c & 0xFF;
    u32 w = (b << 24) | (b << 16) | (b << 8) | b;

    while (p < end && ((u32)p & 3) != 0) {
        *p++ = c;
    }
    while (p + 4 < end) {
        *(u32 *)p = w;
        p += 4;
    }
    while (p < end) {
        *p++ = c;
    }
    return dst;

}
