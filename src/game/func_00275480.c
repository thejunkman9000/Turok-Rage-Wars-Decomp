#include "b17_types.h"

extern f32 D_800C9ABC;
extern f32 D_800C9AC0;
extern f32 D_800C9AC4;
extern f32 D_800C9AC8;
extern f32 D_80115DEC;
extern Tri3 *D_800D2638;
extern Tri3 *D_800D263C;
extern Vec3f D_80115E10;
extern Vec3f D_80115E20;
f32 func_002BC380(f32); /* sqrtf */
f32 sinf(f32 x);
f32 cosf(f32 x);
void func_00271FD8(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00272088(Vec3f *d, Vec3f *a, Vec3f *b);
void func_002720EC(Vec3f *v);
void func_0027200C(Vec3f *d, Vec3f *a, f32 s);
f32 func_00274640(f32 x);

static inline void tri_normal_upd(Tri3 *t) {
    Vec3f e0, e1;

    if (t == 0) {
        D_80115E10.x = 0;
        D_80115E10.y = D_800C9AC0;
        D_80115E10.z = 0;
    } else if (t != D_800D2638) {
        func_00271FD8(&e0, t->v[1], t->v[0]);
        func_00271FD8(&e1, t->v[2], t->v[1]);
        func_00272088(&D_80115E10, &e0, &e1);
    }
    D_800D2638 = t;
}

static inline void tri_unit_upd(Tri3 *t) {
    if (t == 0) {
        D_80115E20.x = 0;
        D_80115E20.z = 0;
        D_80115E20.y = D_800C9ABC;
    } else if (t != D_800D263C) {
        tri_normal_upd(t);
        D_80115E20 = D_80115E10;
        func_002720EC(&D_80115E20);
    }
}

Quat *func_00275480(Quat *out, Tri3 *t) {
    Vec3f n, up, axis;
    Quat q;
    f32 len, h, sn;

    tri_unit_upd(t);
    h = D_800C9AC4;
    D_800D263C = t;
    n = D_80115E20;
    up.x = 0.0f;
    up.y = h;
    up.z = 0.0f;
    func_00272088(&axis, &up, &n);
    len = func_002BC380(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    if (len == 0.0f) {
        q.z = 0.0f;
        q.y = 0.0f;
        q.x = 0.0f;
        q.w = h;
    } else {
        h = h / len;
        func_0027200C(&axis, &axis, h);
        h = func_00274640(up.x * n.x + up.y * n.y + up.z * n.z) * D_800C9AC8;
        sn = sinf(h);
        D_80115DEC = sn;
        q.x = axis.x * sn;
        q.y = axis.y * sn;
        q.z = axis.z * sn;
        q.w = cosf(h);
    }
    *out = q;
    return out;
}
