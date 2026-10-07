#include "b16_types.h"

f32 func_802BC380(f32 x);
void func_00271FD8(Vec3f *dst, Vec3f *a, Vec3f *b);
void func_00272088(Vec3f *dst, Vec3f *a, Vec3f *b);

void func_0026F3D8(B16Mtx *m, Vec3f *eye, Vec3f *target, Vec3f *up) {
    Vec3f u, f, s;
    f32 inv, len;

    func_00271FD8(&f, target, eye);
    len = func_802BC380(f.x * f.x + f.y * f.y + f.z * f.z);
    if (len > 0.001f) {
        len = -1.0f / len;
        f.x *= len;
        f.y *= len;
        f.z *= len;
    } else {
        f.y = 0.0f;
        f.z = 0.0f;
        f.x = 1.0f;
    }
    func_00272088(&s, up, &f);
    len = func_802BC380(s.x * s.x + s.y * s.y + s.z * s.z);
    if (len > 0.001f) {
        len = 1.0f / len;
        s.x *= len;
        s.y *= len;
        s.z *= len;
    } else {
        s.y = 0.0f;
        s.z = 0.0f;
        s.x = 1.0f;
    }
    func_00272088(&u, &f, &s);
    len = func_802BC380(u.x * u.x + u.y * u.y + u.z * u.z);
    len = 1.0f / len;
    u.x *= len;
    u.y *= len;
    u.z *= len;
    m->m[0][0] = s.x;
    m->m[1][0] = s.y;
    m->m[2][0] = s.z;
    m->m[3][0] = -(eye->x * s.x + eye->y * s.y + eye->z * s.z);
    m->m[0][1] = u.x;
    m->m[1][1] = u.y;
    m->m[2][1] = u.z;
    m->m[3][1] = -(eye->x * u.x + eye->y * u.y + eye->z * u.z);
    m->m[0][2] = f.x;
    m->m[1][2] = f.y;
    m->m[2][2] = f.z;
    m->m[3][2] = -(eye->x * f.x + eye->y * f.y + eye->z * f.z);
    m->m[0][3] = 0.0f;
    m->m[1][3] = 0.0f;
    m->m[2][3] = 0.0f;
    m->m[3][3] = 1.0f;
}
