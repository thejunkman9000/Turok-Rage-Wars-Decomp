#include "b24_types.h"

extern DlCmd *D_80110634;

#define SHIFTL(v, s, w) (((u32)(v) & ((0x01 << (w)) - 1)) << (s))
#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define TXL2WORDS_4b(w) (1 > ((w) / 16) ? 1 : ((w) / 16))
#define CALC_DXT_4b(w) (((1 << 11) + TXL2WORDS_4b(w) - 1) / TXL2WORDS_4b(w))
#define TXL2WORDS_16b(w) (1 > ((w) * 2 / 8) ? 1 : ((w) * 2 / 8))
#define CALC_DXT_16b(w) (((1 << 11) + TXL2WORDS_16b(w) - 1) / TXL2WORDS_16b(w))
#define LRS_4b(w, h) ((((w) * (h) + 3) >> 2) - 1)
#define LRS_16b(w, h) (((w) * (h)) - 1)
#define MIN7FF(v) ((v) < 0x800 ? (v) : 0x7FF)

#define SCIS_TEXRECT(xl, yl, xh, yh, tile, s, t, dsdx, dtdy) \
    GFX(0xE4000000 | SHIFTL(MAX((xh), 0), 12, 12) | SHIFTL(MAX((yh), 0), 0, 12), \
        SHIFTL((tile), 24, 3) | SHIFTL(MAX((xl), 0), 12, 12) | SHIFTL(MAX((yl), 0), 0, 12)) \
    GFX(0xE1000000, \
        SHIFTL(((s) - (((xl) < 0) ? (((dsdx) < 0) ? (MAX((((xl) * (dsdx)) >> 7), 0)) : (MIN((((xl) * (dsdx)) >> 7), 0))) : 0)), 16, 16) | \
        SHIFTL(((t) - (((yl) < 0) ? (((dtdy) < 0) ? (MAX((((yl) * (dtdy)) >> 7), 0)) : (MIN((((yl) * (dtdy)) >> 7), 0))) : 0)), 0, 16)) \
    GFX(0xF1000000, SHIFTL((dsdx), 16, 16) | SHIFTL((dtdy), 0, 16))

void func_002AA724(u32 tex0, u32 tex1, f32 x, f32 y, s32 w, s32 h, f32 sx, f32 sy) {
    s32 dsdx, dtdy;
    s16 x0, y0, x1, y1;
    dsdx = 0x400;
    if (sx != 0.0f) {
        dsdx = dsdx / sx;
    }
    dtdy = 0x400;
    if (sy != 0.0f) {
        dtdy = dtdy / sy;
    }
    GFX(0xFD900000, tex1)
    GFX(0xF5900100, 0x07000000)
    GFX(0xE6000000, 0)
    x0 = x * 4.0f;
    x1 = (x + w * sx) * 4.0f;
    y0 = y * 4.0f;
    y1 = (y + h * sy) * 4.0f;
    GFX(0xF3000000, SHIFTL(MIN7FF(LRS_4b(w, h)), 12, 12) | 0x07000000 | SHIFTL(CALC_DXT_4b(w), 0, 12))
    GFX(0xE7000000, 0)
    GFX(0xF5800100 | SHIFTL((((w >> 1) + 7) >> 3), 9, 9), 0)
    GFX(0xF2000000, SHIFTL(((w - 1) << 2), 12, 12) | SHIFTL(((h - 1) << 2), 0, 12))
    GFX(0xFD100000, tex0)
    GFX(0xF5100000, 0x07000000)
    GFX(0xE6000000, 0)
    GFX(0xF3000000, SHIFTL(MIN7FF(LRS_16b(w, h)), 12, 12) | 0x07000000 | SHIFTL(CALC_DXT_16b(w), 0, 12))
    GFX(0xE7000000, 0)
    GFX(0xF5100000 | SHIFTL((((w * 2) + 7) >> 3), 9, 9), 0)
    GFX(0xF2000000, SHIFTL(((w - 1) << 2), 12, 12) | SHIFTL(((h - 1) << 2), 0, 12))
    GFX(0xF5800100 | SHIFTL((w / 16), 9, 9), 0x01000000)
    GFX(0xF2000000, SHIFTL(1, 24, 3) | SHIFTL(((w - 1) << 2), 12, 12) | SHIFTL(((h - 1) << 2), 0, 12))
    SCIS_TEXRECT(x0, y0, x1, y1, 0, 0, 0, (s16)dsdx, (s16)dtdy)
}
