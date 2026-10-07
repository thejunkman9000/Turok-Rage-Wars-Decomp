#include "b24_types.h"

extern DlCmd *D_80110634;

#define SHIFTL(v, s, w) (((u32)(v) & ((0x01 << (w)) - 1)) << (s))
#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void func_002ABA44(s32 x0, s32 y0, s32 x1, s32 y1, u8 r, u8 g, u8 b, u8 a) {
    GFX(0xE7000000, 0)
    GFX(0xFA00FFFF, SHIFTL(r, 24, 8) | SHIFTL(g, 16, 8) | SHIFTL(b, 8, 8) | SHIFTL(a, 0, 8))
    GFX(0xF6000000 | SHIFTL(MAX(x1, 0), 14, 10) | SHIFTL(MAX(y1, 0), 2, 10), SHIFTL(MAX(x0, 0), 14, 10) | SHIFTL(MAX(y0, 0), 2, 10))
}
