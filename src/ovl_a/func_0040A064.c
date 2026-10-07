#include "o01_types.h"

extern u8 D_00451820[];
extern u8 D_00451844[];
extern u8 D_00451868[];
extern u8 D_0045188C[];

u8 *func_0040A064(s32 unused, s32 sel) {
    switch (sel) {
    default:
    case 0:
        return D_00451820;
    case 1:
        return D_00451844;
    case 2:
        return D_00451868;
    case 3:
        return D_0045188C;
    }
}
