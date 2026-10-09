#include "b06_types.h"

extern f32 D_800C7DF8;
f32 func_0024D274(void *obj);

/* port: func_0024D274 reads a0, which the MIPS code leaves as this function's own argument. */
f32 func_0022ADE0(u8 *a) {
    if (B6F(a, s32, 0x18) != 0) {
        return func_0024D274(a);
    }
    return D_800C7DF8;
}
