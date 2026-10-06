#include "b23_types.h"

extern s32 D_800E28D8;

s32 func_0029A958(void);
s32 func_00411E4C(s32 a);
void func_002A3478(s32 a, s32 b);

void func_002A3318(void) {
    if (D_800E28D8 == 1) {
        func_002A3478(func_00411E4C(func_0029A958()), 0);
    }
}
