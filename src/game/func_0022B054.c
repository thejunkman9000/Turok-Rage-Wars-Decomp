#include "b06_types.h"
s32 func_002227D0(u8 *a, u8 *b, s32 c);
void func_0022B054(u8 *a, Vec3f *v) {
    B6F(a, Vec3f, 0x16C4) = *v;
    func_002227D0(a, a, 0x11);
}
