#include "b24_types.h"

extern u8 D_800D2F80[];
extern u8 D_800F81F0[];
extern u8 D_800FD1F0[];
extern u8 D_8010FC40[];
extern u8 D_801462C8[];
extern u8 D_801468A0[];
extern s32 D_8014D330;

s32 func_002A8544(u32 a) {
    u32 p = a | 0x80000000;
    if ((p >= (u32)D_800D2F80 && p < (u32)(D_800D2F80 + 0x10)) || p == (u32)&D_8014D330) {
        return 0;
    }
    if (D_8014D330 != 0) {
        return 1;
    }
    if ((p >= (u32)D_8010FC40 && p < (u32)(D_8010FC40 + 0x430)) ||
        (p >= (u32)D_801462C8 && p < (u32)(D_801462C8 + 0x584)) ||
        (p >= (u32)D_800FD1F0 && p < (u32)(D_800FD1F0 + 0x5800)) ||
        (p >= (u32)D_800F81F0 && p < (u32)(D_800F81F0 + 0x5000))) {
        return 0;
    }
    if (p >= (u32)(D_801462C8 + 0x5D8) && p <= (u32)(D_801462C8 + 0x688)) {
        return 0;
    }
    return 1;
}
