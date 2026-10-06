#include "p1_types.h"
s32 func_002016DC(u8 *s) {
    u8 *p = s;
    while (*p++) {}
    return p - s;
}
