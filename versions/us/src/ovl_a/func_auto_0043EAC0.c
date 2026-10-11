#include "s1009_types.h"
extern void func_00264790(s32 port);
extern void func_00404E28(s32 port);
void func_auto_0043EAC0(S10Menu *m) {
    s32 p = m->ctrl->port;
    func_00264790(p);
    func_00404E28(p);
}
