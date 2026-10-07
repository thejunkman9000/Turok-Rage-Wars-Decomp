#include "b11_types.h"

void func_0024795C(f32 *q);
void func_002742B4(f32 *q, f32 *m);
void func_00272908(f32 *m, Vec3f *v, Vec3f *out);

Vec3f func_0024BC84(s32 unused, Vec3f v) {
    f32 q[4];
    f32 m[16];
    Vec3f r;
    func_0024795C(q);
    func_002742B4(q, m);
    func_00272908(m, &v, &r);
    return r;
}
