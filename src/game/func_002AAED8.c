#include "b24_types.h"

extern DlCmd *D_80110634;

#define SHIFTL(v, s, w) (((u32)(v) & ((0x01 << (w)) - 1)) << (s))
#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
#define TXL2WORDS_4b(w) (1 > ((w) / 16) ? 1 : ((w) / 16))
#define CALC_DXT_4b(w) (((1 << 11) + TXL2WORDS_4b(w) - 1) / TXL2WORDS_4b(w))
#define LRS_4b(w, h) ((((w) * (h) + 3) >> 2) - 1)
#define MIN7FF(v) ((v) < 0x800 ? (v) : 0x7FF)

void func_002AAED8(u32 tex, f32 x, f32 y, s32 w, s32 h, f32 sx, f32 sy) {
    s32 dsdx, dtdy;
    s32 x0, y0, x1, y1;
    dsdx = 0x400;
    if (sx != 0.0f) {
        dsdx = dsdx / sx;
    }
    dtdy = 0x400;
    if (sy != 0.0f) {
        dtdy = dtdy / sy;
    }
    x0 = x * 4.0f;
    x1 = (x + w * sx) * 4.0f;
    y0 = y * 4.0f;
    y1 = (y + h * sy) * 4.0f;
    GFX(0xFD900000, tex)
    GFX(0xF5900100, 0x07000000)
    GFX(0xE6000000, 0)
    GFX(0xF3000000, SHIFTL(MIN7FF(LRS_4b(w, h)), 12, 12) | 0x07000000 | SHIFTL(CALC_DXT_4b(w), 0, 12))
    GFX(0xE7000000, 0)
    GFX(0xF5800100 | SHIFTL((((w >> 1) + 7) >> 3), 9, 9), 0)
    GFX(0xF2000000, SHIFTL(((w - 1) << 2), 12, 12) | SHIFTL(((h - 1) << 2), 0, 12))
    GFX(0xE4000000 | SHIFTL(x1, 12, 12) | SHIFTL(y1, 0, 12), SHIFTL(x0, 12, 12) | SHIFTL(y0, 0, 12))
    GFX(0xE1000000, 0)
    GFX(0xF1000000, SHIFTL(dsdx, 16, 16) | SHIFTL(dtdy, 0, 16))
}
