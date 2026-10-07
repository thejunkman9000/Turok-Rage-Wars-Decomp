#include "b09_types.h"

extern f32 D_800C8784;
extern f32 D_800C8788;
extern f32 D_800D0648;
f32 sqrtf(f32);
void func_00272038(B09V3 *, f32, B09V3 *, B09V3 *);

static inline s32 can_hit(B09Mover *m, B09Quad *h) {
    f32 v = h->t;
    s32 r;
    if (v <= 0.0f) {
        if (h->unk8 == 7) {
            return 0;
        }
        if ((u32)(h->type0 - 5) < 2 || v * m->f80 < -(D_800D0648 * D_800C8788)) {
            return 0;
        }
    }
    r = 1;
    if (h->t >= m->qcopy.t) {
        r = 0;
    }
    return r;
}

s32 func_0023E168(B09Mover *m, B09V3 *c, f32 r, f32 ylo, f32 yhi, s32 chky, B09Quad *q, s32 copy) {
    B09V3 d;
    B09V3 u;
    B09V3 w;
    f32 len;
    f32 inv;
    f32 along;
    f32 disc;
    f32 t;

    d.x = c->x - m->v44.x;
    d.z = c->z - m->v44.z;
    if (d.x * m->v5C.x + d.z * m->v5C.z < 0.0f) {
        return 0;
    }
    len = sqrtf(m->v5C.x * m->v5C.x + m->v5C.z * m->v5C.z);
    if (len == 0.0f) {
        return 0;
    }
    inv = D_800C8784 / len;
    u.x = m->v5C.x * inv;
    u.z = m->v5C.z * inv;
    along = d.x * u.x + d.z * u.z;
    w.x = d.x - u.x * along;
    w.z = d.z - u.z * along;
    disc = r * r - (w.x * w.x + w.z * w.z);
    if (!(disc > 0.0f)) {
        return 0;
    }
    t = (along - sqrtf(disc)) * inv;
    q->t = t;
    if (!can_hit(m, q)) {
        return 0;
    }
    func_00272038(&q->hit, q->t, &m->v44, &m->v50);
    if (chky == 0 || (!(ylo < q->hit.y) && !(q->hit.y < yhi))) {
        if (copy != 0) {
            q->kind = 1;
            q->v[0] = q->hit;
            q->ny = 0.0f;
            q->nx = q->v[0].x - c->x;
            q->nz = q->v[0].z - c->z;
            m->qcopy = *q;
        }
        return 1;
    }
    return 0;
}
