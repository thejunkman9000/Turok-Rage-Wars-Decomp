#include "b16_types.h"
f32 func_802BC380(f32 x);
void func_0027335C(B16Mtx *m, Vec3f *out) {
    Vec3f r;
    r.x = m->m[0][0]; r.y = m->m[0][1]; r.z = m->m[0][2];
    out->x = func_802BC380(r.x * r.x + r.y * r.y + r.z * r.z);
    r.x = m->m[1][0]; r.y = m->m[1][1]; r.z = m->m[1][2];
    out->y = func_802BC380(r.x * r.x + r.y * r.y + r.z * r.z);
    r.x = m->m[2][0]; r.y = m->m[2][1]; r.z = m->m[2][2];
    out->z = func_802BC380(r.x * r.x + r.y * r.y + r.z * r.z);
}
