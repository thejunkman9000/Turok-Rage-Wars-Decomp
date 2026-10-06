#include "b21_types.h"

void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
void func_00272088(B21Plane *out, Vec3f *a, Vec3f *b);
void func_002720EC(B21Plane *p);

void func_00297878(B21Plane *pl, Vec3f *a, Vec3f *b, Vec3f *c) {
    Vec3f t1;
    Vec3f t2;
    func_00271FD8(&t1, b, a);
    func_00271FD8(&t2, c, b);
    func_00272088(pl, &t2, &t1);
    func_002720EC(pl);
    pl->w = pl->x * a->x + pl->y * a->y + pl->z * a->z;
}
