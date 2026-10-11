
#include "b22_types.h"
static inline void Normalize(Vec3f *v)
{
    float len = B22Sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    v->x = v->x * (1.0f / len);
    v->y = v->y * (1.0f / len);
    v->z = v->z * (1.0f / len);
}
static inline void Cross(Vec3f *d, Vec3f *a, Vec3f *b)
{
    Vec3f t;
    t.x = a->y * b->z - a->z * b->y;
    t.y = a->z * b->x - a->x * b->z;
    t.z = a->x * b->y - a->y * b->x;
    *d = t;
}
void func_0029E000(f32 *m)
{
    Vec3f a, b, c;
    a.x = m[0];
    a.y = m[1];
    a.z = m[2];
    b.x = m[4];
    b.y = m[5];
    b.z = m[6];
    Normalize(&a);
    Normalize(&b);
    Cross(&c, &a, &b);
    Cross(&b, &c, &a);
    {Vec3f *pa = &a;
    m[0] = a.x;
    m[1] = pa->y;
    m[2] = pa->z;}
    m[4] = b.x;
    m[5] = b.y;
    m[6] = b.z;
    m[8] = c.x;
    m[9] = c.y;
    m[10] = c.z;
}
