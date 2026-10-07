#include "b04_types.h"
extern f32 D_800C73E8, D_800C73EC;
extern u8 D_8010EEB8[];
typedef struct { u8 b[0x224]; } B04Row224;
extern B04Row224 D_8010F328[];
typedef struct { u8 pad0[0xF4]; f32 unkF4; } B04Def9;
typedef struct { u8 pad0[0x8D]; u8 unk8D; } B04St9;
typedef struct { u8 pad0[8]; Vec3f pos; u8 pad14[4]; B04Def9 *def; } B04P9h;
#define W(o, off) (*(s32 *)((u8 *)(o) + (off)))
#define F(o, off) (*(f32 *)((u8 *)(o) + (off)))
typedef struct { s32 x, y, z; } V3i;
#define VI(o, off) (*(V3i *)((u8 *)(o) + (off)))
#define V3(o, off) (*(Vec3f *)((u8 *)(o) + (off)))
#define P(o, off, T) (*(T *)((u8 *)(o) + (off)))
void func_0026369C(void *, void *);
f32 func_0022ADAC(void *);
void func_002227D0();
void func_0021A78C(B04P9h *a)
{
  f32 fs;
  B04P9h *new_var;
  u8 *new_var3;
  f32 c1;
  f32 c2;
  u8 *new_var2;
  if ((*((s32 *) (((u8 *) a) + 0x1450))) != 0)
  {
    func_0026369C(((u8 *) a) + 0x688, D_8010EEB8);
  }
  else
  {
    func_0026369C(((u8 *) a) + 0x688, &D_8010F328[*((s32 *) (((u8 *) a) + 0x5D4))]);
  }
  *((s32 *) (((u8 *) a) + 0x6C0)) = 0;
  *((s32 *) (((u8 *) a) + 0x6C4)) = 0;
  *((s32 *) (((u8 *) a) + 0x6C8)) = 0;
  *((s32 *) (((u8 *) a) + 0x6CC)) = 0;
  *((s32 *) (((u8 *) a) + 0x6D0)) = 1;
  *((s32 *) (((u8 *) a) + 0x6D4)) = 0;
  *((s32 *) (((u8 *) a) + 0x6D8)) = 0;
  *((s32 *) (((u8 *) a) + 0x6DC)) = 0;
  *((s32 *) (((u8 *) a) + 0x6E4)) = 0;
  *((s32 *) (((u8 *) a) + 0x758)) = 0;
  *((s32 *) (((u8 *) a) + 0x75C)) = 0;
  *((s32 *) (((u8 *) a) + 0x11B4)) = 0;
  *((s32 *) (((u8 *) a) + 0x11B8)) = 0;
  *((s32 *) (((u8 *) a) + 0x708)) = 0;
  *((s32 *) (((u8 *) a) + 0x70C)) = 0;
  *((s32 *) (((u8 *) a) + 0x710)) = 0;
  *((s32 *) (((u8 *) a) + 0x714)) = 0;
  *((s32 *) (((u8 *) a) + 0x724)) = 0;
  *((s32 *) (((u8 *) a) + 0x728)) = 0;
  *((s32 *) (((u8 *) a) + 0x72C)) = 0;
  *((s32 *) (((u8 *) a) + 0x730)) = 0;
  *((s32 *) (((u8 *) a) + 0x734)) = 0;
  *((s32 *) (((u8 *) a) + 0x738)) = 0;
  *((s32 *) (((u8 *) a) + 0x73C)) = 0;
  *((f32 *) (((u8 *) a) + 0x740)) = func_0022ADAC(a);
  c1 = D_800C73E8;
  *((s32 *) (((u8 *) a) + 0x744)) = 0;
  (*((V3i *) (((u8 *) a) + 0x748))).x = ((*((V3i *) (((u8 *) a) + 0x748))).y = ((*((V3i *) (((u8 *) a) + 0x748))).z = 0));
  *((f32 *) (((u8 *) a) + 0x754)) = c1;
  *((s32 *) (((u8 *) a) + 0x780)) = 0;
  *((f32 *) (((u8 *) a) + 0x784)) = c1;
  *((Vec3f *) (((u8 *) a) + 0x6E8)) = a->pos;
  *((Vec3f *) (((u8 *) a) + 0x6F8)) = a->pos;
  *((s32 *) (((u8 *) a) + 0x658)) = 0;
  *((s32 *) (((u8 *) a) + 0x668)) = 0;
  *((s32 *) (((u8 *) a) + 0x66C)) = 0;
  if (a->def != ((void *) 0))
  {
    *((f32 *) (((u8 *) a) + 0x6F4)) = a->def->unkF4;
  }
  else
  {
    new_var3 = (u8 *) a;
    *((s32 *) (new_var3 + 0x6F4)) = 0;
  }
  *((s32 *) (((u8 *) a) + 0x7B0)) = 0;
  new_var = a;
  fs = *((f32 *) (((u8 *) new_var) + 0x7B0));
  c2 = D_800C73EC;
  new_var3 = (u8 *) a;
  *((s32 *) (((u8 *) a) + 0x718)) = 0;
  *((s32 *) (new_var3 + 0x71C)) = 0;
  *((s32 *) (((u8 *) a) + 0x720)) = 0;
  *((s32 *) (new_var3 + 0x7EC)) = 0;
  *((s32 *) (new_var3 + 0x7F0)) = 0;
  *((s32 *) (new_var3 + 0x7E8)) = 0;
  *((s32 *) (new_var3 + 0x788)) = 0;
  *((s32 *) (((u8 *) a) + 0x78C)) = 0;
  *((s32 *) (new_var3 + 0x790)) = 0;
  *((s32 *) (new_var3 + 0x794)) = 0;
  *((s32 *) (new_var3 + 0x798)) = -1;
  *((s32 *) (new_var3 + 0x7AC)) = (*((s32 *) (((u8 *) a) + 0x7A8)) = (*((s32 *) (new_var3 + 0x7A4)) = (*((s32 *) (new_var3 + 0x7A0)) = (*((s32 *) (((u8 *) a) + 0x79C)) = 0))));
  new_var2 = new_var3;
  (*((Vec3f *) (new_var2 + 0x7D8))).x = ((*((Vec3f *) (new_var2 + 0x7D8))).y = ((*((Vec3f *) (new_var2 + 0x7D8))).z = fs));
  *((f32 *) (new_var2 + 0x7E4)) = c2;
  *((s32 *) (new_var3 + 0x7B4)) = 0;
  *((s32 *) (new_var2 + 0x7B8)) = -1;
  *((f32 *) (new_var2 + 0x7C0)) = fs;
  *((f32 *) (new_var2 + 0x7C4)) = fs;
  *((f32 *) (new_var2 + 0x7C8)) = fs;
  *((f32 *) (new_var3 + 0x7CC)) = fs;
  *((f32 *) (((u8 *) a) + 0x7D0)) = fs;
  *((f32 *) (new_var2 + 0x7D4)) = fs;
  func_002227D0(a, a, 2);
  *((s32 *) (new_var3 + 0x80C)) = 0;
  *((f32 *) (new_var3 + 0x838)) = fs;
  *((f32 *) (new_var2 + 0x83C)) = fs;
  *((f32 *) (new_var2 + 0x840)) = fs;
  *((s32 *) (new_var3 + 0x848)) = 0;
  (*((B04St9 **) (new_var3 + 0x5D8)))->unk8D = 0;
  *((f32 *) (new_var3 + 0x704)) = fs;
  *((s32 *) (new_var2 + 0x16D4)) = 0;
}
