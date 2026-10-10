#include "b02_types.h"

f32 func_00272768(void *a, void *b);
B2Pool *func_0028D1F4(void *g, u8 id);
Vec3f *func_0028D220(void *g, u8 id, s32 idx);
extern u8 D_8011FE88[];
extern B2Obj *D_8011FFC0;
extern s32 D_8011FFC8;
extern const f32 D_800C6E3C;
extern f32 D_800C6E40;

void func_0020ABF0(B2Mgr *m)
{
  B2Obj *list[30];
  s32 nlist;
  B2Obj **lp;
  s32 i;
  s32 z0;
  s32 j;
  s32 k;
  B2Node *n;
  u8 *r;
  B2Obj *sel;
  B2Obj *a;
  B2Obj *a0;
  B2Info *info;
  B2Sub *st;
  B2Pool *t;
  B2Pool *pl;
  Vec3f *p;
  Vec3f found;
  Vec3f pos1;
  Vec3f pos2;
  f32 best;
  f32 d;
  for (z0 = 29; z0 >= 0; z0--)
  {
    list[z0] = (void *) 0;
  }

  i = 0;
  nlist = 0;
  for (; i < D_8011FFC8; i++)
  {
    a0 = &D_8011FFC0[i];
    if (a0->unkE4 == 0x642)
    {
      lp = &list[nlist];
      *lp = a0;
      nlist++;
    }
  }

  for (n = m->head; n != ((void *) 0); n = n->next)
  {
    pl = m->pool0;
    r = (u8 *) (&pl->data[n->id * pl->elemSize]);
    sel = (void *) 0;
    if ((*((u16 *) (r + 0xC))) & 0x200)
    {
      best = D_800C6E40;
      k = 0;
      if (nlist > 0)
      {
        do
        {
          a = list[k];
          st = &a->sub;
          info = &a->def->info;
          if (st->unk34 == 4)
          {
            t = func_0028D1F4(D_8011FE88, st->unk95);
            if (t != ((void *) 0))
            {
              for (j = 0; j < ((s16 *) t)[1]; j++)
              {
                p = func_0028D220(D_8011FE88, st->unk95, j);
                d = func_00272768(r, p);
                if ((d < best) || (best == D_800C6E3C))
                {
                  sel = list[k];
                  best = d;
                  found = *p;
                }
              }

            }
          }
          else
          {
            pos1 = a->pos210;
            pos2 = a->pos210;
            pos2.y += info->unk2C;
            if (info->unk4 != 0)
            {
              pos2.x += info->unk30 * sinf(info->unk34);
              pos2.z += info->unk30 * cosf(info->unk34);
            }
            d = func_00272768(r, &pos1);
            if ((d < best) || (best == D_800C6E3C))
            {
              if (n)
              {
                sel = list[k];
                best = d;
                found = pos1;
              }
              else
              {
                sel = list[k];
                best = d;
                found = pos1;
              }
            }
            d = func_00272768(r, &pos2);
            if ((d < best) || (best == D_800C6E3C))
            {
              sel = list[k];
              best = d;
              found = pos2;
            }
          }
          k++;
        }
        while (k < nlist);
      }
      if (sel != ((void *) 0))
      {
        n->unk40 = sel;
        n->v44 = found;
      }
      else
      {
        n->unk40 = (void *) 0;
        *((u16 *) (r + 0xC)) &= 0xFDFF;
      }
    }
  }

}
