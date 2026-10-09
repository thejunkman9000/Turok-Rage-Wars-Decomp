#include "b17_types.h"

RecW *func_0028FD94(s32 a, s32 n);

void func_00278BAC(s32 a, s32 n, Vec3f *pts) {
    RecW *r;
    s32 i, w;
    Vec3f *p;
    f32 x, y, z;
    s32 ix, iy, iz;
    s32 *wp;
    r = func_0028FD94(a, 1);
    if (r->u4 != 0) {
        wp = r->w;
        for (i = 0; i < n; i++) {
            w = wp[i];
            p = &pts[i];
            ix = ((w & 0xFF0000) << 8) >> 23;
            iy = ((w << 16) >> 24) * 2;
            iz = (w << 24) >> 23;
            p->x = p->x + (f32)ix;
            p->y = p->y + (f32)iy;
            p->z = p->z + (f32)iz;
        }
    }
}