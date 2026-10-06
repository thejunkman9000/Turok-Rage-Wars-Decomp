#include "p4_types.h"
s32 func_002A1238(const u8 *s) {
    const u8 *p = s;
    while (*p++) {}
    return p - s - 1;
}
