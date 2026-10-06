#include "b23_types.h"

extern s32 D_8014D2E0[];
extern s32 D_8014D320;
extern s32 D_8014D328;

void func_002A27F8(void) {
    D_8014D320 = D_8014D320 + 1;
    D_8014D2E0[D_8014D320] = D_8014D328;
}
