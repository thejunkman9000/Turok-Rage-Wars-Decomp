#include "b11_types.h"

void func_0024E78C(Obj *a, Vec3f v, Vec3f *out, B11Box **box, s32 e, s32 f);
f32 func_00275E44(B11Box *box, f32 x, f32 z);

void func_0024E58C(Obj *a, Vec3f *b, Vec3f *c) {
    Vec3f v;
    B11Box *box;
    v.x = b->x;
    v.y = 0;
    v.z = b->z;
    func_0024E78C(a, v, c, &box, 0, 0);
    c->y = func_00275E44(box, c->x, c->z);
}
