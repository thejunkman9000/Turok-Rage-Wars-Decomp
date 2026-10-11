#include "b09_types.h"

extern f32 D_800C8720;
f32 sqrtf(f32);
void func_00240C7C(B09Quad *);
void func_00271FD8(B09V3 *, B09V3 *, B09V3 *);
void func_0027200C(B09V3 *, B09V3 *, f32);
void func_0023F42C(B09Mover *);
void func_00240250(B09Mover *);
void func_00242BE0(B09Mover *);
void func_00243910(B09Mover *);

s32 func_0023D148(B09Mover *m) {
    B09BodyDef *d = m->def;
    f32 a, b, c, dd, e, f;
    func_00240C7C(&m->qcopy);
    func_00271FD8(&m->v5C, &m->v50, &m->v44);
    m->f80 = sqrtf(m->v5C.x * m->v5C.x + m->v5C.y * m->v5C.y + m->v5C.z * m->v5C.z);
    if (m->f80 == 0.0f && m->unk4 == 0) {
        return 0;
    }
    if (m->f80 != 0.0f) {
        func_0027200C(&m->v68, &m->v5C, D_800C8720 / m->f80);
    } else {
        m->v68 = m->v5C;
    }
    a = m->v50.x;
    if (!(a <= m->v44.x)) {
        a = m->v44.x;
    }
    m->f84 = a;
    b = m->v50.x;
    if (!(m->v44.x <= b)) {
        b = m->v44.x;
    }
    m->f90 = b;
    c = m->v50.y;
    if (!(c <= m->v44.y)) {
        c = m->v44.y;
    }
    m->f88 = c;
    dd = m->v50.y;
    if (!(m->v44.y <= dd)) {
        dd = m->v44.y;
    }
    m->f94 = dd;
    e = m->v50.z;
    if (!(e <= m->v44.z)) {
        e = m->v44.z;
    }
    m->f8C = e;
    f = m->v50.z;
    if (!(m->v44.z <= f)) {
        f = m->v44.z;
    }
    m->f98 = f;
    m->box.minx = m->f84;
    m->box.maxx = m->f90;
    m->box.maxz = m->f98;
    m->box.minz = m->f8C;
    if (d->flags & 0x200000) {
        func_0023F42C(m);
    }
    if (m->f80 != 0.0f) {
        if (d->flags & 0x10000) {
            func_00240250(m);
        }
        if (d->flags & 0x4000) {
            func_00242BE0(m);
        }
        if (d->flags & 0x80000) {
            func_00243910(m);
        }
    }
    return m->qcopy.type0 != 0;
}
