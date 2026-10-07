#include "b17_types.h"

RecW *func_0028FD94(s32 a, s32 n);

void func_00278BAC(s32 a, s32 n, Vec3f *pts) {
    RecW *r;
    s32 i, w;

    r = func_0028FD94(a, 1);
    if (r->u4 != 0) {
        for (i = 0; i < n; i++) {
            w = r->w[i];
            pts[i].x += (f32)(((w & 0xFF0000) << 8) >> 23);
            pts[i].y += (f32)(((w << 16) >> 24) * 2);
            pts[i].z += (f32)((w << 24) >> 23);
        }
    }
}
