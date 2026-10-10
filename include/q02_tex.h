#ifndef Q02_TEX_H
#define Q02_TEX_H
#include "common.h"
#include "o03_types.h"

/* texture descriptor used by the overlay-A sprite / texture loader (D_800E32A4) */
typedef struct Q2Tex {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 w;
    /* 0x0A */ s16 h;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u32 img;
} Q2Tex;

#define Q_PUSH(a, b) { O3Dl *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
#define Q_MAX(a, b) ((a) > (b) ? (a) : (b))
#define Q_MIN(a, b) ((a) < (b) ? (a) : (b))
/* SDK-style gDPLoadBlock dxt helpers: TXL2WORDS(w) = MAX(1, w / div) */
#define Q_TXL(W, div) Q_MAX(1, (W) / (div))
#define Q_DXT(W, div) ((0x800 + Q_TXL(W, div) - 1) / Q_TXL(W, div))
#define Q_LOADBLK(W, div, lrs) (0x07000000 | ((Q_MIN(lrs, 2047) & 0xFFF) << 12) | (Q_DXT(W, div) & 0xFFF))
#endif
