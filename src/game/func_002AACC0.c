#include "b24_types.h"

extern DlCmd *D_80110634;

#define SHIFTL(v, s, w) (((u32)(v) & ((0x01 << (w)) - 1)) << (s))
#define TXL2WORDS_4b(w) (1 > ((w) / 16) ? 1 : ((w) / 16))
#define CALC_DXT_4b(w) (((1 << 11) + TXL2WORDS_4b(w) - 1) / TXL2WORDS_4b(w))
#define LRS(w, h) ((((w) * (h) + 3) >> 2) - 1)
#define LRSC(w, h) (LRS(w, h) < 0x800 ? LRS(w, h) : 0x7FF)

#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

void func_002AACC0(u8 *tex, s32 x, s32 y, s32 w, s32 h) {
    GFX(0xFD900000, (u32)tex)
    GFX(0xF5900100, 0x07000000)
    GFX(0xE6000000, 0)
    GFX(0xF3000000, SHIFTL(LRSC(w, h), 12, 12) | 0x07000000 | SHIFTL(CALC_DXT_4b(w), 0, 12))
    GFX(0xE7000000, 0)
    GFX(0xF5800100 | SHIFTL((((w >> 1) + 7) >> 3), 9, 9), 0)
    GFX(0xF2000000, SHIFTL(((w - 1) << 2), 12, 12) | SHIFTL(((h - 1) << 2), 0, 12))
    GFX(0xE4000000 | SHIFTL(((x + w) << 2), 12, 12) | SHIFTL(((y + h) << 2), 0, 12), SHIFTL((x << 2), 12, 12) | SHIFTL((y << 2), 0, 12))
    GFX(0xE1000000, 0)
    GFX(0xF1000000, 0x04000400)
}
