#include "m01_types.h"

extern f32 D_800D2988;
f32 func_00274B00(f32 lo, f32 hi);
f32 func_00265734(f32 x);

void func_00206A20(M1Actor *actor, M1State *state)
{
  M1Info *info = &actor->def->info;
  s32 prev = state->unk37;
  f32 t;
  f32 r;
  s32 go;
  f32 lo;
  f32 hi;
  s32 c;
  switch (prev)
  {
    case 0:
      if (!(info->unk24.u & 0xC00000))
    {
      break;
    }
      if (info->unk24.u & 0x4000000)
    {
      if (actor->flags38 & 0x40)
      {
        state->unk124.f = state->unk124.f + D_800D2988;
      }
      else
      {
        state->unk124.f = 0.0f;
        break;
      }
    }
    else
      if ((state->unk124.f > 0.0f) || (actor->flags38 & 0x20))
    {
      state->unk124.f = state->unk124.f + D_800D2988;
    }
      if (state->unk124.f >= info->f54)
    {
      state->f44 = 0.0f;
      if (info->unk24.u & 0x1000000)
      {
        state->unk37 = 3;
        break;
      }
      if (info->unk24.u & 0x400000)
      {
        state->unk37 = 1;
      }
      else
        if (info->unk24.u & 0x800000)
      {
        state->unk37 = 4;
      }
    }
      break;

    case 3:
      lo = -0.512f;
      hi = 0.512f;
      state->unk128.f = func_00274B00(lo, hi);
      state->unk12C.f = func_00274B00(lo, hi);
      state->vec130.x = func_00274B00(lo, hi);
      state->f44 = state->f44 + D_800D2988;
      if (45.0f < state->f44)
    {
      state->f44 = 0.0f;
      if (info->unk24.u & 0x400000)
      {
        state->unk37 = 1;
      }
      else
        if (info->unk24.u & 0x800000)
      {
        state->unk37 = 4;
      }
    }
      break;

    case 1:
      if (state->f44 < info->f5C)
    {
      state->f44 = state->f44 + D_800D2988;
    }
    else
    {
      if (info->unk24.u & 0x2000000)
      {
        actor->flags &= ~0x2000;
      }
      else
      {
        state->f44 = info->f5C;
        if ((info->unk24.u & 0x8000000) && (!(actor->flags38 & 0x40)))
        {
          go = 0;
        }
        else
        {
          u32 c = info->unk24.u;
          u32 q;
          go = 1;
          if (c & 0x10000000)
          {
            q = actor->flags38 & 0x40;
            go = q == 0;
          }
        }
        if (go)
        {
          state->unk37 = 2;
        }
      }
    }
      if (info->f5C > 0.0f)
    {
      state->unk12C.f = (-((float) info->f58)) * func_00265734(state->f44 / info->f5C);
    }
    else
    {
      state->unk12C.f = -info->f58;
    }
      break;

    case 2:
      if (state->f44 > 0.0f)
    {
      state->f44 = state->f44 - D_800D2988;
    }
    else
    {
      state->unk37 = 0;
      state->unk124.f = 0.0f;
    }
      if (info->f5C > 0.0f)
    {
      state->unk12C.f = (-info->f58) * func_00265734(state->f44 / info->f5C);
    }
    else
    {
      state->unk12C.f = -info->f58;
    }
      break;

    case 4:
      if (state->f44 < info->f5C)
    {
      state->f44 = state->f44 + D_800D2988;
    }
      if (info->f5C > 0.0f)
    {
      state->unk12C.f = (-info->f58) * func_00265734(state->f44 / info->f5C);
    }
    else
    {
      state->unk12C.f = -info->f58;
    }
      if (info->unk24.u & 0x2000000)
    {
      actor->flags = actor->flags & (~0x2000);
    }
      break;

  }

  if (prev != state->unk37)
  {
    state->unk35 = -1;
  }
}
