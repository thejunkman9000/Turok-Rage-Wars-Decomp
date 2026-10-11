#include "s1009_types.h"
extern void func_00264790(s32 port);
extern void func_002647A8(s32 port);
void func_0043DF84(S10Menu *m, s32 on) {
    s32 p = m->ctrl->port;
    if (on != 0) func_00264790(p);
    else func_002647A8(p);
}
