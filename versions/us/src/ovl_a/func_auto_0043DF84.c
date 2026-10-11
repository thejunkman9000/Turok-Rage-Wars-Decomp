/* US v1.0 ROM 0x1A1F84 = US v1.1 src/ovl_a/func_0043DF84.c unchanged, renamed */
#include "s1009_types.h"
extern void func_00264790(s32 port);
extern void func_002647A8(s32 port);
void func_auto_0043DF84(S10Menu *m, s32 on) {
    s32 p = m->ctrl->port;
    if (on != 0) func_00264790(p);
    else func_002647A8(p);
}
