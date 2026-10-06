#include "common.h"

void func_002AB8DC(s32 a, s32 i, u16 **hdr, s32 *out);

void func_0028E36C(s32 unused, s32 handle, u8 *lut) {
    s32 i;
    for (i = 0; i < 0x100; i++) {
        u16 *hdr;
        s32 sp14;
        func_002AB8DC(handle, i, &hdr, &sp14);
        if (hdr != 0) {
            u16 *h = hdr;
            s32 *cell;
            s32 a;
            s32 b;
            s32 n;
            u8 *p;
            s32 w;
            s32 ht;
            u8 v;
            s32 hi;
            s32 lo;
            cell = (s32 *)(h + 4);
            a = h[1];
            while (--a != -1) {
                b = h[0];
                while (--b != -1) {
                    w = cell[0];
                    ht = cell[1];
                    p = (u8 *)cell + 8;
                    n = (u32)(w * ht) / 2;
                    while (--n != -1) {
                        v = *p;
                        hi = v >> 4;
                        lo = v & 0xF;
                        hi = lut[hi];
                        lo = lut[lo];
                        *p = (hi << 4) | lo;
                        p++;
                    }
                    cell = (s32 *)((u8 *)cell + (u32)(w * ht) / 2);
                    cell = (s32 *)((u8 *)cell + 8);
                }
            }
        }
    }
}
