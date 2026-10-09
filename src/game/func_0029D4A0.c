

#include "b22_types.h"
static inline void func_0029F93C(Vec3f *out, Vec3f *p, Vec3f *q, f32 nx, f32 ny, f32 nz, f32 d)
{
    Vec3f dir;
    f32 num, den, t;
    dir.x = q->x - p->x;
    dir.y = q->y - p->y;
    dir.z = q->z - p->z;
    num = -(nx * p->x + ny * p->y + nz * p->z + d);
    den = nx * dir.x + ny * dir.y + nz * dir.z;
    if (den < 0.001f && den > -0.001f) {
        t = 0.5f;
    } else {
        t = num / den;
    }
    out->x = p->x + t * dir.x;
    out->y = p->y + t * dir.y;
    out->z = p->z + t * dir.z;
}


s32 func_0029D4A0(Vec3f *out, s32 *outCnt, Vec3f *in, s32 n, f32 nx, f32 ny, f32 nz, f32 d)
{
    s32 cnt = 0;
    s32 hit = 0;
    s32 i;
    s32 ps, cs;
    Vec3f *prev, *cur, *tmp;
    *outCnt = 0;
    if (n == 0) {
        return 0;
    }
    prev = &in[n - 1];
    ps = 0.0f <= prev->x * nx + prev->y * ny + prev->z * nz + d;
    for (i = 0; i < n; i++) {
        cur = &in[i];
        cs = 0.0f <= cur->x * nx + cur->y * ny + cur->z * nz + d;
        if (ps) {
            *out = *prev;
            out++;
            cnt++;
        }
        if (ps != cs) {
            hit = 1;
            tmp = out;
            out++;
            cnt += hit;
            func_0029F93C(tmp, prev, cur, nx, ny, nz, d);
        }
        prev = cur;
        ps = cs;
    }
    *outCnt = cnt;
    return hit;
}



