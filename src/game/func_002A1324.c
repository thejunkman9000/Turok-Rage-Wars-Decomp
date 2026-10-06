#include "b23_types.h"

u8 *func_002A1324(u8 *dst, u8 *src, s32 n) {
    u8 *p = dst;
    u8 c;

    while (*p++ != 0) {
    }
    p--;
    while (n-- != 0) {
        c = *src++;
        *p++ = c;
        if (c == 0) {
            return dst;
        }
    }
    *p = 0;
    return dst;
}
