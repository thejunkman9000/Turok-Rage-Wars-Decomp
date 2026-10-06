#include "b07_types.h"
s32 func_00265670(void *p, s32 a1);
s32 func_0022F4CC(u8 *p, s32 kind)
{
    s32 r;
    if (kind == 0x10) {
        r = 1;
    } else if (kind == 0x11) {
        r = 1;
    } else {
        r = func_00265670(p + 0x79, kind);
    }
    return r;
}
