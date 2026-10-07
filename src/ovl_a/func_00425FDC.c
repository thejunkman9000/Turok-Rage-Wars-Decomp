#include "o04_types.h"
typedef struct { u8 b[0x190]; } O04Row190f;
extern s32 D_8015402C;
extern O04Row190f D_80102C24[];
s32 func_00265670(void *p, s32 a);
void func_002656A8(void *p, s32 a, s32 b);
s32 func_00425FDC(s32 a) {
    s32 s2 = -1;
    s32 s0;
    O04Row190f *p;
    switch (D_8015402C) {
    case 4:
        s0 = 0;
        break;
    case 9:
        s0 = 1;
        break;
    case 0x16:
        s0 = 2;
        break;
    case 0x23:
        s0 = 3;
        break;
    default:
        s0 = -1;
        break;
    }
    if (s0 != -1) {
        p = &D_80102C24[a];
        if (func_00265670(p, s0) == 0) {
            s2 = 0x13BC;
            func_002656A8(p, s0, 1);
        }
    }
    return s2;
}
