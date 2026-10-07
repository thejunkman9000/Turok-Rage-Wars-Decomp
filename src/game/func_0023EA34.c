#include "b09_types.h"

extern f32 D_800C87C4;
extern f32 D_800D0648;
s32 func_002412C0(B09Quad *, B09V3 *, B09V3 *, f32 *);
s32 func_00241604(B09Quad *, void *, f32, B09V3 *);
void func_00272038(B09V3 *, f32, B09V3 *, B09V3 *);

static inline s32 can_hit(B09Mover *m, B09Quad *h) {
    f32 v = h->t;
    s32 r;
    if (v <= 0.0f) {
        if (h->unk8 == 7) {
            return 0;
        }
        if ((u32)(h->type0 - 5) < 2 || v * m->f80 < -(D_800D0648 * D_800C87C4)) {
            return 0;
        }
    }
    r = 1;
    if (h->t >= m->qcopy.t) {
        r = 0;
    }
    return r;
}

s32 func_0023EA34(B09Mover *m, B09Quad *q, void *a2, f32 a3, s32 copy) {
    B09V3 *hit;
    if (func_002412C0(q, &m->v44, &m->v50, &q->t) == 0) {
        return 0;
    }
    if (!can_hit(m, q)) {
        return 0;
    }
    hit = &q->hit;
    func_00272038(hit, q->t, &m->v44, &m->v50);
    if (func_00241604(q, a2, a3, hit) == 0) {
        return 0;
    }
    if (copy != 0) {
        m->qcopy = *q;
    }
    return 1;
}
