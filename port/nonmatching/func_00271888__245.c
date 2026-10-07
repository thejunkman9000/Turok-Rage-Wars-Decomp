#include "b16_types.h"
extern f32 D_80115DEC;
f32 func_802BC380(f32 x);
f32 sinf(f32 x);
f32 cosf(f32 x);
f32 func_00274640(f32 x);
#define ABS(a) ((a) < 0.0f ? -(a) : (a))

B16Vec4 func_00271888(Vec3f *v) {
    B16Vec4 q;
    Vec3f d, ref, axis;
    f32 len, inv, ang, half, s, alen, ainv;
    len = func_802BC380(v->x * v->x + v->y * v->y + v->z * v->z);
    if (len == 0.0f) {
        q.x = q.y = q.z = 0.0f;
        q.w = 1.0f;
        return q;
    }
    inv = 1.0f / len;
    d.x = v->x * inv;
    d.y = v->y * inv;
    d.z = v->z * inv;
    ref.x = 0.0f;
    ref.y = 0.0f;
    ref.z = 1.0f;
    if (ABS(d.z) > 0.99999f) {
        half = 0.0f;
        s = sinf(half);
        q.z = d.z * s;
        D_80115DEC = s;
        q.x = half;
        q.y = half;
    } else {
        ang = func_00274640(d.x * ref.x + d.y * ref.y + d.z * ref.z);
        axis.x = d.y * ref.z - d.z * ref.y;
        axis.y = d.z * ref.x - d.x * ref.z;
        axis.z = d.x * ref.y - d.y * ref.x;
        alen = func_802BC380(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
        if (alen != 0.0f) {
            ainv = 1.0f / alen;
            axis.x *= ainv;
            axis.y *= ainv;
            axis.z *= ainv;
        }
        s = sinf(ang * 0.5f);
        q.x = axis.x * s;
        q.y = axis.y * s;
        q.z = axis.z * s;
        D_80115DEC = s;
        half = ang * 0.5f;
    }
    q.w = cosf(half);
    return q;
}
