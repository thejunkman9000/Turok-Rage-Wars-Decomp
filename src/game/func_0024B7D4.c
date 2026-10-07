#include "b11_types.h"

/* 4 words differ: delay slots (ROM uses $zero for the FD94 arg, we use s0 == 0 via CSE) */
extern u8 D_800C8AD0[];
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *h, s32 i);
s32 *func_0024BFC4(Obj *a, s32 b);
s32 func_002484A0(Obj *a, s32 b, s32 c);
s32 func_0028FD94(s32 node, s32 idx);
void func_002536F4(s32 a, void *p);

s32 func_0024B7D4(Obj *a, s32 arg)
{
  s32 r = 0;
  s32 *h;
  s32 *p;
  if (a->flags & 0x40000)
  {
    if (a->unkC4)
    {
      h = func_002518DC(0, a->unkC4, a->unkC4, a->unkD0, 0, 0, 0, D_800C8AD0 + 4, arg);
    }
    else
    {
      h = func_002518DC(0, a->unkC4, a->unkC4, a->unkD0, 0, 0, 0, D_800C8AD0 + 4, arg);
    }
    if (h != 0)
    {
      p = func_0024BFC4(a, a->unk1);
      if (p != 0)
      {
        s32 t = *p;
        r = func_002484A0(a, t, func_0028FD94(*h, 0));
        func_002536F4(0, p);
      }
      func_002536F4(0, h);
    }
  }
  return r;
}
