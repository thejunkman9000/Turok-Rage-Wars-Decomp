#include "b16_types.h"
extern f32 D_80115DEC;
f32 func_802BC380(f32 x);
f32 sinf(f32 x);
f32 cosf(f32 x);
f32 func_00274640(f32 x);
#define ABS(a) ((a) < 0.0f ? -(a) : (a))

B16Vec4 func_00271888(Vec3f *v)
{
  B16Vec4 q;
  Vec3f d;
  Vec3f ref;
  Vec3f axis;
  f32 len;
  f32 inv;
  f32 ang;
  float new_var;
  f32 half;
  f32 s;
  f32 s0;
  f32 alen;
  f32 ainv;
  len = func_802BC380(((v->x * v->x) + (v->y * v->y)) + (v->z * v->z));
  if (len == 0.0f)
  {
    q.x = (q.y = (q.z = 0.0f));
    q.w = 1.0f;
    goto done;
  }
  inv = 1.0f / len;
  d.x = v->x * inv;
  d.y = v->y * inv;
  d.z = v->z * inv;
  ref.x = 0.0f;
  ref.y = 0.0f;
  ref.z = 1.0f;
  if (((d.z < 0.0f) ? (-d.z) : (d.z)) > 0.99999f)
  {
    half = 0.0f;
    s0 = sinf(half);
    q.z = d.z * s0;
    D_80115DEC = s0;
    q.x = half;
    q.y = half;
    q.w = cosf(half);
  }
  else
  {
    ang = func_00274640(((d.x * ref.x) + (d.y * ref.y)) + (d.z * ref.z));
    axis.x = (ref.y * d.z) - (ref.z * d.y);
    axis.y = (ref.z * d.x) - (ref.x * d.z);
    axis.z = (ref.x * d.y) - (ref.y * d.x);
    alen = func_802BC380(((axis.x * axis.x) + (axis.y * axis.y)) + (axis.z * axis.z));
    if (alen != 0.0f)
    {
      ainv = 1.0f / alen;
      axis.x *= ainv;
      axis.y *= ainv;
      axis.z *= ainv;
    }
    s = sinf(ang * 0.5f);
    q.x = axis.x * s;
    q.y = axis.y * s;
    q.z = axis.z * s;
    D_80115DEC = s;
    half = ang * 0.5f;
    q.w = cosf(half);
  }
done:
  return q;
}