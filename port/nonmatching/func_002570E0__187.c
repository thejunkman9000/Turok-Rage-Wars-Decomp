
#include "b12_types.h"
#include "libaudio.h"

typedef struct B12DbEnt B12DbEnt;
struct B12DbEnt {
    /* 0x00 */ B12DbEnt *next;
    /* 0x04 */ u8 *key;
    /* 0x08 */ u16 state;
    /* 0x0A */ u16 len;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ u8 data[1];
};

extern B12DbEnt *D_8010BDFC;
extern u32 D_800D0954;
extern ALHeap *D_8010BEA0;
void *func_002C2490(void *d, void *s, u32 n);
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);

u32 func_002570E0(u8 *src, u32 len)
{
  B12DbEnt *e;
  B12DbEnt *free = 0;
  u8 *d;
  B12DbEnt *new_var;
  for (e = D_8010BDFC; e; e = e->next)
  {
    if (e->key == src)
    {
      new_var = e;
      new_var->state = 3;
      if (new_var->len != len)
      {
        new_var->len = len;
        func_002C2490(e->data, src, len);
        osWritebackDCache(new_var->data, len);
      }
      return osVirtualToPhysical(e->data);
    }
    if (new_var->state == 0)
    {
      free = e;
    }
  }

  if (!free)
  {
    free = alHeapDBAlloc(0, 0, D_8010BEA0, 1, 0x90);
    free->next = D_8010BDFC;
    D_8010BDFC = free;
    D_800D0954++;
  }
  d = free->data;
  free->key = src;
  free->state = 3;
  free->len = len;
  func_002C2490(d, src, len);
  return osVirtualToPhysical(d);
}
