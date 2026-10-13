#include "veu3n10_types.h"
#include "s1009_types.h"
extern void func_00265904(char *dst, u8 *fmt, s32 a);
extern s32 func_auto_00442EE0(S10Item *a);
extern VeuGlobals8208 D_801462C8;
extern s32 D_auto_800F24B8;
extern u8 D_auto_800EE978[];   /* "%3d" (resident string, stays in the ROM data blob) */
extern u8 D_auto_800E41C4[], D_auto_800E41B4[];

s32 func_auto_0043F644(S10Item *a, S10Menu *m) {
    VeuGlobals8208 *g = &D_801462C8;
    if (g->f20 == 1.0f) {
        a->f14 = D_auto_800E41C4;
    } else {
        char *s;
        a->f14 = D_auto_800E41B4;
        s = ((char **)a->f14)[g->b581];
        func_00265904(s + (func_auto_00442EE0(a) - 3), D_auto_800EE978, D_auto_800F24B8 - 5);
    }
    return 0;
}
