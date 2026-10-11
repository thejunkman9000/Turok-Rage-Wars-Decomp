#include "q01_types.h"

/* Q01 pool re-initialisation: frees the old buffers, then (re)allocates the frame-buffer pool and the display-list / buffer handles.
   An allocation handle is a pointer to a struct whose first word is the buffer address (Q01Mem): reading h->addr is a struct-member load
   (MEM_IN_STRUCT_P), which sched1 may move across the stores to the scalar globals; a plain *(s32 *)h is a pointer deref that it may not. */
typedef struct Q01Mem { s32 addr; } Q01Mem;
typedef struct Q01Pool { s32 unk0; Q01Mem *unk4; Q01Mem *unk8; Q01Mem *unkC[3]; Q01Mem *unk18; Q01Mem *unk1C; } Q01Pool;
extern u32 D_800E28A0;
extern s32 D_800E28A4;
extern s32 D_800E28A8;
extern s32 D_801536B0;
extern s32 D_801536B4;
extern s32 D_801536B8;
extern s32 D_801536BC;
extern s32 D_801536C0;
extern s32 D_801536E8;
extern s32 D_801536EC;
extern s32 D_801536F0;
extern s32 D_801536F4;
extern s32 D_801536F8[];
extern u8 D_800E0D30[];
extern u8 D_800E0D3C[];
extern u8 D_800E0D4C[];
extern u8 D_800E0D6C[];
extern u8 D_800E0D7C[];
extern u8 D_800E0D84[];
Q01Mem *func_002533DC(s32 a, s32 b, s32 c, void *d);
Q01Mem *func_002534D0(s32 a, s32 b, s32 c, void *d);
void func_002537D8(s32 a, Q01Mem *b);
u32 func_00265370();
void *memset(void *p, s32 c, u32 n);

void func_004058B0(Q01Pool *arg0)
{
  u32 mb = 0x100000;
  u32 i;
  s32 j;
  s32 n;
  Q01Mem *a;
  Q01Mem *b;
  Q01Mem *b2;
  u32 sz;
  u32 base;
  if (arg0->unk4 != 0)
  {
    func_002537D8(0, arg0->unk4);
  }
  if (arg0->unk8 != 0)
  {
    func_002537D8(0, arg0->unk8);
  }
  if (arg0->unk18 != 0)
  {
    func_002537D8(0, arg0->unk18);
  }
  if (arg0->unk1C != 0)
  {
    func_002537D8(0, arg0->unk1C);
  }
  for (n = 0; n < 3; n++)
  {
    if (arg0->unkC[n] != 0)
    {
      func_002537D8(0, arg0->unkC[n]);
    }
  }

  arg0->unk0 = 0;
  arg0->unk4 = 0;
  arg0->unk8 = 0;
  arg0->unk18 = 0;
  arg0->unk1C = 0;
  for (j = 2; j >= 0; j--)
  {
    arg0->unkC[j] = 0;
  }

  if (func_00265370() >= (mb * 6))
  {
    sz = 0x54600;
    base = func_00265370() | 0x80000000;
    D_800E28A0 = 3;
    a = func_002534D0(0, base - mb, sz, D_800E0D30);
    b = func_002534D0(0, base - (mb * 2), D_800E28A0 * sz, D_800E0D3C);
    memset((void *) b->addr, 0, 0xFD200);
    memset((void *) a->addr, 0, 0x54600);
    arg0->unk18 = a;
    arg0->unkC[0] = b;
    D_801536E8 = arg0->unk18->addr;
    for (i = 0; i < D_800E28A0; i++)
      D_801536F8[i] = b->addr + i * sz;
  }
  else
  {
    sz = 0x1ECC0;
    base = 0x80400000;
    b2 = func_002534D0(0, base - ((D_800E28A0 + 1) * sz), (D_800E28A0 + 1) * sz, D_800E0D4C);
    arg0->unkC[0] = b2;
    for (i = 0; i < D_800E28A0; i++)
      D_801536F8[i] = b2->addr + i * sz;
    D_801536E8 = b2->addr + (sz * i);
  }
  for (i = 0; i < D_800E28A0; i++)
    memset((void *) D_801536F8[i], 0, sz);
  memset((void *) D_801536E8, 0, sz);
  arg0->unk4 = func_002533DC(0, (D_800E28A4 + D_800E28A8) * 16, 0x23, D_800E0D6C);
  arg0->unk8 = func_002533DC(0, 0x8000, 0x23, D_800E0D7C);
  arg0->unk1C = func_002533DC(0, 0x22000, 0x23, D_800E0D84);
  D_801536F0 = arg0->unk4->addr;
  D_801536BC = D_801536F0 + (D_800E28A4 * 8);
  D_801536F4 = D_801536BC + (D_800E28A8 * 8);
  D_801536C0 = D_801536F4 + (D_800E28A4 * 8);
  D_801536B4 = 0x8000;
  D_801536EC = 0x22000;
  D_801536B8 = arg0->unk8->addr;
  D_801536B0 = arg0->unk1C->addr;
  for (i = 0; i < D_800E28A0; i++)
    ;
  arg0->unk0 = 1;
}
