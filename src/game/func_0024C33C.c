#include "b11_types.h"

void func_0025E5D0(f32 *p, s32 a, f32 t, f32 *out);
void func_00273744(f32 *m, s32 a);
void func_00272908(f32 *m, f32 *v, f32 *out);
void func_0024E78C(Obj *a, Vec3f v, Vec3f *out, B11Box **box, s32 e, s32 f);

void func_0024C33C(Obj *a, f32 *p) {
    f32 t0[3];
    f32 t1[3];
    f32 d[3];
    f32 r[3];
    Vec3f w;
    f32 m[16];
    func_0025E5D0(p, 0, 0.0f, t0);
    func_0025E5D0(p, 0, *p, t1);
    d[0] = t1[0] - t0[0];
    d[1] = 0.0f;
    d[2] = t1[1] - t0[1];
    func_00273744(m, a->unk6C.i);
    func_00272908(m, d, r);
    w.x = a->pos.x + r[0] * a->unk50;
    w.y = a->pos.y;
    w.z = a->pos.z + r[2] * a->unk58;
    func_0024E78C(a, w, &a->pos, (B11Box **)&a->unk14, 0, 0);
}
