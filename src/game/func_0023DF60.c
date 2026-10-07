#include "b09_types.h"

extern f32 D_800C8780;
extern f32 D_800D0648;
void func_0027200C(B09V3 *, B09V3 *, f32);
void func_00271FA4(B09V3 *, B09V3 *, B09V3 *);
s32 func_002412C0(B09Quad *, B09V3 *, B09V3 *, f32 *);
void func_00272038(B09V3 *, f32, B09V3 *, B09V3 *);
s32 func_002406C0(B09Quad *, B09V3 *, f32);

static inline s32 can_hit(B09Mover *m, B09Quad *h) {
    f32 v = h->t;
    s32 r;
    if (v <= 0.0f) {
        if (h->unk8 == 7) {
            return 0;
        }
        if ((u32)(h->type0 - 5) < 2 || v * m->f80 < -(D_800D0648 * D_800C8780)) {
            return 0;
        }
    }
    r = 1;
    if (h->t >= m->qcopy.t) {
        r = 0;
    }
    return r;
}

s32 func_0023DF60(B09Mover *m, B09V3 *off, f32 scale, B09Quad *q, s32 copy) {
    B09V3 a;
    B09V3 b;
    B09V3 d;
    B09V3 c;
    B09V3 *hit;
    if (off != NULL) {
        func_0027200C(&d, (B09V3 *)&q->nx, -scale);
        func_00271FA4(&d, &d, off);
    } else {
        d.x = 0.0f;
        d.y = 0.0f;
        d.z = 0.0f;
    }
    func_00271FA4(&a, &m->v44, &d);
    func_00271FA4(&b, &m->v50, &d);
    if (func_002412C0(q, &a, &b, &q->t) == 0) {
        return 0;
    }
    if (!can_hit(m, q)) {
        return 0;
    }
    func_00272038(&c, q->t, &a, &b);
    if (func_002406C0(q, &c, scale) == 0) {
        return 0;
    }
    hit = &q->hit;
    func_00272038(hit, q->t, &m->v44, &m->v50);
    if (copy != 0) {
        m->qcopy = *q;
    }
    return 1;
}
