#include "b23_types.h"

typedef struct Quat4f {
    f32 x, y, z, w;
} Quat4f;

extern f32 D_800CB018;
extern f32 D_800CB01C;
extern f32 D_80115DEC;

void func_00272088(Vec3f *out, Vec3f *a, Vec3f *b);
void func_0027200C(Vec3f *dst, Vec3f *src, f32 s);
f32 func_00274640(f32 x);

Quat4f *func_002A6010(Quat4f *out, Vec3f axis) {
    Vec3f up, c;
    Quat4f q;
    f32 len, one, ang, s;

    one = D_800CB018;
    up.x = 0.0f;
    up.z = 0.0f;
    up.y = one;
    func_00272088(&c, &up, &axis);
    len = sqrtf(c.x * c.x + c.y * c.y + c.z * c.z);
    if (len == 0.0f) {
        q.z = 0.0f;
        q.y = 0.0f;
        q.x = 0.0f;
        q.w = one;
    } else {
        func_0027200C(&c, &c, one / len);
        ang = func_00274640(up.x * axis.x + up.y * axis.y + up.z * axis.z) * D_800CB01C;
        s = sinf(ang);
        D_80115DEC = s;
        q.x = c.x * s;
        q.y = c.y * s;
        q.z = c.z * s;
        q.w = cosf(ang);
    }
    *out = q;
    return out;
}
