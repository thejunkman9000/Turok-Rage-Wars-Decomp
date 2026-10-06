#include "b22_types.h"
void func_0029F458(Vec3f *d, Vec3f *a, Vec3f *b)
{
    Vec3f t;
    t.x = a->y * b->z - a->z * b->y;
    t.y = a->z * b->x - a->x * b->z;
    t.z = a->x * b->y - a->y * b->x;
    *d = t;
}
