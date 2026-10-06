#include "b22_types.h"
f32 func_0029D044(f32, f32);
void func_0029F810(Vec3f *v, f32 *p, f32 *q)
{
    f32 len = B22Sqrt(v->x * v->x + v->z * v->z);
    *q = func_0029D044(v->x, v->z);
    *p = func_0029D044(v->y, len);
    *q = -*q;
}
