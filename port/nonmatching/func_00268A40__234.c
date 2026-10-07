/* PARTIAL (11 words): z-component FP register allocation (ROM f0/f1 swapped for the third diff) + one swc1 position */
#include "b15_types.h"

typedef struct B15Pt B15Pt;
struct B15Pt {
    u8 pad0[4];
    B15Pt *next;
    u16 *rad;
    u8 padC[4];
    s16 x, y, z;
    s16 active;
};

void func_00271FA4(s32 a, s32 b, Vec3f *v);
void func_0027200C(Vec3f *a, Vec3f *b, f32 c);
void func_002720EC(Vec3f *v);
extern f32 D_800C9580;
extern f32 D_800C9584;

void func_00268A40(B15Pt **head, Vec3f p, s32 a, f32 *b)
{
  B15Pt *n;
  Vec3f v;
  f32 d;
  f32 t;
  u16 *new_var;
  f32 u;
  f32 r;
  f32 f;
  float new_var2;
  u16 *rp;
  for (n = *head; n != ((void *) 0); n = n->next)
  {
    do
    {
      if (n->active != 0)
      {
        rp = n->rad;
        d = p.x - n->x;
        if (d < 0.0f)
        {
          d = -d;
        }
        t = p.y - n->y;
        if (t < 0.0f)
        {
          d = d - t;
        }
        else
        {
          d = d + t;
        }
        u = p.z - n->z;
        d = (u < 0.0f) ? (d - u) : (d + u);
        new_var = rp;
        r = (u = *new_var);
        if (d < r)
        {
          v.x = n->x - p.x;
          v.y = n->y - p.y;
          new_var2 = D_800C9580 - (d / r);
          v.z = n->z - p.z;
          f = new_var2;
          func_002720EC(&v);
          f = f * D_800C9584;
          func_0027200C(&v, &v, f);
          func_00271FA4(a, a, &v);
          *b -= f;
        }
      }
    }
    while (0);
  }

}
