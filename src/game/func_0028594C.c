#include "b19_types.h"
s32 func_00264E10(void *);
s32 func_0028594C(u8 *o) {
    s32 r = 0;
    if (func_00264E10(o + 0x20)) r = 1;
    else if (func_00264E10(o + 0x2C)) r = 1;
    return r;
}
