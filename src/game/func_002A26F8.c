#include "b23_types.h"

extern s32 D_800D2BD0;
extern s32 D_800D2BD4[];
extern s32 D_8014D2D0;
extern s32 D_8014D2D4;

s32 func_00252FFC(s32 n);
void func_002A2270(void);

void func_002A26F8(s32 size) {
    s32 n = (size + 7) & ~7;

    D_800D2BD4[0] = func_00252FFC(n);
    D_800D2BD4[1] = func_00252FFC(n);
    D_8014D2D4 = n;
    D_8014D2D0 = 0;
    func_002A2270();
    D_800D2BD0 = 1;
}
