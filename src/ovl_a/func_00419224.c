#include "o03_types.h"
extern s32 D_800E32E4;
extern O3Dl *D_80110634;
void func_00419224(void) {
    if (D_800E32E4 == 0) {
        D_800E32E4 = 1;
        O3_PUSH(0xE7000000, 0);
    }
}
