#include "b11_types.h"

Vec3f func_0024BC84(Obj *o, Vec3f v);
void func_00272908(void *m, Vec3f *v, Vec3f *out);
void func_00271FA4(Vec3f *out, Vec3f *a, Vec3f *b);
void func_0024E78C(Obj *a, Vec3f v, Vec3f *out, B11Box **box, s32 e, s32 f);

void func_0024BBA4(Obj *a, Vec3f v, Vec3f *out, B11Box **box) {
    Vec3f t;
    Vec3f r;
    u8 *p;
    if (a->flags & 0x300000) {
        v.x = -v.x;
        v.z = -v.z;
        p = a->unk1D8->unk5DC;
        if (p != 0) {
            func_00272908(p + 0x160, &v, &r);
        } else {
            t = func_0024BC84(a, v);
            func_00271FA4(&r, &a->pos, &t);
        }
    } else {
        t = func_0024BC84(a, v);
        func_00271FA4(&r, &a->pos, &t);
    }
    func_0024E78C(a, r, out, box, 1, 1);
}
