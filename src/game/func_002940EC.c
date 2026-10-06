#include "b21_types.h"

extern s32 D_800D29C8;
s32 func_002938E8(B21Game *g, f32 a, s32 b, s32 c);

void func_002940EC(B21Game *g) {
    if (func_002938E8(g, 4.0f, 4, 4)) {
        D_800D29C8 = 0;
    }
}
