#include "b24_types.h"

typedef struct AtlasCell {
    s32 w;
    s32 h;
} AtlasCell;

void func_002AACC0(u8 *, s32, s16, s32, s32);

void func_002AC0A0(u16 *hdr, s32 x0, s16 y) {
    s32 r, c;
    s32 x;
    s32 w, h;
    u8 *p;
    u16 rows;
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
            func_002AACC0(p + 8, x, y, w, h);
            x += w;
            p += (u32)(w * h) >> 1;
            p += 8;
        }
        y += h;
    }
}
