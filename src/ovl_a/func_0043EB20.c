#include "s1009_types.h"
extern void func_00264790(s32 port);
extern s32 func_004426E4();
extern u8 D_8014561C[];
extern u8 D_0044F754[];
s32 func_0043EB20(void *a, S10Menu *m) {
    func_00264790(m->ctrl->port);
    func_004426E4(D_8014561C, D_0044F754, m->ctx, m->ctrl, 0);
    return 1;
}
