#include "s1009_types.h"
extern s32 D_80146914[];
extern void func_002647A8(s32 port);
extern void func_00264268(void *c);
extern void func_00264808(void *c, s32 b);
s32 func_0043E284(void *a, S10Menu *m) {
    D_80146914[0] = 0;
    func_002647A8(m->ctrl->port);
    func_00264268(m->ctrl);
    func_00264808(m->ctrl, 1);
    m->ctx->f85C = 0;
    return 1;
}
