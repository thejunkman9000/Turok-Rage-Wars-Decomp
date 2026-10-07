#include "o03_types.h"
void func_00419144(s32 mode) {
    if (D_80153F68 == 0) {
        mode = 0xE;
    }
    if (mode != D_800E32D0) {
        D_800E32D0 = mode;
        O3_Sync();
        if (mode == 0xD) {
            O3_PUSH(0xD7000002, 0x80008000);
        } else if (mode == 0xE) {
            O3_PUSH(0xD7000000, 0x80008000);
        }
    }
}
