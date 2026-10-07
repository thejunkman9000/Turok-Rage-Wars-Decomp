#include "o01_types.h"

extern s32 D_801534F0[];
extern s32 D_80153500[];

s32 func_00404F04(s32 i) {
    if (D_801534F0[i] != 3) {
        return -2;
    }
    return D_80153500[i];
}
