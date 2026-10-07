#include "b09_types.h"

extern f32 D_800D2988;
extern f32 D_800C8710;
extern f32 D_800C8714;
extern f32 D_800C8718;
extern f32 D_800C871C;

void func_0023CFD0(B09Mover *m) {
    B09V3 a;
    B09BodyDef *d;
    f32 dt;
    f32 c;
    f32 lim;
    f32 up;
    f32 k;
    if (m->unk2C != 0) {
        dt = D_800D2988 * D_800C8710;
        d = m->def;
        if (dt != 0.0f) {
            c = d->f14;
            c *= D_800C8714;
            lim = D_800C8718 / dt;
            if (!(c <= lim)) {
                c = lim;
            }
            up = 0.0f;
            if (m->unk28 != 0) {
                up = d->f8;
            }
            if (c == 0.0f) {
                a.x = 0.0f;
                a.y = up;
                a.z = 0.0f;
            } else {
                a.x = -m->v74.x * c;
                a.y = -m->v74.y * c + up;
                a.z = -m->v74.z * c;
            }
            k = dt * D_800C871C;
            m->v50.x = m->v50.x + (m->v74.x + a.x * k) * dt;
            m->v50.y = m->v50.y + (m->v74.y + a.y * k) * dt;
            m->v50.z = m->v50.z + (m->v74.z + a.z * k) * dt;
            m->v74.x = m->v74.x + a.x * dt;
            m->v74.y = m->v74.y + a.y * dt;
            m->v74.z = m->v74.z + a.z * dt;
        }
    }
}
