#include "b06_types.h"

void func_002227D0(u8 *a, u8 *b, s32 c);

void func_0022B030(u8 *a, s32 b) {
    B6F(a, s32, 0x16D0) = b;
    func_002227D0(a, a, 0x10);
}
