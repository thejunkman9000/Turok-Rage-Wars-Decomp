#include "b11_types.h"

void func_0025E5D0(s32 *p, s32 a, s32 b, f32 *out);
void func_00273744(f32 *m, s32 a);
void func_00272908(f32 *m, Vec3f *v, Vec3f *out);

Vec3f func_0024C0F4(Obj *o, s32 *p) {
    f32 m[16];
    f32 t[3];
    Vec3f u;
    Vec3f r;
    func_0025E5D0(p, 0, *p, t);
    u.x = t[0];
    u.y = t[2];
    u.z = t[1];
    func_00273744(m, o->unk6C.i);
    func_00272908(m, &u, &r);
    r.x *= o->unk50;
    r.y *= o->unk54;
    r.z *= o->unk58;
    return r;
}
