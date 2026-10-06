#include "b06_types.h"

extern f32 D_800C7DF0;
extern f32 D_800C7DF4;

f32 func_0022ADAC(u8 *a) {
    u8 *p = B6F(a, u8 *, 0x18);
    if (p != NULL) {
        return B6F(p, f32, 0xF4) * D_800C7DF4;
    }
    return D_800C7DF0;
}
