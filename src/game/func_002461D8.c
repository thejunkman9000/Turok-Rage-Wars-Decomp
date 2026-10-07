#include "b10_types.h"

extern s32 D_801040D0[];
f32 func_00275E44(s32 a, s32 b, s32 c);
unsigned int func_00243A80(B10Obj *o, Vec3f v, s32 *p);

/* 12 words differ: only the three temp registers of the 12-byte struct copies (ROM v1,t0,t1; ours v0,v1,t0) */
void func_002461D8(B10Obj *o, f32 x, f32 z)
{
  Vec3f saved;
  B10Obj *new_var;
  Vec3f v;
  f32 d;
  B10Obj *new_var2;
  s32 s;
  f32 h = func_00275E44((s32) o->p14, o->u8, o->u10);
  d = o->fC - h;
  saved = o->v1C;
  new_var2 = o;
  new_var2->v1C.x = ((new_var = new_var2)->v1C.y = (new_var2->v1C.z = 0.0f));
  v.x = x;
  v.y = new_var2->fC;
  v.z = z;
  s = D_801040D0[0];
  func_00243A80(new_var2, v, D_801040D0);
  D_801040D0[0] = s;
  new_var2->v1C = saved;
  new_var2->fC = func_00275E44((s32) new_var2->p14, new_var2->u8, new_var2->u10) + d;
}
