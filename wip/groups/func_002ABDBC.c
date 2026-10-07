#include "b24_types.h"

typedef struct AtlasCell {
    s32 w;
    s32 h;
} AtlasCell;

void func_002AA354(u8 *, u8 *, s32, s16, s32, s32);

void func_002ABDBC(u16 *hdr, s32 x0, s16 y) {
    s32 r, c;
    s32 x;
    s32 w, h;
    u8 *p;
    s32 n;
    p = (u8 *)hdr + 8;
    h = 0;
    r = hdr[1];
    r--;
    for (; r != -1; r--) {
        x = (s16)x0;
        c = hdr[0];
        c--;
        for (; c != -1; c--) {
            h = ((AtlasCell *)p)->h;
            w = ((AtlasCell *)p)->w;
            n = w * h;
            func_002AA354(p + 8, p + (n * 2 + 8), x, y, w, h);
            x += w;
            p += (n * 2) + ((u32)n >> 1);
            p += 8;
        }
        y += h;
    }
}
