#include "b08_types.h"

u32 func_002337C0(void *p);

s32 func_00239E38(u8 *o) {
    u32 a, b, c;
    s32 r;

    a = func_002337C0(o + 0x18);
    b = func_002337C0(o + 0x2C);
    c = func_002337C0(o + 0x40);
    r = 0;
    if (a != 0 && b != 0) {
        r = c > 0;
    }
    return r;
}
