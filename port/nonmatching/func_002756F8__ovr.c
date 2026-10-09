/* port (passthru_fix.py): func_00275120 needs a1 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b17_types.h"

extern f32 D_800C9ACC;
extern f32 D_800C9AD0;
extern f32 D_80115DEC;
f32 func_002BC380(f32); /* sqrtf */
f32 sinf(f32 x);
f32 cosf(f32 x);
void func_00275120(Vec3f *v, u32);
void func_0027200C(Vec3f *d, Vec3f *a, f32 s);
void func_00272088(Vec3f *d, Vec3f *a, Vec3f *b);
f32 func_00274640(f32 x);

Quat *func_002756F8(Quat *out, u32 pt_a1) {
    Vec3f n, up, axis;
    Quat q;
    f32 len, t, sn;

    func_00275120(&n, pt_a1);
    t = D_800C9ACC;
    up.x = 0.0f;
    up.y = t;
    up.z = 0.0f;
    func_00272088(&axis, &up, &n);
    len = func_002BC380(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    if (len == 0.0f) {
        q.z = 0.0f;
        q.y = 0.0f;
        q.x = 0.0f;
        q.w = t;
    } else {
        t = t / len;
        func_0027200C(&axis, &axis, t);
        t = func_00274640(up.x * n.x + up.y * n.y + up.z * n.z) * D_800C9AD0;
        sn = sinf(t);
        D_80115DEC = sn;
        q.x = axis.x * sn;
        q.y = axis.y * sn;
        q.z = axis.z * sn;
        q.w = cosf(t);
    }
    *out = q;
    return out;
}
