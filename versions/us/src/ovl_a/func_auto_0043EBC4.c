#include "s1009_types.h"
extern void func_00293808(void *a, s32 b);
extern void func_002647A8(s32 port);
extern u8 D_8011FAC0[];
extern s32 D_80154048;
s32 func_auto_0043EBC4(void *a, S10Menu *m) {
    func_00293808(D_8011FAC0, 8);
    D_80154048 = 0;
    func_002647A8(m->ctrl->port);
    return 1;
}
