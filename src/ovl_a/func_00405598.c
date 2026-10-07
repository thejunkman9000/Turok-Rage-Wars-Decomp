#include "o01_types.h"

extern s32 D_801534F0[];
extern s32 D_80153500[];

s32 func_00405598(s32 i) {
    if (D_801534F0[i] != 3) {
        return 0;
    }
    return D_80153500[i] == -4;
}
