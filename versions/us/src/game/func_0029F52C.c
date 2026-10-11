
#include "b22_types.h"
void func_0029F52C(Vec3f *v)
{
    float len = B22Sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    v->x = v->x * (1.0f / len);
    v->y = v->y * (1.0f / len);
    v->z = v->z * (1.0f / len);
}
