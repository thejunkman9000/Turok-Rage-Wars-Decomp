#ifndef O02_TYPES_H
#define O02_TYPES_H
#include "common.h"

/* list/tree node used by the overlay-A UI widget code: +4 = next sibling, +0x12 = flags */
typedef struct O02Slider {
    u8 pad0[0x44];
    s32 min;       /* 0x44 */
    s32 max;       /* 0x48 */
    s32 step;      /* 0x4C */
    s32 val;       /* 0x50 */
    u8 pad54[0x6C - 0x54];
    s32 unk6C;
} O02Slider;

typedef struct { s32 w[4]; } O02Rect;
/* 40-byte render context passed by value (starts in $a1) */
typedef struct { s32 w[5]; u8 col; u8 padc[3]; s32 w2[4]; } O02Ctx;
/* entry of the draw-list table D_80153820 (0x18 bytes) */
typedef struct O02Item { s32 w0; f32 f4, f8, fC, f10; u16 f14; u16 f16; } O02Item;
typedef struct { s32 b[4]; O02Item *items; s32 count; } O02Ent;
#endif
