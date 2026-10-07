#include "m04_types.h"

f32 Trunc16ToF32(u16 x);
void func_00259C7C(M04Emitter *o, void *a1, void *a2);
void func_00259F88(M04Emitter *o, void *a1, void *a2);
M04Rec12 *func_00258C14(M04Ctx *c, s16 id);
s32 func_00258D4C(M04Ctx *c, s16 id);
s32 func_00259B30(f32 *pos, M04Tgt *t);

typedef struct M04EmArg {
    u8 pad0[0xC];
    s16 id;
} M04EmArg;

void func_0025BBA4(M04Emitter *o, M04EmArg *a1, void *a2)
{
  f32 f;
  M04Rec12 *r;
  s16 id;
  func_00259C7C(o, a1, a2);
  func_00259F88(o, a1, a2);
  o->vp.pan = 0x40;
  id = a1->id;
  if (id != (-1))
  {
    r = func_00258C14(o->ctx, id);
    o->rec = *r;
    f = Trunc16ToF32(o->rec.w1);
 do { o->envSlope = (f - Trunc16ToF32(o->rec.w2)) / ((f32) o->rec.w3); o->env0 = Trunc16ToF32(o->rec.w1); o->vp.pan = (s32) Trunc16ToF32(o->rec.w1); o->hasEnv = 1; return; } while (0);
  }
  o->hasEnv = 0;
  if (o->kind < 0x100)
  {
    if ((o->resetFlag == 0) && (func_00258D4C(o->ctx, id) != 0))
    {
      o->vp.pan = o->ctx->defaultPan;
    }
  }
  else
    if ((o->resetFlag == 0) && (func_00258D4C(o->ctx, id) != 0))
  {
    o->vp.pan = func_00259B30((f32 *)((u8 *)o + 0x44), o->ctx->tgt);
  }
}
