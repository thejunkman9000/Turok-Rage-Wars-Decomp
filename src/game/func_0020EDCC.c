#include "b02_types.h"

B2Node *func_0020CFE0(B2Mgr *m, s32 key);
extern B2Mgr D_8013B364;
extern const f32 D_800C6FCC;

void func_0020EDCC(B2Ctl *ctl) {
    B2Mgr *m = &D_8013B364;
    s32 i;

    if (m != NULL) {
        for (i = 0; i < 10; i++) {
            if (ctl->a3C[i] != NULL) {
                func_0020CFE0(m, ctl->a3C[i]->owner->brain->key)->unk18 = D_800C6FCC;
            }
        }
    }
}
