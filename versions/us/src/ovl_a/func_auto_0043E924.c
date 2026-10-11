#include "s1009_types.h"
extern f32 D_801462E8;
extern u8 *D_800D7E04[];
extern u8 *D_800D7E08[];
extern s32 D_800E5E48;
extern u8 D_800E2328[];
extern s32 func_00442158(S10Item *a);
extern void func_00265904(char *dst, u8 *fmt, s32 a);
s32 func_auto_0043E924(S10Item *a, S10Menu *m) {
    if (D_801462E8 == 1.0f) {
        a->f14 = D_800D7E08;
    } else {
        char *s;
        a->f14 = D_800D7E04;
        s = *(char **)a->f14;
        func_00265904(s + (func_00442158(a) - 3), D_800E2328, D_800E5E48 - 5);
    }
    return 0;
}
