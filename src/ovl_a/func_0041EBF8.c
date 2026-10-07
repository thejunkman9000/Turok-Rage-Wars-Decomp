#include "o03_types.h"
extern s32 D_800E37B8[][5];
s32 func_0041EBF8(s32 a, s32 b) {
    s32 i = a - 1;
    if (a <= 0) return 0;
    return D_800E37B8[b][i];
}
