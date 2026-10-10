#include "b12_types.h"

void func_00255854(B12Heap *h, u32 base, u32 size)
{
  B12HBlk *b;
  u32 e;
  e = base + size;
  b = (B12HBlk *) ((base + 0xF) & (~0xF));
  h->start = base;
  h->end = e;
  size -= ((u32) b) - base;
  size &= ~0xF;
  b->prev = 0;
  b->next = 0;
  b->unkC = 0;
  b->unk8 = 0;
  b->hdr = 0x20;
  b->size = size - 0x20;
  h->cur = b;
  if (b->size != 0)
  {
    h->last = b;
    h->first = b;
  }
  else
  {
    h->last = 0;
    h->first = 0;
  }
}