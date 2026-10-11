#include "s1009_types.h"
extern void func_00409814(void);
extern void func_0025E234(s32 a);
extern s32 func_004426E4();
extern u8 D_8014561C[];
extern u8 D_0044F0B8[];
s32 func_0043E5F4(void *a, S10Menu *m) {
    S10Ctx *ctx = m->ctx;
    func_00409814();
    func_0025E234(-1);
    func_004426E4(D_8014561C, D_0044F0B8, ctx, m->ctrl, 0);
    return 1;
}
