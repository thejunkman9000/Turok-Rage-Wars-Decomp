#include "b23_types.h"

static __inline__ void cpyn(u8 *dst, u8 *src, s32 n) {
    u8 *d = dst;
    s32 k = n;
    u8 c;

    if (k == 0) {
        goto z;
    }
copy:
    c = *src;
    src++;
    *d = c;
    d++;
    if (c == 0) {
        goto fill;
    }
    k--;
    if (k != 0) {
        goto copy;
    }
fill:
    if (k == 0) {
        goto z;
    }
    k--;
    if (k == 0) {
        goto z;
    }
zero:
    *d = 0;
    k--;
    d++;
    if (k != 0) {
        goto zero;
    }
z:
    dst[n] = 0;
}

void func_002A0888(u8 *path, u8 *drive, u8 *dir, u8 *fname, u8 *ext)
{
  u8 *slash = 0;
  u8 *dot = 0;
  u8 *p;
  u8 *e;
  s32 n3;
  s32 n4;
  u8 c;
  p = path + 1;
  if ((*path) != 0)
  {
    do
    {
      c = *p;
      p++;
    }
    while (c != 0);
  }
  if ((((p - path) - 1) > 0) && (path[1] == 0x3A))
  {
    if (drive != 0)
    {
      cpyn(drive, path, 2);
    }
    path += 2;
  }
  else
    if (drive != 0)
  {
    *drive = 0;
  }
  e = path;
  if ((*path) != 0)
  {
    n4 = 0x2F;
    do
    {
      c = *e;
      if ((c == n4) || (c == 0x5C))
      {
        slash = e + 1;
      }
      else
        if (c == 0x2E)
      {
        dot = e;
      }
      e++;
    }
    while ((*e) != 0);
  }
  if (slash != 0)
  {
    if (dir != 0)
    {
      n3 = slash - path;
      if (n3 >= 0x100)
      {
        n3 = 0xFF;
      }
      cpyn(dir, path, n3);
    }
    path = slash;
  }
  else
    if (dir != 0)
  {
    *dir = 0;
  }
  if ((dot != 0) && (!(dot < path)))
  {
    if (fname != 0)
    {
      n4 = dot - path;
      if (n4 >= 0x100)
      {
        n4 = 0xFF;
      }
      cpyn(fname, path, n4);
    }
    if (ext != 0)
    {
      n3 = e - dot;
      if (n3 >= 0x100)
      {
        n3 = 0xFF;
      }
      cpyn(ext, dot, n3);
    }
  }
  else
  {
    if (fname != 0)
    {
      n4 = e - path;
      if (n4 >= 0x101)
      {
        n4 = 0x100;
      }
      cpyn(fname, path, n4);
    }
    if (ext != 0)
    {
      *ext = 0;
    }
  }
}
