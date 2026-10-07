#include "b09_types.h"

extern f32 D_800C87C8;
extern f32 D_800D0648;

s32 func_0023ED54(B09Mover *m, B09Quad *h) {
    f32 v = h->t;
    s32 r;
    if (v <= 0.0f) {
        if (h->unk8 == 7) {
            return 0;
        }
        if ((u32)(h->type0 - 5) < 2 || v * m->f80 < -(D_800D0648 * D_800C87C8)) {
            return 0;
        }
    }
    r = 0;
    if (!(h->t >= m->qcopy.t)) {
        r = 1;
    }
    return r;
}
