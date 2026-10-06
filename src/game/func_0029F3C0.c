#include "b22_types.h"
float func_0029F3C0(Vec3f *a, Vec3f *b)
{
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    float dz = a->z - b->z;
    return B22Sqrt(dx * dx + dy * dy + dz * dz);
}
