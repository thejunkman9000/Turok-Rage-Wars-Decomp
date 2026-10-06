#include "b06_types.h"

void func_0022A930(u8 *a) {
    s32 v = B6F(a, s32, 0xB4);
    if (v != 0 && v != 3) {
        B6F(a, s32, 0xB4) = 3;
    }
}
