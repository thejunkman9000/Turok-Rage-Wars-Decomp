#include "b02_types.h"

B2Rec *func_0020C994(B2Mgr *m, s32 idx);
s32 func_0020F55C(u16 id);
s32 func_0020F57C(u16 id);
extern B2Mgr D_8013B364;
extern const f32 D_800C6FD4;

void func_0020EEA4(B2Ctl *ctl) {
    B2Mgr *m = &D_8013B364;
    B2Node *n;
    B2Rec *r;

    for (n = m->head; n != NULL; n = n->next) {
        r = func_0020C994(m, n->id);
        if (r->flags & 1) {
            if (func_0020F55C(r->id) || func_0020F57C(r->id)) {
                n->unk18 += D_800C6FD4;
            }
        }
    }
}
