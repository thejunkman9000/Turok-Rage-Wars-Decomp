#include "b14_types.h"
extern u8 D_800CD390[];
extern u8 D_F641[];
extern u8 jtbl_800C6AB0[];
extern u8 D_655C[];
extern u8 D_800E2830[];
extern u8 D_3B6E[];
s32 func_002657A4(u32 a) {
    if (a >= (u32)D_800CD390 && a < (u32)D_800CD390 + (u32)D_F641) {
        return 1;
    }
    if (a >= (u32)jtbl_800C6AB0 && a < (u32)jtbl_800C6AB0 + (u32)D_655C) {
        return 1;
    }
    if (a >= (u32)D_800E2830 && a < (u32)D_800E2830 + (u32)D_3B6E) {
        return 1;
    }
    return 0;
}
