#include "b21_types.h"

void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
void func_00272088(B21Plane *out, Vec3f *a, Vec3f *b);
void func_002720EC(B21Plane *p);

static inline void MkPlane(B21Plane *pl, Vec3f *a, Vec3f *b, Vec3f *c) {
    Vec3f t1;
    Vec3f t2;
    func_00271FD8(&t1, b, a);
    func_00271FD8(&t2, c, b);
    func_00272088(pl, &t2, &t1);
    func_002720EC(pl);
    pl->w = pl->x * a->x + pl->y * a->y + pl->z * a->z;
}

void func_002975B0(B21Plane *pl, Vec3f *p1, Vec3f *p2, Vec3f *p3, Vec3f *p4, Vec3f *p5) {
    MkPlane(&pl[2], p2, p3, p5);
    MkPlane(&pl[0], p1, p2, p4);
    MkPlane(&pl[1], p1, p5, p3);
    MkPlane(&pl[4], p1, p3, p2);
    MkPlane(&pl[3], p1, p4, p5);
    pl[5].x = -pl[2].x;
    pl[5].y = -pl[2].y;
    pl[5].z = -pl[2].z;
    pl[5].w = pl[5].x * p1->x + pl[5].y * p1->y + pl[5].z * p1->z;
}

