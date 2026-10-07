#include "m01_types.h"

typedef struct M1Quat { f32 x, y, z, w; } M1Quat;
extern Vec3f D_800C6AE0;
extern f32 D_800C6AEC;
extern f32 D_800C6AF0;
extern f32 D_800C6AF4;
extern f32 D_800C6AF8;
extern f32 D_800C6AFC;
extern f32 D_80115DEC;
void func_002720EC(Vec3f *v);
void func_00272088(Vec3f *out, Vec3f *a, Vec3f *b);
f32 func_00274640(f32 x);

M1Quat func_00202CA0(Vec3f *v) {
    M1Quat q;
    Vec3f up;
    Vec3f axis;
    f32 ang, ang2;
    f32 sn;
    f32 zero;
    f32 y;

    up = D_800C6AE0;
    func_002720EC(v);
    y = v->y;
    if (D_800C6AEC < y) {
        zero = 0.0f;
        q.z = zero;
        q.y = zero;
        q.x = zero;
        q.w = D_800C6AF0;
    } else if (y < D_800C6AF4) {
        ang = D_800C6AF8;
        q.x = D_80115DEC = sinf(ang);
        q.y = 0.0f;
        q.z = 0.0f;
        q.w = cosf(ang);
    } else {
        ang2 = func_00274640(v->x * up.x + y * up.y + v->z * up.z);
        func_00272088(&axis, &up, v);
        func_002720EC(&axis);
        ang = ang2 * D_800C6AFC;
        sn = sinf(ang);
        D_80115DEC = sn;
        q.x = axis.x * sn;
        q.y = axis.y * sn;
        q.z = axis.z * sn;
        q.w = cosf(ang);
    }
    return q;
}
