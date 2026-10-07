#include "p4_types.h"
u8 *func_002A12E8(u8 *dst, const u8 *src) {
    u8 *p = dst;
    while (*p != 0) {
        p++;
    }
    while ((*p++ = *src++) != 0) {}
    return dst;
}
