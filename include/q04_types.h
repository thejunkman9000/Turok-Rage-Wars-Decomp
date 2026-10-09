#ifndef Q04_TYPES_H
#define Q04_TYPES_H
#include "common.h"
/* round-3 overlay A shared types (q04): UI "panel" / "item" family (items are 0x28 bytes, templates 0x24 bytes) */
typedef struct { s32 x0, x1, y0, y1; } Q04Rect;
typedef struct { s32 w, h; } Q04Size;
/* 0x28-byte list item (Panel.items[]), also used as the by-value copy / info block of the layout helpers */
typedef struct Q04Item {
    s32 idx;            /* 0x00 */
    s16 w4;             /* 0x04 */
    u8 pad6[2];
    u32 flags;          /* 0x08 */
    u16 wC;             /* 0x0C */
    u16 wE;             /* 0x0E */
    u8 b10, b11, b12, b13;
    s32 f14;            /* 0x14 (pointer in some uses) */
    void *def;          /* 0x18 template/definition */
    s32 f1C;            /* 0x1C */
    void *p20;          /* 0x20 */
    void *owner;        /* 0x24 */
} Q04Item;
/* output block of func_0043F69C (item rect); also 0x28 bytes */
typedef struct Q04Info {
    s32 f0, f4, f8;
    f32 fC, f10;
    s32 x0, x1, y0, y1;   /* 0x14..0x20; total size 0x24 */
} Q04Info;
/* D_800E59E0 page block as seen by func_0043A0A4 (same block as O05L2 but with word fields at 0x134C/0x1354) */
#include "o05_types.h"
typedef struct Q04L2 {
    /* 0x0000 */ void *f0;
    /* 0x0004 */ void *f4;
    /* 0x0008 */ O05Row2 row[4];
    /* 0x1348 */ void *f1348;
    /* 0x134C */ s32 f134C;
    /* 0x1350 */ void *f1350;
    /* 0x1354 */ s32 f1354;
    /* 0x1358 */ s32 f1358;
    /* 0x135C */ s32 f135C;
    /* 0x1360 */ void *f1360;
    /* 0x1364 */ void *f1364;
    /* 0x1368 */ s32 f1368;
} Q04L2;
#endif
