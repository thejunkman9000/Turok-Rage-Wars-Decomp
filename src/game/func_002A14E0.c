#include "b23_types.h"

u8 *func_002A14E0(u8 *s) {
    u8 *p = s;

    if (s == 0) {
        return 0;
    }
    while (*p != 0) {
        if ((u32)(*p - 0x41) < 0x1A) {
            *p = *p + 0x20;
        }
        p++;
    }
    return s;
}
