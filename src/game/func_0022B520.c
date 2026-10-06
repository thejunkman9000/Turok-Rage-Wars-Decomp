#include "b06_types.h"

void func_0022B520(u8 *a) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        B6F(a, s32, 0x124C + i * 0x18) = 0;
    }
}
