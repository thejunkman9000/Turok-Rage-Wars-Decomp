#include "b23_types.h"
void func_002A01A0(Mtx4f *m, Vec3f *out, Vec3f *in, s32 n) {
    s32 i;
    f32 x, y, z;
    for (i = 0; i < n; i++) {
        x = in[i].x;
        y = in[i].y;
        z = in[i].z;
        out[i].x = m->m[0][0] * x + m->m[1][0] * y + m->m[2][0] * z + m->m[3][0];
        out[i].y = m->m[0][1] * x + m->m[1][1] * y + m->m[2][1] * z + m->m[3][1];
        out[i].z = m->m[0][2] * x + m->m[1][2] * y + m->m[2][2] * z + m->m[3][2];
    }

}
