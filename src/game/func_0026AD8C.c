#include "common.h"

extern s32 func_00285150();
extern u8 *func_0028FD94();
extern u8 *func_0028FDA8();
extern s32 **func_00254420();
extern void func_00253CB0();
extern void func_00285540();
extern void *memcpy();

void func_0026AD8C(s32 unused, s32 ***arg1, s32 arg2, s32 arg3)
{
  u32 new_var2;
  s32 sz0;
  s32 sz1;
  s32 sz2;
  s32 sz3;
  s32 sz4;
  u8 *p;
  u8 *q;
  int new_var;
  s32 **out;
  s32 *node;
  s32 *tbl;
  s32 *tbl2;
  u8 *d0;
  u8 *d0e;
  s32 cnt;
  s32 i;
  s32 nw;
  s32 size;
  s32 off;
  s32 off2;
  s32 ctr;
  s32 *hdr;
  s32 k5;
  s32 w;
  u8 *ssrc;
  if (func_00285150(arg1, 1) != 0)
  {
    nw = 6;
    if (arg2 == 0)
    {
      nw = 3;
      if (arg3 != 0)
      {
        nw = 4;
      }
    }
    node = *(*arg1);
    size = ((nw * 4) + 0xF) & (~7);
    func_0028FDA8(node, 0, &sz0);
    size += sz0;
    func_0028FDA8(node, 1, &sz1);
    size += sz1;
    tbl = (s32 *) func_0028FD94(node, 2);
    cnt = *tbl;
    i = 0;
    size += ((cnt * 4) + 0xF) & (~7);
    if (cnt > 0)
    {
      do
      {
        s32 v1;
        register s32 a asm("$4");
        q = func_0028FD94(tbl, i);
        size += 0x10;
        asm("" : "+r"(size));
        size += 0x20;
        p = func_0028FD94(q, 1);
        v1 = 0;
        a = *p;
        if (a != 0)
        {
          do
          {
            if (a & 0x80)
            {
              p += 2;
              v1 += 8;
              if ((*p) & 0x80)
              {
                p += 2;
              }
            }
            else
            {
              switch (a & 0x60)
              {
                case 0x40:

                case 0x20:
                  p += 2;
                  v1 += 8;
                  break;

                case 0x60:
                  p += 5;
                  v1 += 8;
                  break;

              }

            }
            a = *p;
          }
          while (a != 0);
        }
        size += (v1 + 0xF) & (~7);
        i++;
      }
      while (i < cnt);
    }
    if (arg2 != 0)
    {
      func_0028FDA8(node, 3, &sz2);
      size += sz2;
      func_0028FDA8(node, 4, &sz3);
      size += sz3;
      func_0028FDA8(node, 5, &sz4);
      size += sz4;
    }
    if (arg3 != 0)
    {
      size += 8;
    }
    out = func_00254420(0, arg1, size);
    if (out != 0)
    {
      off = ((nw * 4) + 0xF) & (~7);
      node = *(*arg1);
      hdr = *out;
      hdr[0] = nw;
      hdr[1] = off;
      ssrc = func_0028FDA8(node, 0, &sz0);
      ctr = 0;
      d0 = func_0028FD94(hdr, 0);
      memcpy(d0, ssrc, sz0);
      off += sz0;
      hdr[2] = off;
      {
        u8 *ssrc = func_0028FDA8(node, 1, &sz1);
        memcpy(func_0028FD94(hdr, 1), ssrc, sz1);
      }
      off += sz1;
      hdr[3] = off;
      tbl = (s32 *) func_0028FD94(node, 2);
      tbl2 = (s32 *) func_0028FD94(hdr, 2);
      cnt = *tbl;
      i = 0;
      *tbl2 = cnt;
      new_var = 0x01000000;
      off2 = ((cnt * 4) + 0xF) & (~7);
      tbl2[1] = off2;
      if (cnt > 0)
      {
        d0e = d0 + 8;
        do
        {
          s32 *rec;
          s32 *orec;
          u32 *dst;
          s32 rsz;
          s32 a;
          s32 k2;
          rec = (s32 *) func_0028FD94(tbl, i);
          orec = (s32 *) func_0028FD94(tbl2, i);
          rsz = (((*rec) * 4) + 0xF) & (~7);
          orec[0] = *rec;
          orec[1] = rsz;
          {
            u8 *ssrc = func_0028FD94(rec, 0);
            func_00285540(func_0028FD94(orec, 0), ssrc);
          }
          if (hdr)
          {
            rsz += 0x20;
          }
          else
          {
            rsz += 0x20;
          }
          orec[2] = rsz;
          p = func_0028FD94(rec, 1);
          dst = (u32 *) func_0028FD94(orec, 1);
          a = *p;
          if (a != 0)
          {
            do
            {
              if (a & 0x80)
              {
                s32 rA;
                s32 gA;
                s32 bA;
                register s32 hiA asm("$3");
                register s32 t1x asm("$7");
                register s32 loA asm("$2");
                hiA = *(p++);
                loA = *(p++);
                t1x = hiA << 8;
                w = t1x | loA;
                __asm__("" : : "r"(hiA));
                rA = (w >> 10) & 0x1F;
                gA = (w >> 5) & 0x1F;
                do
                {
                  bA = w & 0x1F;
                }
                while (0);
                if ((*p) & 0x80)
                {
                  register s32 lo2 asm("$4");
                  register s32 hi2 asm("$5");
                  register s32 t2x asm("$7");
                  u32 n2;
                  hi2 = *(p++);
                  lo2 = *(p++);
                  t2x = hi2 << 8;
                  w = t2x | lo2;
                  n2 = (u32) w >> 9;
                  dst += 2;
                  dst[-2] = (((rA << 17) | (gA << 9)) | (bA * 2)) | 0x06000000;
                  {
                    u32 bb;
                    bb = w & 0x1F;
                    dst[-1] = (((n2 & 0x3E) << 16) | ((w << 4) & 0x3E00)) | (bb * 2);
                  }
                }
                else
                {
                  dst += 2;
                  dst[-2] = (((rA << 17) | (gA << 9)) | (bA * 2)) | 0x05000000;
                  dst[-1] = 0;
                }
              }
              else
              {
                switch (a & 0x60)
                {
                  case 0x20:
                  {
                    register s32 t3x asm("$7");
                    register s32 nB asm("$2");
                                        register s32 hiB asm("$3");
                    register s32 loB asm("$2");
                    hiB = *(p++);
                    loB = *p;
                    t3x = hiB << 8;
                    w = t3x | loB;
                    k5 = (w >> 5) & 0x1F;
                    nB = w & 0x1F;
                    p++;
                    if (nB == 0)
                    {
                      nB = 0x20;
                    }
                    dst += 2;
                    dst[-2] = (nB << 12) | (((k5 + nB) * 2) | new_var);
                    dst[-1] = ((u32) ((d0e - (-(ctr * 0x10))) - d0)) + 0x02000000;
                    ctr += nB;
                    break;
                  }

                  case 0x40:
                  {
                    s32 kb;
                    p++;
                    kb = *p;
                    p++;
                    dst += 2;
                    dst[-1] = (kb << 6) + new_var;
                    dst[-2] = 0xDA380003;
                    break;
                  }

                  case 0x60:
                  {
                    register s32 q0 asm("$7");
                    register s32 q1 asm("$4");
                    register s32 q2 asm("$5");
                    register s32 q3 asm("$6");
                    k5 = a & 0x1F;
                    p++;
                    q0 = *p;
                    p++;
                    q1 = *p;
                    p++;
                    q2 = *p;
                    p++;
                    q3 = *p;
                    p++;
                    dst += 2;
                    dst[-2] = (k5 * 2) | 0x02140000;
                    q0 = q0 << 24;
                    dst[-1] = ((q0 | (q1 << 16)) | (q2 << 8)) | q3;
                    break;
                  }

                }

              }
              a = *p;
            }
            while (a != 0);
          }
          {
            u32 *e = dst;
            dst += 2;
            e[0] = 0xDF000000;
            e[1] = 0;
          }
          {
            register u32 len asm("$3");
            register u32 len2 asm("$2");
            len = (u32) (((u8 *) dst) - func_0028FD94(orec, 1));
            len2 = len + 7;
            rsz += len2 & (~7);
          }
          off2 += rsz;
          k2 = i + 1;
          orec[3] = rsz;
          {
            s32 *tp2 = tbl2 + k2;
            tp2[1] = off2;
          }
          i = k2;
        }
        while (i < cnt);
      }
      off += off2;
      hdr[4] = off;
      if (arg2 != 0)
      {
        {
          u8 *ssrc = func_0028FDA8(node, 3, &sz2);
          memcpy(func_0028FD94(hdr, 3), ssrc, sz2);
        }
        off += sz2;
        hdr[5] = off;
        {
          u8 *ssrc = func_0028FDA8(node, 4, &sz3);
          memcpy(func_0028FD94(hdr, 4), ssrc, sz3);
        }
        off += sz3;
        hdr[6] = off;
        {
          u8 *ssrc = func_0028FDA8(node, 5, &sz4);
          memcpy(func_0028FD94(hdr, 5), ssrc, sz4);
        }
        off += sz4;
        hdr[7] = off;
      }
      if (arg3 != 0)
      {
        s32 *e = (s32 *) func_0028FD94(hdr, 3);
        off += 8;
        e[0] = -1;
        e[1] = 0;
        hdr[5] = off;
      }
    }
    func_00253CB0(0, arg1, out);
  }
}
