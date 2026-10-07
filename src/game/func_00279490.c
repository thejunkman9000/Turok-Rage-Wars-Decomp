#include "b17_types.h"

extern Ent2E8 *D_8011FFC0;
extern s32 D_8013B294;
s32 func_00204308(Ent2E8 *e, u8 *p, s32 flag);

s32 func_00279490(Rec14 *r, s32 flag) {
    Ent2E8 *e;

    if (r->wA == D_8013B294) {
        if (flag != 0) {
            e = &D_8011FFC0[r->w4];
            if (r->b11 == 10) {
                if (r->b12 == 1) {
                    return func_00204308(e, &e->f170, flag);
                }
            }
        }
    }
    return 1;
}
