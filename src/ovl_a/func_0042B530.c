#include "o04_types.h"
extern u8 D_80154018[];
void func_002656A8(void *p, s32 a, s32 b);
void func_0042B530(void) {
    s32 i;
    for (i = 0; i < 0x28; i++) {
        func_002656A8(D_80154018, i, 0);
    }
}
