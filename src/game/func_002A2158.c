#include "b23_types.h"
extern s32 D_800D2BB4[];
void func_002A2158(s32 a0, u8 *s) {
    while (*s != 0) {
        s++;
    }

    D_800D2BB4[0] = 0;
    D_800D2BB4[2] = 1;
}
