/* PARTIAL: only the temp regs of the src->pos struct copy differ (ours v0,v1,t0; ROM v1,t0,t1); two dead local Vec3f (0x30 scale, 0x40 zero) are real */
#include "b15_types.h"
s32 func_0028FFB0(void *a, s32 b, s32 c, Vec3f zero, Vec3f pos, s32 d, f32 e);
extern u8 D_80131600[];

void func_002686EC(s32 a, B15Src *src, s32 c, Vec3f v, B15PairF k)
{
  Vec3f sc;
  Vec3f z;
  z.x = 0;
  z.y = 0;
  z.z = 0;
  sc.x = k.b;
  sc.y = k.b;
  sc.z = k.b;
  func_0028FFB0(D_80131600, 0, k.a, z, src->pos, 0, 0.0f);
}
