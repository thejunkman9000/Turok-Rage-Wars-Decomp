#include "o04_types.h"
extern s32 D_80154010;
extern s32 D_80154014;
static inline s32 sub_B334(s32 a) {
    switch (a) {
    case 0:
        return 5;
    case 1:
        return 7;
    case 3:
        return 0xB;
    case 2:
        return 0x11;
    default:
        return 0;
    }
}
s32 func_0042B11C(void) {
    if (D_80154010 < 0) {
        return 1;
    }
    return D_80154014 + 1 == sub_B334(D_80154010);
}
