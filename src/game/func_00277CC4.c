#include "b17_types.h"

typedef struct M5Cell { f32 x0, z0, x1, z1; } M5Cell;
typedef struct M5Ent { s32 *a; M5Cell *cell; s32 pad8; } M5Ent;
typedef struct M5Grid {
    u8 pad0[0x1500];
    s32 n;
    u8 pad1504[4];
    M5Ent ent[1];
} M5Grid;

#define BOXHIT(q, rec) \
    ((q)->mx.x > (rec)->box.mn.x && (q)->mn.x < (rec)->box.mx.x && (q)->mx.z > (rec)->box.mn.z && \
     (q)->mn.z < (rec)->box.mx.z && (q)->mx.y > (rec)->box.mn.y && (q)->mn.y < (rec)->box.mx.y)

extern M5Grid D_8011FE88;
void *func_0028FD94();

s32 func_00277CC4(Box3 *q, WRec **out, s32 *cnt)
{
  s32 hashes[64];
  M5Ent *list[64];
  s32 spare[64];
  s32 n;
  s32 ncell;
  s32 i;
  s32 ret;
  s32 j;
  s32 k;
  s32 sum;
  s32 dup;
  s32 m;
  WTab *tab;
  WRec *rec;
  register M5Cell *c asm("$3");
  s32 *wp;
  s32 off;
  M5Ent *e;
  M5Grid *g;
  g = &D_8011FE88;
  n = 0;
  ncell = 0;
  i = 0;
  ret = 0;
  if (g->n > 0)
  {
    off = 0x1508;
    do
    {
      e = (M5Ent *) (((u8 *) g) + off);
      c = e->cell;
      if ((((c->x1 > q->mn.x) && (c->x0 < q->mx.x)) && (c->z1 > q->mn.z)) && (c->z0 < q->mx.z))
      {
        list[ncell] = e;
        ncell++;
      }
      off += 12;
      i++;
    }
    while (i < g->n);
  }
  if (ncell == 1)
  {
    tab = func_0028FD94(*list[0]->a, 2);
    j = tab->count;
    j--;
    rec = tab->r;
    for (; j != (-1); j--)
    {
      if ((((((q->mx.x > rec->box.mn.x) && (q->mn.x < rec->box.mx.x)) && (q->mx.z > rec->box.mn.z)) && (q->mn.z < rec->box.mx.z)) && (q->mx.y > rec->box.mn.y)) && (q->mn.y < rec->box.mx.y))
      {
        out[n] = rec;
        n++;
        if (rec->bBA != 0)
        {
          ret = 1;
        }
        if (n == 0x40)
        {
          if (1)
          {
            break;
          }
        }
      }
      rec++;
    }

    *cnt = n;
  }
  else
    if (ncell >= 2)
  {
    for (i = 0; i < ncell; i++)
    {
      tab = func_0028FD94(*list[i]->a, 2);
      j = tab->count;
      j--;
      rec = tab->r;
      for (; j != (-1); j--)
      {
        if ((((((q->mx.x > rec->box.mn.x) && (q->mn.x < rec->box.mx.x)) && (q->mx.z > rec->box.mn.z)) && (q->mn.z < rec->box.mx.z)) && (q->mx.y > rec->box.mn.y)) && (q->mn.y < rec->box.mx.y))
        {
          sum = 0;
          {
            register s32 kk asm("$3");
            s32 *wq;
            kk = 0;
            wq = (s32 *) (((u8 *) rec) + 0x60);
            do { sum += *wq; wq++; kk++; } while (kk < 16);
          }

          dup = 0;
          m = i != 0;
          if (m)
          {
            for (m = 0; m < n; m++)
            {
              if (hashes[m] == sum)
              {
                dup = 1;
                break;
              }
            }

          }
          if (dup == 0)
          {
            out[n] = rec;
            hashes[n] = sum;
            n++;
            if (rec->bBA != 0)
            {
              ret = 1;
            }
            if (n == 0x40)
            {
              *cnt = n;
              return ret;
            }
          }
        }
        rec++;
      }

    }

    do
    {
      *cnt = n;
    }
    while (0);
  }
  else
  {
    *cnt = n;
  }
  return ret;
}