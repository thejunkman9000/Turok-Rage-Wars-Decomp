#include "s1009_types.h"
extern void func_00409814(void);
extern s32 func_004426E4();
extern u8 D_8014561C[];
extern u8 D_0044F100[];
s32 func_0043EB78(void *a, S10Menu *m) {
    func_00409814();
    func_004426E4(D_8014561C, D_0044F100, m->ctx, m->ctrl, 0);
    return 1;
}
